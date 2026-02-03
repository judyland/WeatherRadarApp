#include <cmath>
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include <deque>
#include <limits>
#include <random>

#include "whrdrAntenna.h"
#include "WeatherRadarApp.h"

//#ifndef M_PI
//#	define M_PI            3.14159265358979323846
//#endif



using namespace whrdr;

using Clock = std::chrono::high_resolution_clock;
namespace sc = std::chrono;
using namespace std;

constexpr const size_t NumFids = 4;

array<Pixel, NumFids> theFidsToColorsTable{
     10,
     20,
     30,
     40
};
// Constructor

template<typename T>
class MinMax
{
public:
    MinMax() = default;
    ~MinMax() = default;

    bool valid() const {
        return (m_dMin < m_dMax);
    }

    T min() const {
        return m_dMin;
    }

    T max() const {
        return m_dMax;
    }

    bool inRange(T val) const {
        return ((val >= m_dMin) && (val <= m_dMax));
    }

    void addValue(T val)
    {
        if (val < m_dMin)
        {
            m_dMin = val;
        }
        if (val > m_dMax)
        {
            m_dMax = val;
        }
    }

private:
    double m_dMin = std::numeric_limits<T>::max();
    double m_dMax = std::numeric_limits<T>::min();
};


class MinMaxTable
{
public:
    MinMaxTable() = default;
    ~MinMaxTable() = default;

    void addValue(int fid, double elevation)
    {
        m_aTable[fid].addValue(elevation);
    }

    bool isInsideLayer(int fid, double elevation) const
    {
        return m_aTable[fid].inRange(elevation);
    }

private:
    using MinMaxd = MinMax<double>;
    std::array<MinMaxd, NumFids> m_aTable;
};


double getRandomNumber() 
{
    // Create a random device and generator
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Create a uniform distribution between 0 and 1
    static std::uniform_real_distribution<double> dis(0.0, 1.0);

    return dis(gen);
}

Antenna::Antenna() : Position() 
{
    // Initialize Antenna-specific members here if needed
 
#ifdef PIXEL_IS_RGB
    Pixel initPix{ 0, 0, 0 };
#else
    Pixel initPix{ 0 };
#endif
    for (auto infIt = m_aBeamsInfoArray.begin(); infIt != m_aBeamsInfoArray.end(); ++infIt)
    {
        auto pixBeginIt = infIt->aPixelsf.begin();
        auto pixEndIt = infIt->aPixelsf.end();
        std::fill(pixBeginIt, pixEndIt, initPix);
    }
    whrdr::getRadarData().pAntenna = this;
}

// Destructor

Antenna::~Antenna() 
{
    m_bFinish = true;
    if (m_cUpdateThread.joinable())  {
        m_cUpdateThread.join();
    }
    whrdr::getRadarData().pAntenna = nullptr;
}


using SegmentIsectFn = std::function<void(const qryIsectPointInfo&)>;
void getMultiIsect(qryIsectDB* pDB, const qryIsectPoint& rSrc, const qryIsectPoint& rDst,
    SegmentIsectFn func)
{
    double totalRange = rSrc.rangeFrom2d(rDst);
    double normX = (rDst.xLon - rSrc.xLon) / totalRange;
    double normY = (rDst.yLat - rSrc.yLat) / totalRange;
    double normZ = (rDst.zAlt - rSrc.zAlt) / totalRange;
    bool hasIsect = false;
    auto firstPoint = rSrc;
    do
    {
        auto isect = pDB->getLineIntersect(firstPoint, rDst);
        if (isect.hasData())
        {
            hasIsect = true;
            func(isect);
            firstPoint.xLon = isect.point().xLon + normX * 1.0;
            firstPoint.yLat = isect.point().yLat + normY * 1.0;
            firstPoint.zAlt = isect.point().zAlt + normZ * 1.0;
        }
        else
        {
            hasIsect = false;
        }

    } while (hasIsect);
}





