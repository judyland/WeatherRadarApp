


#include <GL/glew.h>
#include <iostream>
#include "chrono"
#include "whrdrComm.h"
#include "whrdrChannel.h"
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
	auto pObj = pDB->createObject(objId, pModel, cParams, iIntensity);
	if (pObj != nullptr)
	{
		whrdr::getRadarData().vActiveAreas.push_back(pObj); // pModel);
	}
}

Comm::Comm()
{
}

Comm::~Comm()
{
}

void Comm::readClouds()
{
	static int iCounter = 0;
	// check if a new cloud has been added

	if(iCounter%60 == 0)
	{
		bool bNewCloud = false;

		qryIsectDB::UniquePtr pDB = std::make_unique<qryIsectDB>();
		string qryName = "";

		auto pModel = pDB->loadModel("C:\\work\\Weather\\SimCore_30_3_25\\IG\\Data\\circle_area_shape_no_sw.flt"); // , cParams);

		// read clouds
		for (int i = 0;i < num_of_clouds;i++)
			m_cWheaterData->m_cWeatherState.m_nIsolatedCloudIdentifier[i];

		// convert position to ESF
		Location geoPos;
		Location esfPos;

		geoPos[LON] = radToDeg(m_cWheaterData->m_cWeatherState.m_fIsolatedCloudLongitudeWGS84[0]);
		geoPos[LAT] = radToDeg(m_cWheaterData->m_cWeatherState.m_fIsolatedCloudLatitudeWGS84[0]);
		geoPos[ALT] = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudBottomAltitudeAMSL[0];
		CoordTranslations::setESFCenter(geoPos[LAT], geoPos[LON]);
		CoordTranslations::positionLLAtoPositionESF(geoPos, esfPos);

		qryIsectTranslationParams cParams;

		cParams.transx = esfPos[X]; // 1500;
		cParams.transy = esfPos[Y]; // 1500;
		cParams.transz = geoPos[ALT];

		cParams.scalex = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudRadius[0];
		cParams.scaley = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudRadius[0];
		cParams.scalez = 3000;

		int iInt = m_cWheaterData->m_cWeatherState.m_fIsolatedCloudTurbulenceIntensityperc[0];
		//cParams.transx = 0; // 1500;
		//cParams.transy = 1000; // 1500;
		//cParams.transz = 2000;

		//cParams.scalex = 30000;
		//cParams.scaley = 30000;
		//cParams.scalez = 3000;
		//uint32_t objId = 1;
		createObject(pDB, 1, pModel, cParams, iInt);
		whrdr::getRadarData().pDatabase = std::move(pDB);

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
		auto ownLon = m_cWheaterData->m_cFlightModelData.m_dLongitude;
		auto ownLat = m_cWheaterData->m_cFlightModelData.m_dLatitude;
		auto ownAlt = m_cWheaterData->m_cFlightModelData.m_dAltitudeMSL;
		pChan->setPositionLLA({ radToDeg(ownLon), radToDeg(ownLat), ownAlt });
		
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

	//MMPReceiverMgr receiverMgr(configFile);
	//IMMPReceiver* pReceiver = receiverMgr.getReceiverPtr().get();
	m_pMMPMgr = std::make_unique<MMPReceiverMgr>(configFile);

	if (!m_pMMPMgr->getMMPDataElement("WHEATER_CHANNEL_DATA", m_cWheaterData))
	{
		cout << "failed to initialize mmp data element for moving map\n";
	}
}


