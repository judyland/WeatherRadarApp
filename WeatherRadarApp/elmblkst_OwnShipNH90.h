//-----------------------------------------------------------------------------
// File Name:		Export/elmblkst.h
// Project Name:	OwnShipNH90
//-----------------------------------------------------------------------------
#ifndef ELM_BLK_ST__OWNSHIPNH90__H
#define ELM_BLK_ST__OWNSHIPNH90__H

#if defined(_MSC_VER) && !defined(__KLOCWORK__)
#	pragma once
#endif

#ifdef _MSC_VER
	#ifndef DBDLL_EXTDBSIM_OWNSHIPNH90
		#ifdef _DBSIMDBSIM_OWNSHIPNH90
			#define DBDLL_EXTDBSIM_OWNSHIPNH90 __declspec(dllexport)
		#else
			#ifdef _DBSIMEXT
				#define DBDLL_EXTDBSIM_OWNSHIPNH90
			#else
				#define DBDLL_EXTDBSIM_OWNSHIPNH90 __declspec(dllimport)
			#endif
		#endif
	#endif
#else
	#define DBDLL_EXTDBSIM_OWNSHIPNH90
#endif

#include "elmenum_OwnShipNH90.h"
#include "elminfo_OwnShipNH90.h"
#include "SafeArrayT.h"
#include "BlockHeader.h"
//#include "DbsimApi/DbsimCompatibilityValidator_Interface.h"

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(push, 1)
#endif

// ============================ DEFINES ========================================
#ifndef DBSIM_GET_LRU
	#define DBSIM_GET_LRU(LRU_NAME) (*g_p##LRU_NAME)
	#define DBSIM_GET_LRU_ARR(X) (g_p##X)
#endif

// Examples:
//	DBSIM_GET_LRU(IOS_LRU).Something
//	DBSIM_GET_LRU(IOS_LRU_ARR[5]).Something
//	DBSIM_GET_LRU_ARR(IOS_LRU_ARR)

// ============================ TYPES ==========================================
typedef int BOOL;
// ============================ LRUs ===========================================

// List of LRUs

//-----------------------------------------------------------------------------
// LRU Name:		Nh90Cargo
// Description:		
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_Nh90Cargo
{
	enum
	{
		NAME_HASH = 403644630,
		COUNTERS_MASK = 4865
	};

	

	// Blocks structures
	struct blk_CargoMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[73];

		Nh90Cargo_Header m_cHeader;
		Nh90Cargo_Payload m_cPayload;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "Nh90Cargo";
		}
		static inline const char *GetBlockTypeName()
		{
			return "CargoMessage";
		}
	};

	// Data members
	blk_CargoMessage CargoMessage;
};

//-----------------------------------------------------------------------------
// LRU Name:		Nh90CircuitBrakers
// Description:		NH90 CircuitBrakers
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_Nh90CircuitBrakers
{
	enum
	{
		NAME_HASH = -1680063522,
		COUNTERS_MASK = 69377
	};

	

	// Blocks structures
	struct blk_CircuitBrakerOutMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[290];

		Nh90CircuitBrakers_H2HMessageHeader m_cHeader;
		Nh90CircuitBrakers_ControlAndDisplays m_cControlAndDisplays;
		Nh90CircuitBrakers_Communication m_cCommunication;
		Nh90CircuitBrakers_Navigation m_cNavigation;
		Nh90CircuitBrakers_ElectricalPowerSystem m_cElectricalPowerSystem;
		Nh90CircuitBrakers_EngineSystem m_cEngineSystem;
		Nh90CircuitBrakers_EnvironmentalControlSystem m_cEnvironmentalControlSystem;
		Nh90CircuitBrakers_FlightControlComputer m_cFlightControlComputer;
		Nh90CircuitBrakers_FuelSystem m_cFuelSystem;
		Nh90CircuitBrakers_HydraulicPowerSystem m_cHydraulicPowerSystem;
		Nh90CircuitBrakers_IceAndRainProtection m_cIceAndRainProtection;
		Nh90CircuitBrakers_LandinGearSystem m_cLandingGearSystem;
		Nh90CircuitBrakers_LightingSystem m_cLightingSystem;
		Nh90CircuitBrakers_TransmissionAndRotorSystem m_cTransmissionAndRotorSystem;
		Nh90CircuitBrakers_GITA m_cGita;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "Nh90CircuitBrakers";
		}
		static inline const char *GetBlockTypeName()
		{
			return "CircuitBrakerOutMessage";
		}
	};

	// Data members
	blk_CircuitBrakerOutMessage CircuitBrakerOutMessage;
};