void Antenna::calcBeam(uint32_t beamIndex)
{
    constexpr double dNumPixels = NumOfBeamSamples;

    if (!isValid())
    {
        return;
    }

    // lock for draw when updating beam in other thread
    scoped_lock<mutex> lk(m_cUpdateBeamMutex);

    auto& azBeamInfo = m_aBeamsInfoArray[beamIndex];
    auto& pixelsf = azBeamInfo.aPixelsf;
    azBeamInfo.reset();
    auto& azBeamGeom = m_aBeamsGeomArray[beamIndex];

    m_fCurAngle = static_cast<float>(beamIndex * getAzimuthRes()) + m_fStartAzimuth;
    float fromAz = 90.0f - m_fCurAngle;
    float toAz = static_cast<float>(fromAz + getAzimuthRes());

    auto& center = getPositionXYZ();
    float centerX = (float)center.x;
    float centerY = (float)center.y;
    float alt = (float)center.z;

    float fRange = (float)getScanRange();

    // update the beam parameters

   // azBeamGeom.cP0.x = 0; 
   // azBeamGeom.cP0.y = 0; 


    double dBeamEndX = CosDeg(fromAz) * fRange + centerX;
    double dBeamEndY = SinDeg(fromAz) * fRange + centerY;

    azBeamGeom.cP1.x = CosDeg(fromAz);
    azBeamGeom.cP1.y = SinDeg(fromAz); 

    azBeamGeom.cP2.x = CosDeg(toAz);
    azBeamGeom.cP2.y = SinDeg(toAz); 

    auto& pDB = whrdr::getRadarData().pDatabase;

    if (pDB)
    {
		bool inSegment = false;
		qryIsectPoint rSrc{ center.x,center.y, alt };
		qryIsectPoint rDst{ dBeamEndX, dBeamEndY, alt };

        const double totalRange = getScanRange();
        const double rangeStep = totalRange / pixelsf.size();

        double z = totalRange * tan(m_fElevation * M_PI / 180.0);
        double dz = z / static_cast<double>(pixelsf.size());


        auto vec = rDst - rSrc;
        auto norm2d = vec.getNormalize2d();
        auto step = norm2d * rangeStep;
        auto curPoint = rSrc;
        double curZ = center.z;

        for (size_t i = 0; i < pixelsf.size(); ++i, curPoint += step, curZ += dz)
        {
            MinMaxTable minMaxElevTable;
            bool hasData = false;
            pDB->getPointInfos(curPoint, [&](const qryIsectPointInfo& info) {
                if (info.hasData())
                {
                    const int fid = info.fid();
                    if ((fid >= 0) && (fid < theFidsToColorsTable.size()))
                    {
                        hasData = true;
                        minMaxElevTable.addValue(fid, info.point().zAlt);
                    }
                }
            });

			if (hasData)
			{
				int fid = NumFids;
				while (--fid >= 0)
				{
					if (minMaxElevTable.isInsideLayer(fid, curZ))
					{
 						pixelsf[i] = theFidsToColorsTable[fid];
 						break;
					}
				}
			}
        }


        // create the noise in the edges of cloud areas
        constexpr int MaxDistanceFromFlip = 30;
        constexpr int MidDsistanceFromFlip = MaxDistanceFromFlip / 2;
        int iDistanceFromFlip = MaxDistanceFromFlip;
        int lastPixelFid = pixelsf[0];
        int lastStoredFid = lastPixelFid;
        for (size_t i = 1; i < pixelsf.size(); ++i)
        {
            if (lastPixelFid != pixelsf[i])
            {
                iDistanceFromFlip = 0;
            }
            else
            {
                ++iDistanceFromFlip;
            }
            lastPixelFid = pixelsf[i];

            if (iDistanceFromFlip < MaxDistanceFromFlip)
            {
                double randNum = getRandomNumber() * 2;
                double fa = randNum * iDistanceFromFlip;
                if (fa < MidDsistanceFromFlip)
                {
                    pixelsf[i] = lastStoredFid; // theFidsToColorsTable[3];
                }
               //pixelsf[i] = theFidsToColorsTable[3];
            }
            else
            {
                lastStoredFid = pixelsf[i];
            }

            
        }

#if 0
        for (size_t i = 0; i < pixels.size(); ++i)
        {
            if (i > 0)
            {
                const double random = getRandomNumber();
                if (random > 0.2)
                {
                    pixels[i] = pixels[i - 1];
                    continue;
                }
            }
        }
#endif
    }

    //std::fill(pixelsf.begin(), pixelsf.end(), 10);
    azBeamInfo.cBitSet[BEAM_VALID] = true;
}

struct RangeSegment
{
    RangeSegment() {}

