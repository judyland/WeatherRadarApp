//-----------------------------------------------------------------------------
// File Name:        WXROutMessage_minimal.h
// Description:      Minimal standalone definition of blk_WXROutMessage.
//-----------------------------------------------------------------------------

#ifndef WXROUTMESSAGE_MINIMAL_H
#define WXROUTMESSAGE_MINIMAL_H
#pragma pack(push, 1)
#include <cstdint>
// -----------------------------------------------------------------------------
// Basic header (simplified from project)
// -----------------------------------------------------------------------------
struct CBlockHeader
{
    uint32_t m_nId;
    uint32_t m_nSize;
    double   m_dTimeStamp;
};

// -----------------------------------------------------------------------------
// Weather radar enums
// -----------------------------------------------------------------------------
enum enmNH90WeatherRadar_MessageTypeType
{
    enmNH90WeatherRadar_MessageType__WeatherRadarOutMessageNh90 = 30503,
    enmNH90WeatherRadar_MessageType__WeatherRadarInMessageNh90  = 30504
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
    unsigned char   m_nIsolatedCloudIdentifier[10];
    float m_fIsolatedCloudRadius[10];
    float m_fIsolatedCloudLatitudeWGS84[10];
    float m_fIsolatedCloudLongitudeWGS84[10];
    float m_fIsolatedCloudVisibility[10];
    unsigned char   m_nIsolatedCloudMotionMode[10];
    float m_fIsolatedCloudTopAltitudeAMSL[10];
    float m_fIsolatedCloudBottomAltitudeAMSL[10];
    float m_fIsolatedCloudTurbulenceIntensityperc[10];
    float m_fIsolatedCloudPrecipitationIntensity[10];
    unsigned char   m_IsolatedCloudPrecipitationType[10];
};

struct NH90WeatherRadar_WeatherRadar
{
    bool m_bActive;
    float m_fRadarRange;
};

// -----------------------------------------------------------------------------
// WXROutMessage
// -----------------------------------------------------------------------------
struct blk_WXROutMessage
{
    CBlockHeader m_cRawHeader;
    unsigned char m_aRawData[604];

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
#endif // WXROUTMESSAGE_MINIMAL_H
