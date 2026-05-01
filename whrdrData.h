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
enum enmWXR_MessageTypeType
{
    enmNH90WeatherRadar_MessageType__WeatherRadarOutMessageNh90 = 30503,
    enmNH90WeatherRadar_MessageType__WeatherRadarInMessageNh90 = 30504
};

struct WXR_Header
{
    enmWXR_MessageTypeType m_eType;	//
    unsigned int m_nCounter;	//
    unsigned int m_nDataLength;	//
    double m_dTimeStamp;	//
    unsigned int m_nCrc;	//
};
// -----------------------------------------------------------------------------
// Dependent structs (simplified)
// -----------------------------------------------------------------------------
//struct NH90WeatherRadar_Header
//{
//    enmNH90WeatherRadar_MessageTypeType m_eType;
//    unsigned int m_nCounter;
//    unsigned int m_nDataLength;
//    double m_dTimeStamp;
//    unsigned int m_nCrc;
//};

//struct NH90WeatherRadar_StateVector
//{
//    double m_dLatitude;	//
//    double m_dLongitude;	//
//    double m_dAltitudeMSL;	//
//    double m_dAltitudeAGL;	//
//    double m_dHeading;	//
//    double m_dPitch;	//
//    double m_dRoll;	//
//    double m_dVelocityNorth;	//
//    double m_dVelocityEast;	//
//    double m_dVelocityDown;	//
//    double m_dAlpha;	//
//    double m_dSideSlip;	//
//    double m_dTrueAirSpeed;	//
//    double m_dCalibratedAirSpeed;	//
//
//};

struct WXR_StateVector
{
    double m_dLatitudeRad;	//
    double m_dLongitudeRad;	//
    double m_dAltitudeMSLMeter;	//
    double m_dAltitudeAGLMeter;	//
    double m_dHeadingRad;	//
    double m_dPitchRad;	//
    double m_dRollRad;	//
    double m_dVelocityNorthMSec;	//
    double m_dVelocityEastMSec;	//
    double m_dVelocityDownMSec;	//
    double m_dAlphaRad;	//
    double m_dSideSlipRad;	//
    double m_dTrueAirSpeedMSec;	//
    double m_dCalibratedAirSpeedMSec;	//
};

struct WXR_WeatherState
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
struct WXR_RadarData
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

enum enmWXR_ConfigurationReferenceType
{
    enmWXR_ConfigurationReference__NoWXR = 0,
    enmWXR_ConfigurationReference__WXRFSCT = 1,
    enmWXR_ConfigurationReference__WXRNROS = 2,
    enmWXR_ConfigurationReference__WXRNSCT = 3,
    enmWXR_ConfigurationReference__WXRTWXR = 4
};
struct WXR_WXRS
{
    char m_nSwitchingCommand;	//
    enmWXR_ConfigurationReferenceType m_eImageConfiguration;	//
    char m_nFreezingCommand;	//
    char m_nBlackImage;	//
};

struct WXR_WeatherRadar
{
    WXR_RadarData m_cData;	//
    WXR_WXRS m_cWxrs;	//
};

struct blk_WXROutCopilotMessage // 
{
    WXR_Header m_cHeader;
    WXR_StateVector m_cFlightModelData;
    WXR_WeatherState m_cWeatherState;
    WXR_WeatherRadar m_cWeatherRadar;

    // Elements Arrays Size
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


    // Reflection functions
    static inline const char* GetLruTypeName()
    {
        return "WXR";
    }
    static inline const char* GetBlockTypeName()
    {
        return "WXROutCopilotMessage";
    }
};

struct blk_WXROutPilotMessage // 
{

    //CBlockHeader m_cRawHeader;
    //unsigned char m_aRawData[552];

    WXR_Header m_cHeader;
    WXR_StateVector m_cFlightModelData;
    WXR_WeatherState m_cWeatherState;
    WXR_WeatherRadar m_cWeatherRadar;