    void set(double from, double to, const Pixel& color) {
        dFrom = from; 
        dTo = to;
        cColor = color;
    }

    bool isInside(double r) const {
        return ((r >= dFrom) && (r <= dTo));
    }

    double  dFrom=0;
    double  dTo=0;
    Pixel   cColor{};
};

using RangeSegmentsArray = std::array<RangeSegment, 5>;

//RangeSegmentsArray getRangeSegments(double areaLenght)
//{
//    std::array<RangeSegment, 5> retval;
//
//    constexpr double f0 = 0.15;
//    constexpr double f1 = 0.15;
//    constexpr double f2 = 0.40;
//
//    double r0 = areaLenght * f0;
//    double r1 = r0 + areaLenght * f1;
//    double r2 = r1 + areaLenght * f2;
//    double r3 = r2 + areaLenght * f1;
//
//    retval[0].set(0, r0, { 0, 255, 0 });
//    retval[1].set(r0, r1, { 255, 255, 0 });
//    retval[2].set(r1, r2, { 255, 0, 0 });
//    retval[3].set(r2, r3, { 255, 255, 0 });
//    retval[4].set(r3, areaLenght, { 0, 255, 0 });
//
//    return retval;
//}

//
//void Antenna::updateBeamTexels(double fromRange, double toRange, double totalRange, BeamSamples& pixels)
//{
//	constexpr double dNumPixels = NumOfBeamSamples;
//
//	double rangeStep = totalRange / pixels.size();
//	auto rangeSegments = getRangeSegments(toRange - fromRange);
//	auto fromPix = static_cast<uint32_t>((fromRange / totalRange) * dNumPixels);
//	auto toPix = static_cast<uint32_t>((toRange / totalRange) * dNumPixels);
//
//	double segmentSize = toRange - fromRange;
//	double midRange = (toRange + fromRange) / 2.0;
//	double rangeFromStart = 0;
//	Pixel color{ 255, 0, 0 };
//	for (auto i = fromPix; (i <= toPix) && (i < pixels.size()); ++i)
//	{
//
//		auto segIt = rangeSegments.begin();
//		for (; segIt != rangeSegments.end(); ++segIt)
//		{
//			if (segIt->isInside(rangeFromStart))
//			{
//				pixels[i] = segIt->cColor;
//				break;
//			}
//		}
//		rangeFromStart += rangeStep;
//	}
//}
//
void Antenna::update()
{
    constexpr uint32_t MinimumSleepTimeMiliSec = 2;
   
    uint32_t azBeam = 0;
    double dtBetweenBeams = 60.0 / (m_dRPM * NumOfScanBeams);
    
    Clock::time_point roundStartTp;

    while (!m_bFinish)
    {
        static bool forward = true;
        int bc = azBeam;
        if (azBeam == 0 || azBeam == NumOfScanBeams - 1)
        {
            roundStartTp = Clock::now();
            if (azBeam == NumOfScanBeams - 1)
                forward = false;
            else
                forward = true;
        }

        if (!forward)
            bc = NumOfScanBeams - 1 - bc;
        sc::duration<double> roundElapsed = Clock::now() - roundStartTp;
        double expectedTime = bc * dtBetweenBeams;
        double timeDeviation = expectedTime - roundElapsed.count();
        
        uint32_t sleepTimeMillisec  = 0;
        if (timeDeviation > 0)
        {
            sleepTimeMillisec = static_cast<uint32_t>(timeDeviation * 1000.0);
        }

        // cout << azBeam << ", " << roundElapsed.count() << ", " << expectedTime << ", " << sleepTimeMillisec << endl;
        if (sleepTimeMillisec > MinimumSleepTimeMiliSec)
        {
            std::this_thread::sleep_for(sc::milliseconds(sleepTimeMillisec));
        }

        calcBeam(azBeam);

        static int delta = 1;
        azBeam += delta;
        if (azBeam == NumOfScanBeams - 1)
            delta = -1;
        else if (azBeam == 0)
            delta = 1;
        
    }
}

void Antenna::startUpdateThread()
{
     if (m_bUpdateThreadStarted) {
        // update thread already started
        return;
    }

    m_cUpdateThread = std::thread([&]() {
        this->update(); 
        });

    m_bUpdateThreadStarted = true;
}
