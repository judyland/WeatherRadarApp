#pragma once
#pragma pack(push,1)

#define num_of_clouds 10
//#include "WXROutMessage_minimal.h"
// 
// #include <cstdint>
// -----------------------------------------------------------------------------
// Basic header (simplified from project)
// -----------------------------------------------------------------------------
struct CBlockHeader
{
    // --- Data Members
    std::uint32_t	m_nBlockId;
    std::uint32_t	m_nMessageCounter;	// NOTE: It is returned by reference (changing type breaks compatibility)
    std::uint32_t	m_nTimeTag;
    std::uint32_t	m_nFrmCntTag;
    std::uint32_t	m_nSampleCounter;
    std::uint16_t	m_nErrorCounter;
    std::uint8_t	m_nErrorCode;
    std::uint8_t	m_nFlags;
};

// -----------------------------------------------------------------------------
// Weather radar enums
// -----------------------------------------------------------------------------
enum enmNH90WeatherRadar_MessageTypeType
{
    enmNH90WeatherRadar_MessageType__WeatherRadarOutMessageNh90 = 30503,
    enmNH90WeatherRadar_MessageType__WeatherRadarInMessageNh90 = 30504
};

// -----------------------------------------------------------------------------
// Dependent structs (simplified)
// -----------------------------------------------------------------------------
struct NH90WeatherRadar_Header
{
    enmNH90WeatherRadar_MessageTypeType m_eType;
    unsigned int m_nCounter;
    unsigned int m_nDataLength;
    double m_dTimeStamp;
    unsigned int m_nCrc;
};

struct NH90WeatherRadar_StateVector
{
    double m_dLatitude;	//
    double m_dLongitude;	//
    double m_dAltitudeMSL;	//
    double m_dAltitudeAGL;	//
    double m_dHeading;	//
    double m_dPitch;	//
    double m_dRoll;	//
    double m_dVelocityNorth;	//
    double m_dVelocityEast;	//
    double m_dVelocityDown;	//
    double m_dAlpha;	//
    double m_dSideSlip;	//
    double m_dTrueAirSpeed;	//
    double m_dCalibratedAirSpeed;	//

};

struct NH90WeatherRadar_WeatherState
{
    unsigned char   m_nIsolatedCloudIdentifier[num_of_clouds];
    float m_fIsolatedCloudRadius[num_of_clouds];
    float m_fIsolatedCloudLatitudeWGS84[num_of_clouds];
    float m_fIsolatedCloudLongitudeWGS84[num_of_clouds];
    float m_fIsolatedCloudVisibility[num_of_clouds];
    unsigned char   m_nIsolatedCloudMotionMode[num_of_clouds];
    float m_fIsolatedCloudTopAltitudeAMSL[num_of_clouds];
    float m_fIsolatedCloudBottomAltitudeAMSL[num_of_clouds];
    float m_fIsolatedCloudTurbulenceIntensityperc[num_of_clouds];
    float m_fIsolatedCloudPrecipitationIntensity[num_of_clouds];
    unsigned char   m_IsolatedCloudPrecipitationType[num_of_clouds];
};

struct NH90WeatherRadar_StatusIndicators
{
    char m_cAutotiltEnabled;	//
    unsigned char m_nSeaMapCr2Active;	//
    char m_cWxrImageValid;	//
    char m_cControlAcceptLeft;	//
    char m_cControlAcceptRight;	//
    char m_cSlave;	//
    char m_cTargetAlertActive;	//
    char m_cReactActive;	//
    char m_cTurbActive;	//
    char m_cTargetAlertDetected;	//
    char m_cClutterRedActive;	//
    char m_cRedScanActive;	//
    char m_cCommandError;	//
    char m_cStabilisationOn;	//
    char m_cCoolingFault;	//
    char m_cAirdataFault;	//
    char m_cAttitudeFault;	//
    char m_cControlFault;	//
    char m_cAntennaFault;	//
    char m_cRtFault;	//
    unsigned char m_cMode;	//
    float m_fTiltAngle;	//
    char m_nGain;	//
    float m_fRange;	//
    char m_cDataAcceptLeft;	//
    char m_cDataAcceptRight;	//
    float m_fScanAngle;	//
    char m_cEmittingStatus;	//
    unsigned char m_cBeaconCode;	//
    char m_cClearZone;	//
    unsigned char m_cBeaconType;	//
    char Pilot_TrueOrMagneticHeading;	//
    float m_fBeaconRange;	//
    unsigned char m_nBeaconRangeMultiplier;	//
    unsigned char m_nMissedApproachPoint;	//
    char m_cAutoBeaconGain;	//
    float m_fHeading;	//
    unsigned char m_nDisplayMode;	//
    char m_cPresetBeaconGain;	//
    float m_fBeaconBearing;	//
    char m_cBeaconDetected;	//
};

struct NH90WeatherRadar_WeatherRadar
{
    NH90WeatherRadar_StatusIndicators m_cPilot;	//
    NH90WeatherRadar_StatusIndicators m_cCopilot;	//
};

// -----------------------------------------------------------------------------
// WXROutMessage
// -----------------------------------------------------------------------------
struct blk_WXROutMessage
{
    //CBlockHeader m_cRawHeader;
    //unsigned char m_aRawData[604];

    NH90WeatherRadar_Header m_cHeader;
    NH90WeatherRadar_StateVector m_cFlightModelData;
    NH90WeatherRadar_WeatherState m_cWeatherState;
    NH90WeatherRadar_WeatherRadar m_cWeatherRadar;

    enum
    {
        m_cWeatherState_m_nIsolatedCloudIdentifier_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudRadius_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudLatitudeWGS84_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudLongitudeWGS84_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudVisibility_INSTANCES_NUM = 10,
        m_cWeatherState_m_nIsolatedCloudMotionMode_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudTopAltitudeAMSL_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudBottomAltitudeAMSL_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudTurbulenceIntensityperc_INSTANCES_NUM = 10,
        m_cWeatherState_m_fIsolatedCloudPrecipitationIntensity_INSTANCES_NUM = 10,
        m_cWeatherState_m_IsolatedCloudPrecipitationType_INSTANCES_NUM = 10
    };
};

#pragma pack(pop)
//struct whrdrData
//{
//	double dOwnLon; // Degrees
//	double dOwnLat; // Degrees
//	double dOwnAlt; // Meters
//
//};