    // Elements Arrays Size
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


//
//struct NH90WeatherRadar_WeatherState
//{
//    unsigned char   m_nIsolatedCloudIdentifier[num_of_clouds];
//    float m_fIsolatedCloudRadius[num_of_clouds];
//    float m_fIsolatedCloudLatitudeWGS84[num_of_clouds];
//    float m_fIsolatedCloudLongitudeWGS84[num_of_clouds];
//    float m_fIsolatedCloudVisibility[num_of_clouds];
//    unsigned char   m_nIsolatedCloudMotionMode[num_of_clouds];
//    float m_fIsolatedCloudTopAltitudeAMSL[num_of_clouds];
//    float m_fIsolatedCloudBottomAltitudeAMSL[num_of_clouds];
//    float m_fIsolatedCloudTurbulenceIntensityperc[num_of_clouds];
//    float m_fIsolatedCloudPrecipitationIntensity[num_of_clouds];
//    unsigned char   m_IsolatedCloudPrecipitationType[num_of_clouds];
//};

//struct NH90WeatherRadar_StatusIndicators
//{
//    char m_cAutotiltEnabled;	//
//    unsigned char m_nSeaMapCr2Active;	//
//    char m_cWxrImageValid;	//
//    char m_cControlAcceptLeft;	//
//    char m_cControlAcceptRight;	//
//    char m_cSlave;	//
//    char m_cTargetAlertActive;	//
//    char m_cReactActive;	//
//    char m_cTurbActive;	//
//    char m_cTargetAlertDetected;	//
//    char m_cClutterRedActive;	//
//    char m_cRedScanActive;	//
//    char m_cCommandError;	//
//    char m_cStabilisationOn;	//
//    char m_cCoolingFault;	//
//    char m_cAirdataFault;	//
//    char m_cAttitudeFault;	//
//    char m_cControlFault;	//
//    char m_cAntennaFault;	//
//    char m_cRtFault;	//
//    unsigned char m_cMode;	//
//    float m_fTiltAngle;	//
//    char m_nGain;	//
//    float m_fRange;	//
//    char m_cDataAcceptLeft;	//
//    char m_cDataAcceptRight;	//
//    float m_fScanAngle;	//
//    char m_cEmittingStatus;	//
//    unsigned char m_cBeaconCode;	//
//    char m_cClearZone;	//
//    unsigned char m_cBeaconType;	//
//    char Pilot_TrueOrMagneticHeading;	//
//    float m_fBeaconRange;	//
//    unsigned char m_nBeaconRangeMultiplier;	//
//    unsigned char m_nMissedApproachPoint;	//
//    char m_cAutoBeaconGain;	//
//    float m_fHeading;	//
//    unsigned char m_nDisplayMode;	//
//    char m_cPresetBeaconGain;	//
//    float m_fBeaconBearing;	//
//    char m_cBeaconDetected;	//
//};




//
//// -----------------------------------------------------------------------------
//// WXROutMessage
//// -----------------------------------------------------------------------------
//struct blk_WXROutMessage
//{
//    //CBlockHeader m_cRawHeader;
//    //unsigned char m_aRawData[604];
//
//    NH90WeatherRadar_Header m_cHeader;
//    NH90WeatherRadar_StateVector m_cFlightModelData;
//    NH90WeatherRadar_WeatherState m_cWeatherState;
//    NH90WeatherRadar_WeatherRadar m_cWeatherRadar;
//
//    enum
//    {
//        m_cWeatherState_m_nIsolatedCloudIdentifier_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudRadius_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudLatitudeWGS84_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudLongitudeWGS84_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudVisibility_INSTANCES_NUM = 10,
//        m_cWeatherState_m_nIsolatedCloudMotionMode_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudTopAltitudeAMSL_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudBottomAltitudeAMSL_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudTurbulenceIntensityperc_INSTANCES_NUM = 10,
//        m_cWeatherState_m_fIsolatedCloudPrecipitationIntensity_INSTANCES_NUM = 10,
//        m_cWeatherState_m_IsolatedCloudPrecipitationType_INSTANCES_NUM = 10
//    };
//};

#pragma pack(pop)
//struct whrdrData
//{
//	double dOwnLon; // Degrees
//	double dOwnLat; // Degrees
//	double dOwnAlt; // Meters
//
//};