//-----------------------------------------------------------------------------
// LRU Name:		Nh90Configuration
// Description:		
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_Nh90Configuration
{
	enum
	{
		NAME_HASH = 1041364285,
		COUNTERS_MASK = 21505
	};

	

	// Blocks structures
	struct blk_ConfigurationMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[276];

		Nh90Configuration_Header m_cHeader;
		Nh90Configuration_Payload m_cPayload;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "Nh90Configuration";
		}
		static inline const char *GetBlockTypeName()
		{
			return "ConfigurationMessage";
		}
	};

	// Data members
	blk_ConfigurationMessage ConfigurationMessage;
};

//-----------------------------------------------------------------------------
// LRU Name:		Nh90MalfunctionDamage
// Description:		NH90 Malfunctions Damage
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_Nh90MalfunctionDamage
{
	enum
	{
		NAME_HASH = 65897121,
		COUNTERS_MASK = 106241
	};

	

	// Blocks structures
	struct blk_MalfunctionDamageMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[461];

		Nh90MalfunctionDamage_H2HMessageHeader m_cHeader;
		Nh90MalfunctionDamage_FireMalfunctions m_cFire;
		Nh90MalfunctionDamage_EngineMalfunctions m_cEngine;
		Nh90MalfunctionDamage_TransmissionMalfunctions m_cTransmission;
		Nh90MalfunctionDamage_HydraulicMalfunctions m_cHydraulic;
		Nh90MalfunctionDamage_LandingGearMalfunctions m_cLandingGear;
		Nh90MalfunctionDamage_ElectricMalfunctions m_cElectric;
		Nh90MalfunctionDamage_FuelMalfunctions m_cFuel;
		Nh90MalfunctionDamage_AutoPilotMalfunction m_cAutoPilot;
		Nh90MalfunctionDamage_AvionicMalfunctions m_cAvionic;
		Nh90MalfunctionDamage_LightsMalfunctions m_cLights;
		Nh90MalfunctionDamage_EcsMalfunctions m_cEcs;
		Nh90MalfunctionDamage_NavigationMalfunctions m_cNavigation;
		Nh90MalfunctionDamage_CommunicationMalfunctions m_cCommunication;
		Nh90MalfunctionDamage_IrpsMalfunctions m_cIrps;
		Nh90MalfunctionDamage_RoleEquipmentMalfunctions m_cRoleEquipment;
		Nh90MalfunctionDamage_MissionMalfunctions m_cMission;
		Nh90MalfunctionDamage_EwsMalfunctions m_cEws;
		Nh90MalfunctionDamage_RctMalfunctions m_cRct;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "Nh90MalfunctionDamage";
		}
		static inline const char *GetBlockTypeName()
		{
			return "MalfunctionDamageMessage";
		}
	};

	// Data members
	blk_MalfunctionDamageMessage MalfunctionDamageMessage;
};

//-----------------------------------------------------------------------------
// LRU Name:		Nh90Malfunctions
// Description:		NH90 Malfunctions
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_Nh90Malfunctions
{
	enum
	{
		NAME_HASH = 1900335988,
		COUNTERS_MASK = 106241
	};

	

	// Blocks structures
	struct blk_MalfunctionsRequestFromSE // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[461];

		Nh90Malfunctions_H2HMessageHeader m_cHeader;
		Nh90Malfunctions_FireMalfunctions m_cFire;
		Nh90Malfunctions_EngineMalfunctions m_cEngine;
		Nh90Malfunctions_TransmissionMalfunctions m_cTransmission;
		Nh90Malfunctions_HydraulicMalfunctions m_cHydraulic;
		Nh90Malfunctions_LandingGearMalfunctions m_cLandingGear;
		Nh90Malfunctions_ElectricMalfunctions m_cElectric;
		Nh90Malfunctions_FuelMalfunctions m_cFuel;
		Nh90Malfunctions_AutoPilotMalfunction m_cAutoPilot;
		Nh90Malfunctions_AvionicMalfunctions m_cAvionic;
		Nh90Malfunctions_LightsMalfunctions m_cLights;
		Nh90Malfunctions_EcsMalfunctions m_cEcs;
		Nh90Malfunctions_NavigationMalfunctions m_cNavigation;
		Nh90Malfunctions_CommunicationMalfunctions m_cCommunication;
		Nh90Malfunctions_IrpsMalfunctions m_cIrps;
		Nh90Malfunctions_RoleEquipmentMalfunctions m_cRoleEquipment;
		Nh90Malfunctions_MissionMalfunctions m_cMission;
		Nh90Malfunctions_EwsMalfunctions m_cEws;
		Nh90Malfunctions_RctMalfunctions m_cRct;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "Nh90Malfunctions";
		}
		static inline const char *GetBlockTypeName()
		{
			return "MalfunctionsRequestFromSE";
		}
	};

	// Data members
	blk_MalfunctionsRequestFromSE MalfunctionsRequestFromSE;
};

