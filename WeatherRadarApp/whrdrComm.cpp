


#include <GL/glew.h>
#include <iostream>
#include "chrono"
#include "whrdrComm.h"
#include "whrdrChannel.h"
#include "whrdrPosition.h"
#include "magMath.h"
#include "WeatherRadarApp.h"

using namespace std;
using namespace whrdr;
using namespace magCoordinates;

#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

using Clock = chrono::high_resolution_clock;

void createObject(qryIsectDB::UniquePtr& pDB, uint32_t objId,
	qryIsectDB::ModelPtr& pModel,
	qryIsectTranslationParams& cParams,
	int iIntensity)
{
	pDB->removeObject(objId);
	auto pObj = pDB->createObject(objId, pModel, cParams, iIntensity);
	if (pObj != nullptr)
	{
		whrdr::getRadarData().vActiveAreas.push_back(pObj); // pModel);
	}
}
void clearClouds(qryIsectDB::UniquePtr& pDB)
{
	pDB->unloadModels();
}

Comm::Comm()
{
}

qryIsectDB::ModelPtr Comm::m_pModel = NULL;
qryIsectDB::UniquePtr Comm::m_pDB = NULL;

Comm::~Comm()
{
	cout << "m_pDB destruction" << endl;
}

void Comm::readClouds()
{
	static int iCounter = 0;
	// check if a new cloud has been added

	if(iCounter%60 == 0)
	{
		bool bNewCloud = false;
		string qryName = "";

		clearClouds(whrdr::getRadarData().pDatabase);
		//whrdr::getRadarData().vActiveAreas.clear();
		// read clouds
		
		// convert position to ESF
		Location geoPos;
		//Location esfPos;
	
		int iCloudId;
		for (int i = 0;i < num_of_clouds;i++)
		{
			Position cCloudPos;
			geoPos[LON] = radToDeg(m_cWheaterData->m_cWeatherState.m_fIsolatedCloudLongitudeWGS84[i]);
			geoPos[LAT] = radToDeg(m_cWheaterData->m_cWeatherState.m_fIsolatedCloudLatitudeWGS84[i]);
			geoPos[ALT] = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudBottomAltitudeAMSL[i];

			cCloudPos.setPositionLLA({ geoPos[LON], geoPos[LAT], geoPos[ALT] });
			iCloudId = m_cWheaterData->m_cWeatherState.m_nIsolatedCloudIdentifier[i];

			//CoordTranslations::positionLLAtoPositionESF(geoPos, esfPos);

			qryIsectTranslationParams cParams;

			//cParams.transx = esfPos[X]; // 1500;
			//cParams.transy = esfPos[Y]; // 1500;
			cParams.transx = cCloudPos.getPositionXYZ().x;
			cParams.transy = cCloudPos.getPositionXYZ().y;
			cParams.transz = geoPos[ALT];

			cParams.scalex = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudRadius[i];
			cParams.scaley = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudRadius[i];
			cParams.scalez = 3000;

			int iInt = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudTurbulenceIntensityperc[i];
			//cParams.transx = 0; // 1500;
			//cParams.transy = 1000; // 1500;
			//cParams.transz = 2000;

			//cParams.scalex = 30000;
			//cParams.scaley = 30000;
			//cParams.scalez = 3000;
			//uint32_t objId = 1;
			//m_pDB = std::make_unique<qryIsectDB>();
			createObject(whrdr::getRadarData().pDatabase, iCloudId, m_pModel, cParams, iInt);
		}

	}
	iCounter++;
	
}
void Comm::update(Channel* pChan)
{
	static double centerLon = 34.5;
	static double centerLat = 30.5;
	static Clock::time_point lastTP;
	static bool firstTime = true;
	//constexpr double velocity = 0; // KM / hour
	//constexpr double velocity = 0.5; // KM / hour
	constexpr double velocity = 250; // KM / hour

	Clock::time_point curTP = Clock::now();

	if (firstTime)
	{
		firstTime = false;
	}
	else 
	{
		chrono::duration<double> dt = curTP - lastTP;
		constexpr double meterSecVel = velocity / 3.6; // 250 km/hour
		double dtMeter = dt.count() * meterSecVel;
		double dtLat = dtMeter / (60.0 * 1852.0); 
		centerLat += dtLat;
	}
	lastTP = curTP;


	ostringstream ostr;
	ostr << "size of struct " << sizeof(m_cWheaterData);


	bool bHadData = m_cWheaterData.readData();
	char* sim = getenv("SIMULATE_INPUT");

	if (bHadData)
	{
		//cout << "Data recieved\n";
		auto ownLon = radToDeg(m_cWheaterData->m_cFlightModelData.m_dLongitude);
		auto ownLat = radToDeg(m_cWheaterData->m_cFlightModelData.m_dLatitude);
		auto ownAlt = m_cWheaterData->m_cFlightModelData.m_dAltitudeMSL;

		float range = m_cWheaterData->m_cWeatherRadar.m_cPilot.m_fRange;
		pChan->setScanRange(range);
		pChan->setStartAzimuth(m_cWheaterData->m_cFlightModelData.m_dHeading - 60);
		pChan->setHeading(m_cWheaterData->m_cFlightModelData.m_dHeading);
		pChan->setPositionLLA({ownLon, ownLat, ownAlt });
		//pChan->setStartAzimuth()
		CoordTranslations::setESFCenter(ownLat, ownLon);
		//Location geoPos;
		//Location esfPos;

		//geoPos[LON] = radToDeg(ownLon);
		//geoPos[LAT] = radToDeg(ownLat);
		//geoPos[ALT] = ownAlt;
		//CoordTranslations::setESFCenter(geoPos[LAT], geoPos[LON]);
		//CoordTranslations::positionLLAtoPositionESF(geoPos, esfPos);
		readClouds();
	}
	else if (sim && strcmp(sim, "true") == 0)
	{
		auto ownLon = centerLon;
		auto ownLat = centerLat;
		auto ownAlt = 3000.;
		pChan->setPositionLLA({ ownLon, ownLat, ownAlt });
	}
	else
	{
		double alt = 3000;
		pChan->setPositionLLA({ centerLon, centerLat, alt });
	}

}

void whrdr::Comm::initMMP()
{
	const char* configFile = "C:\\work\\Weather\\SimCore_30_3_25\\IG\\Data\\whrdrComm.xml";

	// general init
	m_pDB = std::make_unique<qryIsectDB>();
	m_pModel = m_pDB->loadModel("C:\\work\\Weather\\SimCore_30_3_25\\IG\\Data\\circle_area_shape_no_sw.flt"); // , cParams);
	whrdr::getRadarData().pDatabase = std::move(m_pDB);

	//MMPReceiverMgr receiverMgr(configFile);
	//IMMPReceiver* pReceiver = receiverMgr.getReceiverPtr().get();
	m_pMMPMgr = std::make_unique<MMPReceiverMgr>(configFile);

	if (!m_pMMPMgr->getMMPDataElement("WHEATER_CHANNEL_DATA", m_cWheaterData))
	{
		cout << "failed to initialize mmp data element for moving map\n";
	}
}


