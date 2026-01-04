#pragma once

#include <bitset>
#include <array>
#include <mutex>
#include <thread>
#include <algorithm>

#include "whrdrPosition.h"

namespace whrdr
{
    constexpr uint32_t NumOfScanBeams = 170;
    constexpr uint32_t NumOfBeamSamples = 170;

    enum BeamBits
    {
        BEAM_VALID,
        BEAM_DOWNLOADED,
        NOF_BITS
    };

    using BeamsBitSet = std::bitset<NOF_BITS>;
#ifdef PIXEL_IS_RGB
    using Pixel = std::array<uint8_t, 3>;
#else
    using Pixel = uint8_t;
#endif
    using BeamSamples = std::array<Pixel, NumOfBeamSamples>;
    using ULock = std::unique_lock<std::mutex>;


    inline void setPixel(Pixel& pix, uint8_t r, uint8_t g, uint8_t b) 
    {
#ifdef PIXEL_IS_RGB
        pix[0] = r; pix[1] = g;  pix[2] = b;
#else
        pix = r;
#endif
    }
    inline void resetPixel(Pixel& pix) 
    {
#ifdef PIXEL_IS_RGB
        pix[0] = pix[1] = pix[2] = 0;
#else
        pix = 0;
#endif
    }

    struct BeamInfo
    {
        BeamsBitSet cBitSet;
        BeamSamples aPixelsf{};
        
        void reset()
        {
            cBitSet.reset();
            std::for_each(aPixelsf.begin(), aPixelsf.end(), [&](Pixel& pix) {
                resetPixel(pix);
                });
        }
    };

    struct BeamGeom
    {
       // PosXYf       cP0; // origin
        PosXYf       cP1; // Next counter clockwise
        PosXYf       cP2; // Next counter clockwise

    };

    using BeamsInfoArray = std::array<BeamInfo, NumOfScanBeams>;
    using BeamsGeomArray = std::array<BeamGeom, NumOfScanBeams>;

    class Antenna : public Position 
    {

    public:
        // Constructor
        Antenna();

        // Destructor
        virtual ~Antenna();

        // Antenna-specific methods here
        
        BeamsInfoArray& getBeamsInfoArray() {
            return m_aBeamsInfoArray;
        }

        BeamsGeomArray& getBeamsGeomArray() {
            return m_aBeamsGeomArray;
        }

        const BeamsGeomArray& getBeamsGeomArray() const {
            return m_aBeamsGeomArray;
        }

        constexpr double getAzimuthRes() const { 
            return m_fSweep / static_cast<double>(NumOfScanBeams); 
        }

        void calcBeam(uint32_t beamIndex);
        void updateBeamTexels(double fromRange, double toRange, double totalRange, BeamSamples& pixels);

        // meters
        double getScanRange() const {
            return m_dScanRange;
        }

        // meters
        void setScanRange(double val) {
            m_dScanRange = val;
        }

        void update();
        void startUpdateThread();

        ULock getUpdateMutexLock()
        {
            return ULock(m_cUpdateBeamMutex);
        }

        float getCurAngle() const {
            return m_fCurAngle;
        }

        float getElevation() const {
            return m_fElevation;
        }

        void setElevation(float elev) {
            m_fElevation = elev;
        }

        void setStartAzimuth(float az) {
            m_fStartAzimuth = az;
        }

        void setSweep(float sw) {
            m_fSweep = sw;
        }

        
    private:
        // Additional Antenna-specific members here
        BeamsInfoArray  m_aBeamsInfoArray{};
        BeamsGeomArray  m_aBeamsGeomArray{};
        double      m_dScanRange = 5E+4; // meters
        double      m_dRPM = 5; // 1.171875;
        float       m_fCurAngle = 0;
        float       m_fElevation = 0;
        bool        m_bFinish = false;
        bool        m_bUpdateThreadStarted = false;
        std::mutex  m_cUpdateBeamMutex;
        std::thread m_cUpdateThread;
        float       m_fStartAzimuth;
        float       m_fSweep;
    
    };

}