//-----------------------------------------------------------------------------
// LRU Name:		NH90ModelOutputs
// Description:		
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_NH90ModelOutputs
{
	enum
	{
		NAME_HASH = 1502551656,
		COUNTERS_MASK = 5889
	};

	

	// Blocks structures
	struct blk_ModelOutputs // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[146];

		NH90ModelOutputs_Header m_cHeader;
		NH90ModelOutputs_Payload m_cPayload;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "NH90ModelOutputs";
		}
		static inline const char *GetBlockTypeName()
		{
			return "ModelOutputs";
		}
	};

	// Data members
	blk_ModelOutputs ModelOutputs;
};

//-----------------------------------------------------------------------------
// LRU Name:		NH90WeatherRadar
// Description:		NH90WeatherRadar
//-----------------------------------------------------------------------------

struct DBDLL_EXTDBSIM_OWNSHIPNH90 LRU_NH90WeatherRadar
{
	enum
	{
		NAME_HASH = -1094408812,
		COUNTERS_MASK = 153092
	};

	

	// Blocks structures
	struct blk_WeatherRadarInMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[604];

		NH90WeatherRadar_Header m_cHeader;
		NH90WeatherRadar_PayloadIn m_cPayload;

		// Elements Arrays Size
		enum
		{
			m_cPayload_m_cABSMTC1AR250_m_nBuffer_INSTANCES_NUM = 64,
			m_cPayload_m_cABSMTC1AR251_m_nBuffer_INSTANCES_NUM = 64,
			m_cPayload_m_cVBUWXRS_m_cSwitchingCommand_INSTANCES_NUM = 5,
			m_cPayload_m_cVBUWXRS_m_cConfigurationReference_INSTANCES_NUM = 5,
			m_cPayload_m_cVBUWXRS_m_cFreezingCommand_INSTANCES_NUM = 5,
			m_cPayload_m_cVBUWXRS_m_cBlackImage_INSTANCES_NUM = 5
		};


		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "NH90WeatherRadar";
		}
		static inline const char *GetBlockTypeName()
		{
			return "WeatherRadarInMessage";
		}
	};

	struct blk_WeatherRadarOutMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[662];

		NH90WeatherRadar_Header m_cHeader;
		NH90WeatherRadar_PayloadOut m_cPayload;

		// Elements Arrays Size
		enum
		{
			m_cPayload_m_cABSWXRAR252_m_nBuffer_INSTANCES_NUM = 64,
			m_cPayload_m_cABSWXRAR253_m_nBuffer_INSTANCES_NUM = 64
		};


		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "NH90WeatherRadar";
		}
		static inline const char *GetBlockTypeName()
		{
			return "WeatherRadarOutMessage";
		}
	};

	struct blk_WXRInMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[2];

		NH90WeatherRadar_Status m_cStatus;

		// Elements Arrays Size
		

		// Reflection functions
		static inline const char *GetLruTypeName()
		{
			return "NH90WeatherRadar";
		}
		static inline const char *GetBlockTypeName()
		{
			return "WXRInMessage";
		}
	};

	struct blk_WXROutMessage // 
	{
		
		CBlockHeader m_cRawHeader;
		unsigned char m_aRawData[604];

		NH90WeatherRadar_Header m_cHeader;
		NH90WeatherRaеьdar_StateVector m_cFlightModelData;
		NH90WeatherRadar_WeatherState m_cWeatherState;
		NH90WeatherRadar_WeatherRadar m_cWeatherRadar;

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
		static inline const char *GetLruTypeName()
		{
			return "NH90WeatherRadar";
		}
		static inline const char *GetBlockTypeName()
		{
			return "WXROutMessage";
		}
	};

	// Data members
	blk_WeatherRadarInMessage WeatherRadarInMessage;
	blk_WeatherRadarOutMessage WeatherRadarOutMessage;
	blk_WXRInMessage WXRInMessage;
	blk_WXROutMessage WXROutMessage;
};

#ifndef SE_STATIC
#	ifndef _DBSIMDBSIM_OWNSHIPNH90
class CDbsimDllHCompatibilityCheck_OwnShipNH90_OwnShipNH90
{
public:
	CDbsimDllHCompatibilityCheck_OwnShipNH90_OwnShipNH90()
	{
		if (!IDbsimCompatibilityValidator::IsDbsimRegistered(4346817576787771278ULL)) // DBSIM Checksum
		{
			IDbsimCompatibilityValidator::ReportIncompatibility(__FILE__, "OwnShipNH90_OwnShipNH90", "dbsim_OwnShipNH90");
		}
	}
};

static CDbsimDllHCompatibilityCheck_OwnShipNH90_OwnShipNH90 gsDbsimChecker_OwnShipNH90_OwnShipNH90;
#	endif	// _DBSIMDBSIM_OWNSHIPNH90
#endif // SE_STATIC

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(pop)
#endif

#endif // ELM_BLK_ST__OWNSHIPNH90__H
