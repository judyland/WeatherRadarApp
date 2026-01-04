//-----------------------------------------------------------------------------
// File Name:		Export/elminfo.h
// Project Name:	OwnShipNH90
//-----------------------------------------------------------------------------
#ifndef ELM_INFO__OWNSHIPNH90__H
#define ELM_INFO__OWNSHIPNH90__H

#if defined(_MSC_VER) && !defined(__KLOCWORK__)
#	pragma once
#endif
#include "elmenum_OwnShipNH90.h"

#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(push, 1)
#endif

// ============================ TYPES ==========================================
typedef int BOOL;
// =============================================================================

// Struct types definitions (order by dependencies)

struct Nh90MalfunctionDamage_AutoPilotMalfunction
{
	bool m_bOnGroundRotorStoppedInceptorSuspicionFailureYawFcc1;	//
	bool m_bOnGroundRotorStoppedInceptorSuspicionFailurePitchFcc2;	//
	bool m_bAfcsDiscrepancy;	//
	bool m_bFcsDegradedSonarCablePositionLoss;	//
	bool m_bAbnormalIncreaseOfControlFrictionInPitchAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInRollAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInCollectiveAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInYawAxis;	//
	bool m_bTrimFailurePitch;	//
	bool m_bTrimFailureRoll;	//
	bool m_bTrimFailureYaw;	//
	bool m_bTrimFailureCollective;	//
	bool m_bAutomaticFlightControlComputerFailure1;	//
	bool m_bAutomaticFlightControlComputerFailure2;	//
	bool m_bDigitalComputerFailure1;	//
	bool m_bDigitalComputerFailure2;	//
	bool m_bAnalogComputerFailure1;	//
	bool m_bAnalogComputerFailure2;	//
	bool m_bFcsControlPanelFailureCentral;	//
	bool m_bFcsControlPanelFailureLateralCopilot;	//
	bool m_bFcsControlPanelFailureLateralPilot;	//
	bool m_bFcsControlPanelFailureAuxiliary;	//
	bool m_bActuatorControlComputerFailure1;	//
	bool m_bActuatorControlComputerFailure2;	//
	bool m_bActuatorControlComputerFailure3;	//
	bool m_bActuatorControlComputerFailure4;	//
	bool m_bCyclicPitchForceFeelLost;	//
	bool m_bCyclicRollForceFeelLost;	//
	bool m_bCollectiveStickForceFeelLost;	//
	bool m_bRudderPedalsForceFeelLost;	//
	bool m_bFcsRunawayPitchUp;	//
	bool m_bFcsRunawayPitchDown;	//
	bool m_bFcsRunawayRollLeft;	//
	bool m_bFcsRunawayRollRight;	//
	bool m_bFcsRunawayCollectiveUp;	//
	bool m_bFcsRunawayCollectiveDown;	//
	bool m_bFcsRunawayYawRight;	//
	bool m_bFcsRunawayYawLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoTail;	//
	bool m_bLossOfArinc1LinkFcsauToFcc;	//
	bool m_bLossOfArinc2LinkFcsauToFcc;	//
	bool m_bPreFlightTestFailureOfAccTest;	//
	bool m_bPreFlightTestFailureOfAnalogTest;	//
	bool m_bLossOfRelativeTrimPitchPositionSensor1A;	//
	bool m_bLossOfRelativeTrimPitchPositionSensor2A;	//
	bool m_bLossOfRelativeTrimRollPositionSensor1A;	//
	bool m_bLossOfRelativeTrimRollPositionSensor2A;	//
	bool m_bLossOfRelativeTrimYawPositionSensor1A;	//
	bool m_bLossOfRelativeTrimYawPositionSensor2A;	//
	bool m_bLossOfRelativeTrimCollectivePositionSensor1A;	//
	bool m_bLossOfRelativeTrimCollectivePositionSensor2A;	//
};

struct Nh90Malfunctions_AutoPilotMalfunction
{
	bool m_bOnGroundRotorStoppedInceptorSuspicionFailureYawFcc1;	//
	bool m_bOnGroundRotorStoppedInceptorSuspicionFailurePitchFcc2;	//
	bool m_bAfcsDiscrepancy;	//
	bool m_bFcsDegradedSonarCablePositionLoss;	//
	bool m_bAbnormalIncreaseOfControlFrictionInPitchAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInRollAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInCollectiveAxis;	//
	bool m_bAbnormalIncreaseOfControlFrictionInYawAxis;	//
	bool m_bTrimFailurePitch;	//
	bool m_bTrimFailureRoll;	//
	bool m_bTrimFailureYaw;	//
	bool m_bTrimFailureCollective;	//
	bool m_bAutomaticFlightControlComputerFailure1;	//
	bool m_bAutomaticFlightControlComputerFailure2;	//
	bool m_bDigitalComputerFailure1;	//
	bool m_bDigitalComputerFailure2;	//
	bool m_bAnalogComputerFailure1;	//
	bool m_bAnalogComputerFailure2;	//
	bool m_bFcsControlPanelFailureCentral;	//
	bool m_bFcsControlPanelFailureLateralCopilot;	//
	bool m_bFcsControlPanelFailureLateralPilot;	//
	bool m_bFcsControlPanelFailureAuxiliary;	//
	bool m_bActuatorControlComputerFailure1;	//
	bool m_bActuatorControlComputerFailure2;	//
	bool m_bActuatorControlComputerFailure3;	//
	bool m_bActuatorControlComputerFailure4;	//
	bool m_bCyclicPitchForceFeelLost;	//
	bool m_bCyclicRollForceFeelLost;	//
	bool m_bCollectiveStickForceFeelLost;	//
	bool m_bRudderPedalsForceFeelLost;	//
	bool m_bFcsRunawayPitchUp;	//
	bool m_bFcsRunawayPitchDown;	//
	bool m_bFcsRunawayRollLeft;	//
	bool m_bFcsRunawayRollRight;	//
	bool m_bFcsRunawayCollectiveUp;	//
	bool m_bFcsRunawayCollectiveDown;	//
	bool m_bFcsRunawayYawRight;	//
	bool m_bFcsRunawayYawLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoFore;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoLeft;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoRight;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane1OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane2OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane3OnServoTail;	//
	bool m_bFcsActuatorControlComputerAccFailOfLane4OnServoTail;	//
	bool m_bLossOfArinc1LinkFcsauToFcc;	//
	bool m_bLossOfArinc2LinkFcsauToFcc;	//
	bool m_bPreFlightTestFailureOfAccTest;	//
	bool m_bPreFlightTestFailureOfAnalogTest;	//
	bool m_bLossOfRelativeTrimPitchPositionSensor1A;	//
	bool m_bLossOfRelativeTrimPitchPositionSensor2A;	//
	bool m_bLossOfRelativeTrimRollPositionSensor1A;	//
	bool m_bLossOfRelativeTrimRollPositionSensor2A;	//
	bool m_bLossOfRelativeTrimYawPositionSensor1A;	//
	bool m_bLossOfRelativeTrimYawPositionSensor2A;	//
	bool m_bLossOfRelativeTrimCollectivePositionSensor1A;	//
	bool m_bLossOfRelativeTrimCollectivePositionSensor2A;	//
};

struct Nh90MalfunctionDamage_AvionicMalfunctions
{
	bool m_bCentralWarningSystemFailure;	//
	bool m_bCmcFailure1;	//
	bool m_bCmcFailure2;	//
	bool m_bMtcFailure1;	//
	bool m_bMtcFailure2;	//
	bool m_bPmcDiscrepancy;	//
	bool m_bPmcFailure1;	//
	bool m_bPmcFailure2;	//
	bool m_bPmcLostByWmc1;	//
	bool m_bPmcLostByWmc2;	//
	bool m_bCursorControlUnitFailure1;	//
	bool m_bCursorControlUnitFailure2;	//
	bool m_bMfdFailure1;	//
	bool m_bMfdFailure2;	//
	bool m_bMfdFailure3;	//
	bool m_bMfdFailure4;	//
	bool m_bMfdFailure5;	//
	bool m_bDisplayKeyboardUnitFailure1;	//
	bool m_bDisplayKeyboardUnitFailure2;	//
	bool m_bDisplayKeyboardUnitFailure3;	//
	bool m_bDisplayKeyboardUnitFailure4;	//
	bool m_bDtdFailure;	//
	bool m_bWarningToneGeneratorFailure;	//
	bool m_bCdtdFailure;	//
	bool m_bMdtdFailure;	//
	bool m_bAuxiliaryKeyboardFailure1;	//
	bool m_bAuxiliaryKeyboardFailure2;	//
	bool m_bAuxiliaryKeyboardFailure3;	//
	bool m_bAuxiliaryKeyboardFailure4;	//
	bool m_bCursorControlUnitFailure3;	//
	bool m_bCursorControlUnitFailure4;	//
};

struct Nh90Malfunctions_AvionicMalfunctions
{
	bool m_bCentralWarningSystemFailure;	//
	bool m_bCmcFailure1;	//
	bool m_bCmcFailure2;	//
	bool m_bMtcFailure1;	//
	bool m_bMtcFailure2;	//
	bool m_bPmcDiscrepancy;	//
	bool m_bPmcFailure1;	//
	bool m_bPmcFailure2;	//
	bool m_bPmcLostByWmc1;	//
	bool m_bPmcLostByWmc2;	//
	bool m_bCursorControlUnitFailure1;	//
	bool m_bCursorControlUnitFailure2;	//
	bool m_bMfdFailure1;	//
	bool m_bMfdFailure2;	//
	bool m_bMfdFailure3;	//
	bool m_bMfdFailure4;	//
	bool m_bMfdFailure5;	//
	bool m_bDisplayKeyboardUnitFailure1;	//
	bool m_bDisplayKeyboardUnitFailure2;	//
	bool m_bDisplayKeyboardUnitFailure3;	//
	bool m_bDisplayKeyboardUnitFailure4;	//
	bool m_bDtdFailure;	//
	bool m_bWarningToneGeneratorFailure;	//
	bool m_bCdtdFailure;	//
	bool m_bMdtdFailure;	//
	bool m_bAuxiliaryKeyboardFailure1;	//
	bool m_bAuxiliaryKeyboardFailure2;	//
	bool m_bAuxiliaryKeyboardFailure3;	//
	bool m_bAuxiliaryKeyboardFailure4;	//
	bool m_bCursorControlUnitFailure3;	//
	bool m_bCursorControlUnitFailure4;	//
};

struct Nh90Configuration_CargoZone
{
	unsigned int m_nRightWeight;	//
	unsigned int m_nCenterWeight;	//
	unsigned int m_nLeftWeight;	//
};

struct Nh90Configuration_CargoZoneEnable
{
	bool m_bZoneA;	//
	bool m_bZoneB;	//
	bool m_bZoneC;	//
	bool m_bZoneD;	//
	bool m_bZoneE;	//
	bool m_bZoneF;	//
	bool m_bZoneG;	//
	bool m_bZoneH;	//
	bool m_bZoneI;	//
	bool m_bZoneJ;	//
	bool m_bZoneK;	//
};

struct Nh90CircuitBrakers_Communication
{
	bool m_bDirectorFinder;	//
	bool m_bHighFrequencyCrypt;	//
	bool m_bHighFrequencySingleSideBand;	//
	bool m_bIdFriendFoeTransponder1;	//
	bool m_bIdFriendFoeTransponder2;	//
	bool m_bIntercomSys1;	//
	bool m_bIntercomSys2;	//
	bool m_bTacticalVUHFControl1;	//
	bool m_bTacticalVUHFControl2;	//
	bool m_bTacticalVUHFCrypt;	//
	bool m_bTacticalVUHFhighPowerAmp1;	//
	bool m_bTacticalVUHFhighPowerAmp2;	//
	bool m_bVUHF1Crypt;	//
	bool m_bVUHF1Power_01;	//
	bool m_bVUHF1Power_02;	//
	bool m_bVUHF2Crypt;	//
	bool m_bVUHF2Power_01;	//
	bool m_bVUHF2Power_02;	//
	bool m_bVUHFControl1;	//
	bool m_bVUHFControl2;	//
};

struct Nh90MalfunctionDamage_CommunicationMalfunctions
{
	bool m_bVUhfFailure1;	//
	bool m_bVUhfFailure2;	//
	bool m_bHfFailure;	//
	bool m_bDfFailure;	//
	bool m_bSatcomFailure;	//
	bool m_bPilotDH;	//
	bool m_bCopilotDH;	//
	bool m_bHFTuning;	//
	bool m_bCMUFailure;	//
	bool m_bVUhfFailure3;	//
	bool m_bVUhfFailure4;	//
};

struct Nh90Malfunctions_CommunicationMalfunctions
{
	bool m_bVUhfFailure1;	//
	bool m_bVUhfFailure2;	//
	bool m_bHfFailure;	//
	bool m_bDfFailure;	//
	bool m_bSatcomFailure;	//
	bool m_bPilotDH;	//
	bool m_bCopilotDH;	//
	bool m_bHFTuning;	//
	bool m_bCMUFailure;	//
	bool m_bVUhfFailure3;	//
	bool m_bVUhfFailure4;	//
};

struct Nh90CircuitBrakers_ControlAndDisplays
{
	bool m_bAdvisoryPanel1;	//
	bool m_bAdvisoryPanel2;	//
	bool m_bAltimeter;	//
	bool m_bCoreManagementComp1;	//
	bool m_bCoreManagementComp2;	//
	bool m_bDataTransferDevice;	//
	bool m_bDKU1;	//
	bool m_bDKU2;	//
	bool m_bEngControlPanelDisp1;	//
	bool m_bEngControlPanelDisp2;	//
	bool m_bDataTransferComp;	//
	bool m_bLeftWarningPanel;	//
	bool m_bMultifDisplay1;	//
	bool m_bMultifDisplay2;	//
	bool m_bMultifDisplay3;	//
	bool m_bMultifDisplay4;	//
	bool m_bMultifDisplay5;	//
	bool m_bBkpINdCopilot1;	//
	bool m_bBkpINdCopilot2;	//
	bool m_bBkpINdPilot1;	//
	bool m_bBkpINdPilot2;	//
	bool m_bPlantManagementComp1;	//
	bool m_bPlantManagementComp2;	//
	bool m_bRemoteFreqComputer1;	//
	bool m_bRemoteFreqComputer2;	//
	bool m_bRightWarningPanel;	//
	bool m_bStbyHorizon1;	//
	bool m_bStbyHorizon2;	//
	bool m_bVoiceFlightDataRec1;	//
	bool m_bVoiceFlightDataRec2;	//
	bool m_bWarningManagementComp1;	//
	bool m_bWarningManagementComp2;	//
};

struct Nh90MalfunctionDamage_EcsMalfunctions
{
	bool m_bMabVentilationFailureBayV1;	//
	bool m_bMabVentilationFailureBayV2;	//
	bool m_bCabinTemperatureControlFailureCooling;	//
	bool m_bCabinTemperatureControlFailureHeating;	//
	bool m_bCockpitTemperatureControlFailureCooling;	//
	bool m_bCockpitTemperatureControlFailureHeating;	//
	bool m_bCockpitDuctOvertemperature;	//
	bool m_bLeftAftAvionicBayVentilationLoss;	//
};

struct Nh90Malfunctions_EcsMalfunctions
{
	bool m_bMabVentilationFailureBayV1;	//
	bool m_bMabVentilationFailureBayV2;	//
	bool m_bCabinTemperatureControlFailureCooling;	//
	bool m_bCabinTemperatureControlFailureHeating;	//
	bool m_bCockpitTemperatureControlFailureCooling;	//
	bool m_bCockpitTemperatureControlFailureHeating;	//
	bool m_bCockpitDuctOvertemperature;	//
	bool m_bLeftAftAvionicBayVentilationLoss;	//
};

struct Nh90CircuitBrakers_ElectricalPowerSystem
{
	bool m_bACElecMasterBox1;	//
	bool m_bACElecMasterBox2;	//
	bool m_bBatt1Heating;	//
	bool m_bBatt2Heating;	//
	bool m_bCockpitCbPanel1DBAT;	//
	bool m_bCockpitCbPanel1ESS11;	//
	bool m_bCockpitCbPanel1ESS12;	//
	bool m_bCockpitCbPanel1Stby1;	//
	bool m_bCockpitCbPanel1Stby2;	//
	bool m_bCockpitCbPanel2DBAT;	//
	bool m_bCockpitCbPanel2ESS21;	//
	bool m_bCockpitCbPanel2ESS22;	//
	bool m_bCockpitCbPanel2Stby1;	//
	bool m_bCockpitCbPanel2Stby2;	//
	bool m_bDCElectricMasterBox1_01;	//
	bool m_bDCElectricMasterBox1_02;	//
	bool m_bDCElectricMasterBox2_01;	//
	bool m_bDCElectricMasterBox2_02;	//
	bool m_bEmergencyGen1;	//
	bool m_bEmergencyGen2;	//
	bool m_bStbyModeBusBar1_01;	//
	bool m_bStbyModeBusBar1_02;	//
	bool m_bStbyModeBusBar2_01;	//
	bool m_bStbyModeBusBar2_02;	//
	bool m_bTRU1;	//
	bool m_bTRU2;	//
};

struct Nh90MalfunctionDamage_ElectricMalfunctions
{
	bool m_bBatteryHighTemperature1;	//
	bool m_bBatteryHighTemperature2;	//
	bool m_bBatteryFailure1;	//
	bool m_bBatteryFailure2;	//
	bool m_bBatterHeatingFailure1;	//
	bool m_bBatterHeatingFailure2;	//
	bool m_bEmergencyBusBarFailure1;	//
	bool m_bEmergencyBusBarFailure2;	//
	bool m_bEmergencyBusBarFailureBoth;	//
	bool m_bAlternatorFailure1;	//
	bool m_bAlternatorFailure2;	//
	bool m_bAlternatorFailureBoth;	//
	bool m_bAlternatorFailure3;	//
	bool m_bTruContactorOpen1;	//
	bool m_bTruContactorOpen2;	//
	bool m_bEmergencyGeneratorFailure1;	//
	bool m_bEmergencyGeneratorFailure2;	//
	bool m_bAcBusBarFailure1;	//
	bool m_bAcBusBarFailure2;	//
	bool m_bAcBusBarFailure3;	//
	bool m_bAcBusBarFailure4;	//
	bool m_bDcMainBusFailure1;	//
	bool m_bDcMainBusFailure2;	//
	bool m_bDcBatteryBusFailure1;	//
	bool m_bDcBatteryBusFailure2;	//
	bool m_bDcEssentialBusFailure1;	//
	bool m_bDcEssentialBusFailure2;	//
	bool m_bDcSheedingBusFailure1;	//
	bool m_bDcSheedingBusFailure2;	//
	bool m_bDcSbmbBusFailure1;	//
	bool m_bDcSbmbBusFailure2;	//
	bool m_bHcSupplyModeFailureOnGround;	//
	bool m_bAcEpuFailureOnGround;	//
	bool m_bDcEpuFailureOnGround;	//
};

struct Nh90Malfunctions_ElectricMalfunctions
{
	bool m_bBatteryHighTemperature1;	//
	bool m_bBatteryHighTemperature2;	//
	bool m_bBatteryFailure1;	//
	bool m_bBatteryFailure2;	//
	bool m_bBatterHeatingFailure1;	//
	bool m_bBatterHeatingFailure2;	//
	bool m_bEmergencyBusBarFailure1;	//
	bool m_bEmergencyBusBarFailure2;	//
	bool m_bEmergencyBusBarFailureBoth;	//
	bool m_bAlternatorFailure1;	//
	bool m_bAlternatorFailure2;	//
	bool m_bAlternatorFailureBoth;	//
	bool m_bAlternatorFailure3;	//
	bool m_bTruContactorOpen1;	//
	bool m_bTruContactorOpen2;	//
	bool m_bEmergencyGeneratorFailure1;	//
	bool m_bEmergencyGeneratorFailure2;	//
	bool m_bAcBusBarFailure1;	//
	bool m_bAcBusBarFailure2;	//
	bool m_bAcBusBarFailure3;	//
	bool m_bAcBusBarFailure4;	//
	bool m_bDcMainBusFailure1;	//
	bool m_bDcMainBusFailure2;	//
	bool m_bDcBatteryBusFailure1;	//
	bool m_bDcBatteryBusFailure2;	//
	bool m_bDcEssentialBusFailure1;	//
	bool m_bDcEssentialBusFailure2;	//
	bool m_bDcSheedingBusFailure1;	//
	bool m_bDcSheedingBusFailure2;	//
	bool m_bDcSbmbBusFailure1;	//
	bool m_bDcSbmbBusFailure2;	//
	bool m_bHcSupplyModeFailureOnGround;	//
	bool m_bAcEpuFailureOnGround;	//
	bool m_bDcEpuFailureOnGround;	//
};

struct Nh90MalfunctionDamage_EngineMalfunctions
{
	bool m_bEngineFirePostShutdown1;	//
	bool m_bEngineFirePostShutdown2;	//
	bool m_bEngineFailureNoRestart1;	//
	bool m_bEngineFailureNoRestart2;	//
	bool m_bEngineMinimumOilPressure1;	//
	bool m_bEngineMinimumOilPressure2;	//
	bool m_bEngineGovernorFailure1;	//
	bool m_bEngineGovernorFailure2;	//
	bool m_bEngineGovernorDegraded1T4SensorFailure;	//
	bool m_bEngineGovernorDegraded2T4SensorFailure;	//
	bool m_bEngineGovernorDegraded1TorqueSensorFailure;	//
	bool m_bEngineGovernorDegraded2TorqueSensorFailure;	//
	bool m_bEngineChipDetection1;	//
	bool m_bEngineChipDetection2;	//
	bool m_bNrIncreaseFunctionFailure;	//
	bool m_bEngineFreeTurbineShaftBroken1;	//
	bool m_bEngineFreeTurbineShaftBroken2;	//
	bool m_bEngineOverspeedProtectionFailure1;	//
	bool m_bEngineOverspeedProtectionFailure2;	//
	bool m_bEngineOilFilterClogged1;	//
	bool m_bEngineOilFilterClogged2;	//
	bool m_bEngineStarterPowerSupplyFault1;	//
	bool m_bEngineStarterPowerSupplyFault2;	//
	bool m_bEngineStarterFailsToDisengange1;	//
	bool m_bEngineStarterFailsToDisengange2;	//
	bool m_bEngineHotStart1;	//
	bool m_bEngineHotStart2;	//
	bool m_bEngineFailureRestart1;	//
	bool m_bEngineFailureRestart2;	//
	bool m_bEngineHighOilTemperature1;	//
	bool m_bEngineHighOilTemperature2;	//
	bool m_bEngineStartFailureFailsToLight1;	//
	bool m_bEngineStartFailureFailsToLight2;	//
	bool m_bEngineEecuPowerSupplyFailure1;	//
	bool m_bEngineEecuPowerSupplyFailure2;	//
	bool m_bEngineCrosstalkSignalFailure;	//
	bool m_bEngineRunUpDueToFuelControllerFailure1;	//
	bool m_bEngineRunUpDueToFuelControllerFailure2;	//
	bool m_bEngineRunDownDueToFuelControllerFailure1;	//
	bool m_bEngineRunDownDueToFuelControllerFailure2;	//
	bool m_bEngineLowPressureFuelPumpFailure1;	//
	bool m_bEngineLowPressureFuelPumpFailure2;	//
	bool m_bApuEcuFailure;	//
	bool m_bApuFuelFailure;	//
	bool m_bEngine1PostShutdownOvertemperature;	//
	bool m_bEngine2PostShutdownOvertemperature;	//
};

struct Nh90Malfunctions_EngineMalfunctions
{
	bool m_bEngineFirePostShutdown1;	//
	bool m_bEngineFirePostShutdown2;	//
	bool m_bEngineFailureNoRestart1;	//
	bool m_bEngineFailureNoRestart2;	//
	bool m_bEngineMinimumOilPressure1;	//
	bool m_bEngineMinimumOilPressure2;	//
	bool m_bEngineGovernorFailure1;	//
	bool m_bEngineGovernorFailure2;	//
	bool m_bEngineGovernorDegraded1T4SensorFailure;	//
	bool m_bEngineGovernorDegraded2T4SensorFailure;	//
	bool m_bEngineGovernorDegraded1TorqueSensorFailure;	//
	bool m_bEngineGovernorDegraded2TorqueSensorFailure;	//
	bool m_bEngineChipDetection1;	//
	bool m_bEngineChipDetection2;	//
	bool m_bNrIncreaseFunctionFailure;	//
	bool m_bEngineFreeTurbineShaftBroken1;	//
	bool m_bEngineFreeTurbineShaftBroken2;	//
	bool m_bEngineOverspeedProtectionFailure1;	//
	bool m_bEngineOverspeedProtectionFailure2;	//
	bool m_bEngineOilFilterClogged1;	//
	bool m_bEngineOilFilterClogged2;	//
	bool m_bEngineStarterPowerSupplyFault1;	//
	bool m_bEngineStarterPowerSupplyFault2;	//
	bool m_bEngineStarterFailsToDisengange1;	//
	bool m_bEngineStarterFailsToDisengange2;	//
	bool m_bEngineHotStart1;	//
	bool m_bEngineHotStart2;	//
	bool m_bEngineFailureRestart1;	//
	bool m_bEngineFailureRestart2;	//
	bool m_bEngineHighOilTemperature1;	//
	bool m_bEngineHighOilTemperature2;	//
	bool m_bEngineStartFailureFailsToLight1;	//
	bool m_bEngineStartFailureFailsToLight2;	//
	bool m_bEngineEecuPowerSupplyFailure1;	//
	bool m_bEngineEecuPowerSupplyFailure2;	//
	bool m_bEngineCrosstalkSignalFailure;	//
	bool m_bEngineRunUpDueToFuelControllerFailure1;	//
	bool m_bEngineRunUpDueToFuelControllerFailure2;	//
	bool m_bEngineRunDownDueToFuelControllerFailure1;	//
	bool m_bEngineRunDownDueToFuelControllerFailure2;	//
	bool m_bEngineLowPressureFuelPumpFailure1;	//
	bool m_bEngineLowPressureFuelPumpFailure2;	//
	bool m_bApuEcuFailure;	//
	bool m_bApuFuelFailure;	//
	bool m_bEngine1PostShutdownOvertemperature;	//
	bool m_bEngine2PostShutdownOvertemperature;	//
};

struct Nh90CircuitBrakers_EngineSystem
{
	bool m_bAPUControl;	//
	bool m_bAPUCElecControlUnit;	//
	bool m_bElecEngineControlUnit1A_01;	//
	bool m_bElecEngineControlUnit1A_02;	//
	bool m_bElecEngineControlUnit1B_01;	//
	bool m_bElecEngineControlUnit1B_02;	//
	bool m_bFireDetect1_01;	//
	bool m_bFireDetect1_02;	//
	bool m_bFireDetect2_01;	//
	bool m_bFireDetect2_02;	//
	bool m_bFireExt1_01;	//
	bool m_bFireExt1_02;	//
	bool m_bFireExt2_01;	//
	bool m_bFireExt2_02;	//
};

struct Nh90CircuitBrakers_EnvironmentalControlSystem
{
	bool m_bAvionicBayVentMU_ACC1_01;	//
	bool m_bAvionicBayVentMU_ACC1_02;	//
	bool m_bAvionicBayVentMU_ACC2_01;	//
	bool m_bAvionicBayVentMU_ACC2_02;	//
	bool m_bAvionicBayVentMU_Left01;	//
	bool m_bAvionicBayVentMU_Left02;	//
	bool m_bAvionicBayVentMU_Right01;	//
	bool m_bAvionicBayVentMU_Right02;	//
	bool m_bCabinEvaporatorFan;	//
	bool m_bCabinCondensorFan;	//
	bool m_bCockpitEvaporatorFan;	//
	bool m_bCockpitCondensorFan;	//
	bool m_bDigitalTempControlUnit_01;	//
	bool m_bDigitalTempControlUnit_02;	//
	bool m_bLeftMainAvionicBayAncUnit1;	//
	bool m_bLeftMainAvionicBayAncUnit2;	//
	bool m_bLeftMainAvionicBayFan1;	//
	bool m_bLeftMainAvionicBayFan2;	//
	bool m_bLeftMainAvionicBayScavengeFan;	//
	bool m_bNoseAvionicBayFan1;	//
	bool m_bNoseAvionicBayFan2;	//
	bool m_bRearFan1;	//
	bool m_bRightMainAvionicBayAncUnit1;	//
	bool m_bRightMainAvionicBayAncUnit2;	//
	bool m_bRightMainAvionicBayFan1;	//
	bool m_bRightMainAvionicBayFan2;	//
	bool m_bRightMainAvionicBayScavengeFan;	//
};

struct Nh90MalfunctionDamage_EwsMalfunctions
{
	bool m_bEwsFailure;	//
	bool m_bChaffFlareFailure;	//
	bool m_bChaffFlareMisfire;	//
	bool m_bRwrFailure;	//
	bool m_bRwrDegraded;	//
	bool m_bLwrFailure;	//
	bool m_bLwrDegraded;	//
	bool m_bMldsFailure;	//
	bool m_bMldsDegraded;	//
};

struct Nh90Malfunctions_EwsMalfunctions
{
	bool m_bEwsFailure;	//
	bool m_bChaffFlareFailure;	//
	bool m_bChaffFlareMisfire;	//
	bool m_bRwrFailure;	//
	bool m_bRwrDegraded;	//
	bool m_bLwrFailure;	//
	bool m_bLwrDegraded;	//
	bool m_bMldsFailure;	//
	bool m_bMldsDegraded;	//
};

struct Nh90Configuration_ExternalAuxiliaryFuelTanks
{
	unsigned int m_nLeftTankWeight;	//
	unsigned int m_nRightTankWeight;	//
	bool m_bEnabled;	//
};

struct Nh90MalfunctionDamage_FireMalfunctions
{
	bool m_bEngineBayFireExtinguishable1Bottle1;	//
	bool m_bEngineBayFireExtinguishable2Bottles1;	//
	bool m_bEngineBayFireNotExtinguishable1;	//
	bool m_bEngineBayFireExtinguishable1Bottle2;	//
	bool m_bEngineBayFireExtinguishable2Bottles2;	//
	bool m_bEngineBayFireNotExtinguishable2;	//
	bool m_bFireInApuBay;	//
	bool m_bFireInMgbCompartment1;	//
	bool m_bFireInMgbCompartment2;	//
};

struct Nh90Malfunctions_FireMalfunctions
{
	bool m_bEngineBayFireExtinguishable1Bottle1;	//
	bool m_bEngineBayFireExtinguishable2Bottles1;	//
	bool m_bEngineBayFireNotExtinguishable1;	//
	bool m_bEngineBayFireExtinguishable1Bottle2;	//
	bool m_bEngineBayFireExtinguishable2Bottles2;	//
	bool m_bEngineBayFireNotExtinguishable2;	//
	bool m_bFireInApuBay;	//
	bool m_bFireInMgbCompartment1;	//
	bool m_bFireInMgbCompartment2;	//
};

struct Nh90CircuitBrakers_FlightControlComputer
{
	bool m_bActuatorControlComp1_01;	//
	bool m_bActuatorControlComp1_02;	//
	bool m_bActuatorControlComp2_01;	//
	bool m_bActuatorControlComp2_02;	//
	bool m_bAutoFCSControlPanel_01;	//
	bool m_bAutoFCSControlPanel_02;	//
	bool m_bAutoFCSControlPanel1_01;	//
	bool m_bAutoFCSControlPanel2_02;	//
	bool m_bDynamicSensorUnit1;	//
	bool m_bDynamicSensorUnit2;	//
	bool m_bFCC1Analogical1;	//
	bool m_bFCC1Analogical2;	//
	bool m_bFCC1Digital1;	//
	bool m_bFCC1Digital2;	//
	bool m_bFCC2Analogical1;	//
	bool m_bFCC2Analogical2;	//
	bool m_bFCC2Digital1;	//
	bool m_bFCC2Digital2;	//
	bool m_bFCSAuxiliaryUnit1;	//
	bool m_bFCSAuxiliaryUnit2;	//
};

struct Nh90Configuration_FloatationDevices
{
	bool m_bCylindricalFloatationForwardLeft;	//
	bool m_bCylindricalFloatationForwardRight;	//
	bool m_bCylindricalFloatationRearLeft;	//
	bool m_bCylindricalFloatationRearRight;	//
	bool m_bEnabled;	//
};

struct Nh90Configuration_Fuel
{
	unsigned int m_nQuantity;	//
	bool m_bEnabled;	//
};

struct Nh90MalfunctionDamage_FuelMalfunctions
{
	bool m_bApuFuelModeFailure;	//
	bool m_bEngine1SupplyPumpFailureLeft;	//
	bool m_bEngine1SupplyPumpFailureRight;	//
	bool m_bEngine2SupplyPumpFailureLeft;	//
	bool m_bEngine2SupplyPumpFailureRight;	//
	bool m_bEngineLowFuelPressure1;	//
	bool m_bEngineLowFuelPressure2;	//
	bool m_bEngineFuelFilterClogging1;	//
	bool m_bEngineFuelFilterClogging2;	//
	bool m_bFuelManagementComputerFailure;	//
	bool m_bCockpitFuelPanelFailure;	//
	bool m_bFuelTankLeakageVariable3;	//
	float m_fFuelTankLeakageVariable3Param1;	//
	bool m_bFuelTankLeakageVariable4;	//
	float m_fFuelTankLeakageVariable4Param1;	//
	bool m_bFuelDumpingModeFailure;	//
	bool m_bFuelBalanceModeFailure;	//
	bool m_bFuelSensorFailureTank1;	//
	bool m_bFuelSensorFailureTank2;	//
	bool m_bFuelSensorFailureTank3;	//
	bool m_bFuelSensorFailureTank4;	//
	bool m_bFuelSensorFailureTank6;	//
	bool m_bFuelSensorFailureTank7;	//
};

struct Nh90Malfunctions_FuelMalfunctions
{
	bool m_bApuFuelModeFailure;	//
	bool m_bEngine1SupplyPumpFailureLeft;	//
	bool m_bEngine1SupplyPumpFailureRight;	//
	bool m_bEngine2SupplyPumpFailureLeft;	//
	bool m_bEngine2SupplyPumpFailureRight;	//
	bool m_bEngineLowFuelPressure1;	//
	bool m_bEngineLowFuelPressure2;	//
	bool m_bEngineFuelFilterClogging1;	//
	bool m_bEngineFuelFilterClogging2;	//
	bool m_bFuelManagementComputerFailure;	//
	bool m_bCockpitFuelPanelFailure;	//
	bool m_bFuelTankLeakageVariable3;	//
	float m_fFuelTankLeakageVariable3Param1;	//
	bool m_bFuelTankLeakageVariable4;	//
	float m_fFuelTankLeakageVariable4Param1;	//
	bool m_bFuelDumpingModeFailure;	//
	bool m_bFuelBalanceModeFailure;	//
	bool m_bFuelSensorFailureTank1;	//
	bool m_bFuelSensorFailureTank2;	//
	bool m_bFuelSensorFailureTank3;	//
	bool m_bFuelSensorFailureTank4;	//
	bool m_bFuelSensorFailureTank6;	//
	bool m_bFuelSensorFailureTank7;	//
};

struct Nh90CircuitBrakers_FuelSystem
{
	bool m_bCockpitFuelPanel1;	//
	bool m_bCockpitFuelPanel2;	//
	bool m_bExtFuelControlUnitLeftHand;	//
	bool m_bExtFuelControlUnitRightHand;	//
	bool m_bExternalTank1;	//
	bool m_bExternalTank2;	//
	bool m_bFuelManagementComputer1;	//
	bool m_bFuelManagementComputer2;	//
	bool m_bFuelManagementComputer3;	//
	bool m_bFuelSOV1_01;	//
	bool m_bFuelSOV1_02;	//
	bool m_bFuelSOV2_01;	//
	bool m_bFuelSOV2_02;	//
};

struct Nh90CircuitBrakers_GITA
{
	bool m_bCautionAdvisoryLight1;	//
	bool m_bCautionAdvisoryLight2;	//
	bool m_bVideoDistributionUnit1;	//
	bool m_bVideoDistributionUnit2;	//
	bool m_bMIDSLowVolumeTerminal;	//
	bool m_bTacticalVUHFCrypt2;	//
	bool m_bTacticalVUHFPower11;	//
	bool m_bTacticalVUHFPower12;	//
	bool m_bTacticalVUHFPower21;	//
	bool m_bTacticalVUHFPower22;	//
	bool m_bEngine1Control;	//
	bool m_bEngine2Control;	//
	bool m_bEngine1AntiIce;	//
	bool m_bEngine2AntiIce;	//
	bool m_bPanelLight1;	//
	bool m_bPanelLight2;	//
	bool m_bParachutingLight;	//
	bool m_bRightLandingLight;	//
	bool m_bCHaffFlareSafetyPinUnit;	//
	bool m_bCursorControlUnit;	//
	bool m_bDigitalMapGenerator;	//
	bool m_bElectronicWarfareSystem;	//
	bool m_bElectronicWarfareSystemElecUnit;	//
	bool m_bFloorWinch;	//
	bool m_bHMSD1ControlPanel;	//
	bool m_bHMSD2ControlPanel;	//
	bool m_bHMSD1ElectronicUnit;	//
	bool m_bHMSD2ElectronicUnit;	//
	bool m_bMissileLaunchDetectorUnit1;	//
	bool m_bMissileLaunchDetectorUnit2;	//
	bool m_bMissileLaunchDetectorUnit3;	//
	bool m_bMissileLaunchDetectorUnit4;	//
	bool m_bObstacleWarningSystem;	//
	bool m_bRampHatchElectricalActuatorSystem;	//
	bool m_bWeatherRadar1;	//
	bool m_bWeatherRadar2;	//
};

struct Nh90CircuitBrakers_H2HMessageHeader
{
	enmNh90CircuitBrakers_H2HMessageIdentifierType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct Nh90MalfunctionDamage_H2HMessageHeader
{
	enmNh90MalfunctionDamage_H2HMessageIdentifierType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct Nh90Malfunctions_H2HMessageHeader
{
	enmNh90Malfunctions_H2HMessageIdentifierType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct Nh90Cargo_Header
{
	enmNh90Cargo_MessageTypeType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct Nh90Configuration_Header
{
	enmNh90Configuration_MessageTypeType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct NH90ModelOutputs_Header
{
	enmNH90ModelOutputs_MessageTypeType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct NH90WeatherRadar_Header
{
	enmNH90WeatherRadar_MessageTypeType m_eType;	//
	unsigned int m_nCounter;	//
	unsigned int m_nDataLength;	//
	double m_dTimeStamp;	//
	unsigned int m_nCrc;	//
};

struct Nh90MalfunctionDamage_HydraulicMalfunctions
{
	bool m_bHydraulicFluidTemperatureHighVariable1;	//
	float m_fHydraulicFluidTemperatureHighVariable1Param1;	//
	bool m_bHydraulicFluidTemperatureHighVariable2;	//
	float m_fHydraulicFluidTemperatureHighVariable2Param1;	//
	bool m_bEPHighTemperature;	//
	bool m_bFCCircuitLowPressure1;	//
	bool m_bFCCircuitLowPressure2;	//
	bool m_bHydPumpLowPressure1;	//
	bool m_bHydPumpLowPressure2;	//
	bool m_bHydPumpLowPressure4;	//
	bool m_bTRServoLowPressure;	//
	bool m_bEPLowPressure;	//
	bool m_bHydUtilLowPressure2;	//
	bool m_bHydAbnormalPressureVariable1;	//
	float m_fHydAbnormalPressureVariable1Param1;	//
	bool m_bHydAbnormalPressureVariable2;	//
	float m_fHydAbnormalPressureVariable2Param1;	//
	bool m_bHydLowFluidLevel1;	//
	bool m_bHydLowFluidLevel2;	//
	bool m_bHydMinimumFluidLevel1;	//
	bool m_bHydMinimumFluidLevel2;	//
	bool m_bHydFluidLeakageVariable1;	//
	float m_fHydFluidLeakageVariable1Param1;	//
	bool m_bHydFluidLeakageVariable2;	//
	float m_fHydFluidLeakageVariable2Param1;	//
};

struct Nh90Malfunctions_HydraulicMalfunctions
{
	bool m_bHydraulicFluidTemperatureHighVariable1;	//
	float m_fHydraulicFluidTemperatureHighVariable1Param1;	//
	bool m_bHydraulicFluidTemperatureHighVariable2;	//
	float m_fHydraulicFluidTemperatureHighVariable2Param1;	//
	bool m_bEPHighTemperature;	//
	bool m_bFCCircuitLowPressure1;	//
	bool m_bFCCircuitLowPressure2;	//
	bool m_bHydPumpLowPressure1;	//
	bool m_bHydPumpLowPressure2;	//
	bool m_bHydPumpLowPressure4;	//
	bool m_bTRServoLowPressure;	//
	bool m_bEPLowPressure;	//
	bool m_bHydUtilLowPressure2;	//
	bool m_bHydAbnormalPressureVariable1;	//
	float m_fHydAbnormalPressureVariable1Param1;	//
	bool m_bHydAbnormalPressureVariable2;	//
	float m_fHydAbnormalPressureVariable2Param1;	//
	bool m_bHydLowFluidLevel1;	//
	bool m_bHydLowFluidLevel2;	//
	bool m_bHydMinimumFluidLevel1;	//
	bool m_bHydMinimumFluidLevel2;	//
	bool m_bHydFluidLeakageVariable1;	//
	float m_fHydFluidLeakageVariable1Param1;	//
	bool m_bHydFluidLeakageVariable2;	//
	float m_fHydFluidLeakageVariable2Param1;	//
};

struct Nh90CircuitBrakers_HydraulicPowerSystem
{
	bool m_bElectricalHydPumpControl;	//
	bool m_bEleDrivenHydPumpPwr;	//
	bool m_bHydCirc1SOV;	//
	bool m_bHydCirc1TailRotorSOV;	//
	bool m_bHydCirc12OV;	//
	bool m_bHydCirc2UtilSOV;	//
};

struct Nh90CircuitBrakers_IceAndRainProtection
{
	bool m_bDeiceComputer1;	//
	bool m_bDeiceComputer2;	//
	bool m_bHorizontalStabilizierDeice1;	//
	bool m_bHorizontalStabilizierDeice2;	//
	bool m_bIceDetectionSeverityBox1;	//
	bool m_bIceDetectionSeverityBox2;	//
	bool m_bLeftWhsldAntiIce;	//
	bool m_bRightWhsldAntiIce;	//
	bool m_bWhsldWasherSys;	//
	bool m_bWhsldWasherWiper1;	//
	bool m_bWhsldWasherWiper2;	//
};

struct Nh90MalfunctionDamage_IrpsMalfunctions
{
	bool m_bEngineAntiIcingLoss1;	//
	bool m_bEngineAntiIcingLoss2;	//
	bool m_bIcingDetectionSystemFailure;	//
	bool m_bPowerDeIcingUnitFailure1;	//
	bool m_bPowerDeIcingUnitFailure2;	//
	bool m_bMainRotorDeIcingSystemFailure;	//
	bool m_bMainRotorDeicingSystemDegradation;	//
	bool m_bTailRotorAntiIcingSystemDegradation;	//
	bool m_bHorizontalStabilizerDeIcingFailure;	//
	bool m_bPitotHeaterFailure1;	//
	bool m_bPitotHeaterFailure2;	//
	bool m_bWindshieldAntiIcingFailure1;	//
	bool m_bWindshieldAntiIcingFailure2;	//
	bool m_bPitotHeaterFailureStandby;	//
};

struct Nh90Malfunctions_IrpsMalfunctions
{
	bool m_bEngineAntiIcingLoss1;	//
	bool m_bEngineAntiIcingLoss2;	//
	bool m_bIcingDetectionSystemFailure;	//
	bool m_bPowerDeIcingUnitFailure1;	//
	bool m_bPowerDeIcingUnitFailure2;	//
	bool m_bMainRotorDeIcingSystemFailure;	//
	bool m_bMainRotorDeicingSystemDegradation;	//
	bool m_bTailRotorAntiIcingSystemDegradation;	//
	bool m_bHorizontalStabilizerDeIcingFailure;	//
	bool m_bPitotHeaterFailure1;	//
	bool m_bPitotHeaterFailure2;	//
	bool m_bWindshieldAntiIcingFailure1;	//
	bool m_bWindshieldAntiIcingFailure2;	//
	bool m_bPitotHeaterFailureStandby;	//
};

struct Nh90CircuitBrakers_LandinGearSystem
{
	bool m_bLndGearAncillaryUnit1_01;	//
	bool m_bLndGearAncillaryUnit1_02;	//
	bool m_bLndGearAncillaryUnit1_03;	//
	bool m_bLndGearAncillaryUnit2_01;	//
	bool m_bLndGearAncillaryUnit2_02;	//
	bool m_bLndGearAncillaryUnit2_03;	//
	bool m_bLandGearSysDown;	//
	bool m_bLandGearSysEmergency;	//
	bool m_bLandGearSysLever;	//
	bool m_bWheelBrake;	//
};

struct Nh90MalfunctionDamage_LandingGearMalfunctions
{
	bool m_bLandingGearFailureToLockNose;	//
	bool m_bLandingGearFailureToLockLeft;	//
	bool m_bLandingGearFailureToLockRight;	//
	bool m_bLdgEmergencyExtentionDegradation;	//
	bool m_bWBAccumulatorAbnormalPressure;	//
	bool m_bWeightOnWheelsSwitchFailure;	//
	bool m_bLandingGearFailsToRetractAmberLightsNose;	//
	bool m_bLandingGearFailsToRetractAmberLightsLeft;	//
	bool m_bLandingGearFailsToRetractAmberLightsRight;	//
	bool m_bLandingGearFailsToRetractGreenLightsNose;	//
	bool m_bLandingGearFailsToRetractGreenLightsLeft;	//
	bool m_bLandingGearFailsToRetractGreenLightsRight;	//
	bool m_bTyreBurstNose;	//
	bool m_bTyreBurstLeft;	//
	bool m_bTyreBurstRight;	//
	bool m_bParkingBrakeFailsToOn;	//
	bool m_bParkingBrakeFailsToOff;	//
	bool m_bNoseLandingGearSteeringNwsFailure;	//
};

struct Nh90Malfunctions_LandingGearMalfunctions
{
	bool m_bLandingGearFailureToLockNose;	//
	bool m_bLandingGearFailureToLockLeft;	//
	bool m_bLandingGearFailureToLockRight;	//
	bool m_bLdgEmergencyExtentionDegradation;	//
	bool m_bWBAccumulatorAbnormalPressure;	//
	bool m_bWeightOnWheelsSwitchFailure;	//
	bool m_bLandingGearFailsToRetractAmberLightsNose;	//
	bool m_bLandingGearFailsToRetractAmberLightsLeft;	//
	bool m_bLandingGearFailsToRetractAmberLightsRight;	//
	bool m_bLandingGearFailsToRetractGreenLightsNose;	//
	bool m_bLandingGearFailsToRetractGreenLightsLeft;	//
	bool m_bLandingGearFailsToRetractGreenLightsRight;	//
	bool m_bTyreBurstNose;	//
	bool m_bTyreBurstLeft;	//
	bool m_bTyreBurstRight;	//
	bool m_bParkingBrakeFailsToOn;	//
	bool m_bParkingBrakeFailsToOff;	//
	bool m_bNoseLandingGearSteeringNwsFailure;	//
};

struct Nh90CircuitBrakers_LightingSystem
{
	bool m_bAnticollisionLt1;	//
	bool m_bAnticollisionLt2;	//
	bool m_bCabinLeftExitUnit;	//
	bool m_bCabinLight1;	//
	bool m_bCabinLight2;	//
	bool m_bCabinRearRightLightUnit;	//
	bool m_bCabinRightExitUnit;	//
	bool m_bCabinRightFrontLightUnit;	//
	bool m_bCabinUtilityLight1;	//
	bool m_bCabinUtilityLight2;	//
	bool m_bCabinUtilityLight3;	//
	bool m_bDomeLight;	//
	bool m_bFormationLight;	//
	bool m_bForwardLandingLight;	//
	bool m_bHoverLight;	//
	bool m_bLightingPowerUnit1;	//
	bool m_bLightingPowerUnit2;	//
	bool m_bMapLight1;	//
	bool m_bMapLight2;	//
	bool m_bPositionLight1;	//
	bool m_bPositionLight2;	//
	bool m_bRotorTipLight;	//
	bool m_bUtilityLight;	//
	bool m_bCargoHook;	//
	bool m_bCentralClear1;	//
	bool m_bCentralClear2;	//
	bool m_bChaffFlaresSequencingSupplyUnit;	//
	bool m_bFlir;	//
	bool m_bJettisonSys1;	//
	bool m_bJettisonSys2;	//
	bool m_bMissionDataTransferDevice;	//
	bool m_bMissionTacticalComputer1;	//
	bool m_bMissionTacticalComputer2;	//
	bool m_bRescueHoist;	//
};

struct Nh90MalfunctionDamage_LightsMalfunctions
{
	bool m_bLandingLightFailure;	//
	bool m_bSearchLightFailure;	//
	bool m_bAntiCollisionLightFailureLower;	//
	bool m_bAntiCollisionLightFailureUpper;	//
	bool m_bCockpitLightsFailureConsl;	//
	bool m_bCockpitLightsFailureInstr;	//
	bool m_bCockpitLightsFailureOvhd;	//
	bool m_bMapLightFailurePlt;	//
	bool m_bMapLightFailureCplt;	//
	bool m_bMapLightFailureThird;	//
	bool m_bUtilityLightFailure;	//
};

struct Nh90Malfunctions_LightsMalfunctions
{
	bool m_bLandingLightFailure;	//
	bool m_bSearchLightFailure;	//
	bool m_bAntiCollisionLightFailureLower;	//
	bool m_bAntiCollisionLightFailureUpper;	//
	bool m_bCockpitLightsFailureConsl;	//
	bool m_bCockpitLightsFailureInstr;	//
	bool m_bCockpitLightsFailureOvhd;	//
	bool m_bMapLightFailurePlt;	//
	bool m_bMapLightFailureCplt;	//
	bool m_bMapLightFailureThird;	//
	bool m_bUtilityLightFailure;	//
};

struct Nh90MalfunctionDamage_MissionMalfunctions
{
	bool m_bTacticalRadarFailure;	//
	bool m_bFlirTotalFailure;	//
	bool m_bIffFailure;	//
	bool m_bIffUnableToReplyToMode4Interrogations;	//
	bool m_bIffMode4Failure;	//
	bool m_bAutomaticFoldingSystemFailure;	//
	bool m_bSonarReelingMachineKitingFault;	//
	bool m_bSonarReelingMachineFailure;	//
	bool m_bSonarCableMiswrap;	//
	bool m_bSonarReelingMachineUncommandedRaise;	//
	bool m_bSonarReelingMachineRemoteControl;	//
	bool m_bSonarWetEndWetFailure;	//
	bool m_bSonarWetEndSnag;	//
	bool m_bSonarWetEndUplinkLoss;	//
	bool m_bSonarWetEndHungArray;	//
	bool m_bSonarWetEndHotBatteryHotFailure;	//
	bool m_bSonarWetEndBatteryOverpressFailure;	//
	bool m_bSonarReelingMachine28VdcPowerLoss;	//
	bool m_bSonarCips28VdcPowerLoss;	//
	bool m_bSonarCips115VacPowerLoss;	//
	bool m_bSonarCap115VacPowerLoss;	//
	bool m_bLightStoresSystemFailure;	//
	bool m_bStoreManagementSystemFailure;	//
	bool m_bIffInterrogatorFailure;	//
	bool m_bTacticalRadarErpFailure;	//
	bool m_bFlirImageFailure;	//
	bool m_bFlirTurretBindingAzimuth;	//
	bool m_bFlirTurretBindingElevation;	//
	bool m_bFlirGimbalFailure;	//
	bool m_bFlirAutoTrackingTcsFailure;	//
	bool m_bFlirZoomFailure;	//
	bool m_bFlirCoolingFailure;	//
	bool m_bSuonoBuoySystemFailure;	//
	bool m_bSuonobuoyNotReleased;	//
	bool m_bSuonobuoyNoGo;	//
	bool m_bSuonobuoyDegraded;	//
	bool m_bIffMode5Failure;	//
	bool m_bIffUnableToReplyToMode5Interrogations;	//
	bool m_bDmgGeographicProcessorFailure1;	//
	bool m_bDmgGeographicProcessorFailure2;	//
	bool m_bHmsdSymbologyFailure;	//
	bool m_bOwsSystemDegraded;	//
	bool m_bOwsSystemNogo;	//
	bool m_bOwsSystemBusNogo;	//
	bool m_bPilotingFlirTotalFailure;	//
	bool m_bWxrFailure;	//
	bool m_bWxrStabilizationFailure;	//
	bool m_bDeckLockFailure;	//
	bool m_bDataLink11Inoperative;	//
	bool m_bMsguFailure1;	//
	bool m_bMsguFailure2;	//
};

struct Nh90Malfunctions_MissionMalfunctions
{
	bool m_bTacticalRadarFailure;	//
	bool m_bFlirTotalFailure;	//
	bool m_bIffFailure;	//
	bool m_bIffUnableToReplyToMode4Interrogations;	//
	bool m_bIffMode4Failure;	//
	bool m_bAutomaticFoldingSystemFailure;	//
	bool m_bSonarReelingMachineKitingFault;	//
	bool m_bSonarReelingMachineFailure;	//
	bool m_bSonarCableMiswrap;	//
	bool m_bSonarReelingMachineUncommandedRaise;	//
	bool m_bSonarReelingMachineRemoteControl;	//
	bool m_bSonarWetEndWetFailure;	//
	bool m_bSonarWetEndSnag;	//
	bool m_bSonarWetEndUplinkLoss;	//
	bool m_bSonarWetEndHungArray;	//
	bool m_bSonarWetEndHotBatteryHotFailure;	//
	bool m_bSonarWetEndBatteryOverpressFailure;	//
	bool m_bSonarReelingMachine28VdcPowerLoss;	//
	bool m_bSonarCips28VdcPowerLoss;	//
	bool m_bSonarCips115VacPowerLoss;	//
	bool m_bSonarCap115VacPowerLoss;	//
	bool m_bLightStoresSystemFailure;	//
	bool m_bStoreManagementSystemFailure;	//
	bool m_bIffInterrogatorFailure;	//
	bool m_bTacticalRadarErpFailure;	//
	bool m_bFlirImageFailure;	//
	bool m_bFlirTurretBindingAzimuth;	//
	bool m_bFlirTurretBindingElevation;	//
	bool m_bFlirGimbalFailure;	//
	bool m_bFlirAutoTrackingTcsFailure;	//
	bool m_bFlirZoomFailure;	//
	bool m_bFlirCoolingFailure;	//
	bool m_bSuonoBuoySystemFailure;	//
	bool m_bSuonobuoyNotReleased;	//
	bool m_bSuonobuoyNoGo;	//
	bool m_bSuonobuoyDegraded;	//
	bool m_bIffMode5Failure;	//
	bool m_bIffUnableToReplyToMode5Interrogations;	//
	bool m_bDmgGeographicProcessorFailure1;	//
	bool m_bDmgGeographicProcessorFailure2;	//
	bool m_bHmsdSymbologyFailure;	//
	bool m_bOwsSystemDegraded;	//
	bool m_bOwsSystemNogo;	//
	bool m_bOwsSystemBusNogo;	//
	bool m_bPilotingFlirTotalFailure;	//
	bool m_bWxrFailure;	//
	bool m_bWxrStabilizationFailure;	//
	bool m_bDeckLockFailure;	//
	bool m_bDataLink11Inoperative;	//
	bool m_bMsguFailure1;	//
	bool m_bMsguFailure2;	//
};

struct Nh90CircuitBrakers_Navigation
{
	bool m_bAirDataComputer1;	//
	bool m_bAirDataComputer2;	//
	bool m_bDistanceMeasurementComp;	//
	bool m_bDopplerVelocitySensor1;	//
	bool m_bDopplerVelocitySensor2;	//
	bool m_bInertialReferenceSystem1;	//
	bool m_bInertialReferenceSystem2;	//
	bool m_bLeftPitot;	//
	bool m_bMicrowaveLandingSys;	//
	bool m_bRadarAltimeter1;	//
	bool m_bRadarAltimeter2;	//
	bool m_bRightPitot;	//
	bool m_bStbyPitot1;	//
	bool m_bStbyPitot2;	//
};

struct Nh90MalfunctionDamage_NavigationMalfunctions
{
	bool m_bPitotHeadClogged1;	//
	bool m_bPitotHeadClogged2;	//
	bool m_bAdcFailure1;	//
	bool m_bAdcFailure2;	//
	bool m_bDsuFailure;	//
	bool m_bLandingSystemFailure;	//
	bool m_bTacanReceiverFailure;	//
	bool m_bOatProbeFailure1;	//
	bool m_bOatProbeFailure2;	//
	bool m_bGpsFailure1;	//
	bool m_bGpsFailure2;	//
	bool m_bDopplerVelocitySensorDvsFailure;	//
	bool m_bRadarAltimeterFailure;	//
	bool m_bIrsFailure1;	//
	bool m_bIrsFailure2;	//
	bool m_bIrsPitchDiscrepancyDriftInPitch1;	//
	bool m_bIrsPitchDiscrepancyDriftInPitch2;	//
	bool m_bIrsRollDiscrepancyDriftInRoll1;	//
	bool m_bIrsRollDiscrepancyDriftInRoll2;	//
	bool m_bIrsHeadingDiscrepancyDriftInYaw1;	//
	bool m_bIrsHeadingDiscrepancyDriftInYaw2;	//
	bool m_bStaticPortClogged1;	//
	bool m_bStaticPortClogged2;	//
	bool m_bStandbyHorizonFailure;	//
	bool m_bStandbyAltimeterFailure;	//
	bool m_bStandbyAirspeedIndicatorFailure;	//
};

struct Nh90Malfunctions_NavigationMalfunctions
{
	bool m_bPitotHeadClogged1;	//
	bool m_bPitotHeadClogged2;	//
	bool m_bAdcFailure1;	//
	bool m_bAdcFailure2;	//
	bool m_bDsuFailure;	//
	bool m_bLandingSystemFailure;	//
	bool m_bTacanReceiverFailure;	//
	bool m_bOatProbeFailure1;	//
	bool m_bOatProbeFailure2;	//
	bool m_bGpsFailure1;	//
	bool m_bGpsFailure2;	//
	bool m_bDopplerVelocitySensorDvsFailure;	//
	bool m_bRadarAltimeterFailure;	//
	bool m_bIrsFailure1;	//
	bool m_bIrsFailure2;	//
	bool m_bIrsPitchDiscrepancyDriftInPitch1;	//
	bool m_bIrsPitchDiscrepancyDriftInPitch2;	//
	bool m_bIrsRollDiscrepancyDriftInRoll1;	//
	bool m_bIrsRollDiscrepancyDriftInRoll2;	//
	bool m_bIrsHeadingDiscrepancyDriftInYaw1;	//
	bool m_bIrsHeadingDiscrepancyDriftInYaw2;	//
	bool m_bStaticPortClogged1;	//
	bool m_bStaticPortClogged2;	//
	bool m_bStandbyHorizonFailure;	//
	bool m_bStandbyAltimeterFailure;	//
	bool m_bStandbyAirspeedIndicatorFailure;	//
};

struct Nh90Cargo_Payload
{
	bool m_bCargoAttached;	//
	double m_dCargoWeight;	//
	double m_dSlingLength;	//
	double m_dCargoHeightOfTerrain;	//
	double m_dSoilType;	//
	bool m_bCargoEmergencyRelease;	//
	bool m_bExternalCargoCollision;	//
	bool m_bHoistAttached;	//
	double m_dHoistWeight;	//
	bool m_bHoistCableCut;	//
	bool m_bHoistCableUp;	//
	bool m_bHoistCableDown;	//
	bool m_bResetSling;	//
	bool m_bResetHoist;	//
};

struct NH90ModelOutputs_Payload
{
	float m_fRampPosition;	//
	float m_fHatchPosition;	//
	double m_dFuelMassTank1;	//
	double m_dFuelMassTank2;	//
	double m_dFuelMassTank2Bis;	//
	double m_dFuelMassTank3;	//
	double m_dFuelMassTank4;	//
	double m_dFuelMassTank5;	//
	double m_dFuelMassTank6;	//
	double m_dFuelMassTank7;	//
	double m_dFuelMassRightAuxiliaryTank;	//
	double m_dFuelMassLeftAuxiliaryTank;	//
	double m_dOutsideAirTemperature;	//
	double m_dOutsideAmbientPressure;	//
	bool m_bCoPilotWipersOn;	//
	bool m_bPilotWipersOn;	//
	double m_dCgX;	//
	double m_dCgY;	//
};

struct Nh90MalfunctionDamage_RctMalfunctions
{
	bool m_bCableJamming;	//
	bool m_bRearRampFailure;	//
	bool m_bGunJamming;	//
};

struct Nh90Malfunctions_RctMalfunctions
{
	bool m_bCableJamming;	//
	bool m_bRearRampFailure;	//
	bool m_bGunJamming;	//
};

struct Nh90MalfunctionDamage_RoleEquipmentMalfunctions
{
	bool m_bJettisonSystemControllerFailure;	//
	bool m_bCargoHookReleaseFailure;	//
	bool m_bRescueHoistHydraulicOvertemperatureVariable;	//
	float m_fRescueHoistHydraulicOvertemperatureVariableParam1;	//
	bool m_bRescueHoistFailure;	//
};

struct Nh90Malfunctions_RoleEquipmentMalfunctions
{
	bool m_bJettisonSystemControllerFailure;	//
	bool m_bCargoHookReleaseFailure;	//
	bool m_bRescueHoistHydraulicOvertemperatureVariable;	//
	float m_fRescueHoistHydraulicOvertemperatureVariableParam1;	//
	bool m_bRescueHoistFailure;	//
};

struct Nh90Configuration_Sonar
{
	bool m_bEnabled;	//
	unsigned char m_nDispenderSonobuoysSdbu1;	//
	unsigned char m_nDispenderSonobuoysSdbu2;	//
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

struct NH90WeatherRadar_Status
{
	bool m_bKeepAlive;	//
	bool m_bAPPStatus;	//
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

struct NH90WeatherRadar_StreamState
{
	char m_cLineStatus;	//
	char m_cCount;	//
	///DEF_ARRAY(m_nBuffer, unsigned int, 64);	//
	unsigned short m_nNotificCounter;	//
};

struct Nh90CircuitBrakers_TransmissionAndRotorSystem
{
	bool m_bChipDetector;	//
	bool m_bRotorBrakeControl;	//
	bool m_bRotorBrakePwr;	//
};

struct Nh90MalfunctionDamage_TransmissionMalfunctions
{
	bool m_bRotorBrakeFailure;	//
	bool m_bCaliperJamming;	//
	bool m_bRotorBrakeAbnormalTemperature;	//
	bool m_bRotorBrakeAbnormalPressure;	//
	bool m_bLossOfTailRotorThrust;	//
	bool m_bMgbLowOilPressureMgbp;	//
	bool m_bRagbLowOilPressureRagbp;	//
	bool m_bMgbChipDetection;	//
	bool m_bMgbInputModuleChipDetection1;	//
	bool m_bMgbInputModuleChipDetection2;	//
	bool m_bRagbChipDetection;	//
	bool m_bIgbChipDetection;	//
	bool m_bTgbChipDetection;	//
	bool m_bChipBurningSystemFailure;	//
	bool m_bMgbHighOilTemperature;	//
	bool m_bMgbInputModuleHighOilTemperature1;	//
	bool m_bMgbInputModuleHighOilTemperature2;	//
	bool m_bTgbHighOilTemperature;	//
	bool m_bIgbHighOilTemperature;	//
	bool m_bRagbHighOilTemperature;	//
};

struct Nh90Malfunctions_TransmissionMalfunctions
{
	bool m_bRotorBrakeFailure;	//
	bool m_bCaliperJamming;	//
	bool m_bRotorBrakeAbnormalTemperature;	//
	bool m_bRotorBrakeAbnormalPressure;	//
	bool m_bLossOfTailRotorThrust;	//
	bool m_bMgbLowOilPressureMgbp;	//
	bool m_bRagbLowOilPressureRagbp;	//
	bool m_bMgbChipDetection;	//
	bool m_bMgbInputModuleChipDetection1;	//
	bool m_bMgbInputModuleChipDetection2;	//
	bool m_bRagbChipDetection;	//
	bool m_bIgbChipDetection;	//
	bool m_bTgbChipDetection;	//
	bool m_bChipBurningSystemFailure;	//
	bool m_bMgbHighOilTemperature;	//
	bool m_bMgbInputModuleHighOilTemperature1;	//
	bool m_bMgbInputModuleHighOilTemperature2;	//
	bool m_bTgbHighOilTemperature;	//
	bool m_bIgbHighOilTemperature;	//
	bool m_bRagbHighOilTemperature;	//
};
//
//struct NH90WeatherRadar_VDUWXRS
//{
//	char m_cSwitchingCommand[5];	//
//	DEF_ARRAY(m_cConfigurationReference, enmNH90WeatherRadar_ConfigurationReferenceType, 5);	//
//	char m_cFreezingCommand[5];	//
//	char m_cBlackImage[5];	//
//};

struct NH90WeatherRadar_WeatherState
{
	unsigned char m_nIsolatedCloudIdentifier[10];	//
	DEF_ARRAY(m_fIsolatedCloudRadius, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudLatitudeWGS84, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudLongitudeWGS84, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudVisibility, float, 10);	//
	unsigned char m_nIsolatedCloudMotionMode[10];	//
	DEF_ARRAY(m_fIsolatedCloudTopAltitudeAMSL, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudBottomAltitudeAMSL, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudTurbulenceIntensityperc, float, 10);	//
	DEF_ARRAY(m_fIsolatedCloudPrecipitationIntensity, float, 10);	//
	unsigned char m_IsolatedCloudPrecipitationType[10];	//
};

struct NH90WeatherRadar_WXRStatus
{
	char m_nCB1Status;	//
	char m_nCB2Status;	//
	bool m_bMissionWxrFailure;	//
	bool m_bMissionWxrStabilizationFailure;	//
	bool m_WxrSwitch;	//
};

struct Nh90Configuration_Payload
{
	double m_dTotalWeight;	//
	bool m_bCgEnable;	//
	double m_dCgX;	//
	double m_dCgY;	//
	bool m_bGrossWeightEnabled;	//
	double m_dGrossWeight;	//
	bool m_bPayloadEnabled;	//
	double m_dPayloadWeight;	//
	unsigned int m_nChaffsAndFlaresDispenserModule1;	//
	unsigned int m_nChaffsAndFlaresDispenserModule2;	//
	unsigned int m_nChaffsAndFlaresDispenserModule3;	//
	unsigned int m_nChaffsAndFlaresDispenserModule4;	//
	bool m_bChaffAndFlaresEnabled;	//
	unsigned int m_nHeavyStoreCarrierLeft;	//
	unsigned int m_nHeavyStoreCarrierRight;	//
	bool m_bHeavyStoreCarrierEnabled;	//
	bool m_bMachineGunsLeftEnabled;	//
	bool m_bMachineGunsRightEnabled;	//
	unsigned int m_nAmmunitionsOnMachineGunLeft;	//
	unsigned int m_nAmmunitionsOnMachineGunRight;	//
	unsigned int m_nRescueHoistWeight;	//
	Nh90Configuration_CargoZone m_cCargoZoneA;	//
	Nh90Configuration_CargoZone m_cCargoZoneB;	//
	Nh90Configuration_CargoZone m_cCargoZoneC;	//
	Nh90Configuration_CargoZone m_cCargoZoneD;	//
	Nh90Configuration_CargoZone m_cCargoZoneE;	//
	Nh90Configuration_CargoZone m_cCargoZoneF;	//
	Nh90Configuration_CargoZone m_cCargoZoneG;	//
	Nh90Configuration_CargoZone m_cCargoZoneH;	//
	Nh90Configuration_CargoZone m_cCargoZoneI;	//
	Nh90Configuration_CargoZone m_cCargoZoneJ;	//
	Nh90Configuration_CargoZone m_cCargoZoneK;	//
	Nh90Configuration_CargoZoneEnable m_cZonesEnabled;	//
	Nh90Configuration_ExternalAuxiliaryFuelTanks m_cExternalAuxiliaryFuelTanks;	//
	Nh90Configuration_Fuel m_cFuel;	//
	unsigned int m_nCargoHookWeight;	//
	Nh90Configuration_Sonar m_cSonar;	//
	Nh90Configuration_FloatationDevices m_cFloatationDevices;	//
};

struct NH90WeatherRadar_PayloadIn
{
	NH90WeatherRadar_WXRStatus m_cWXRStatus;	//
	NH90WeatherRadar_StreamState m_cABSMTC1AR250;	//
	NH90WeatherRadar_StreamState m_cABSMTC1AR251;	//
	NH90WeatherRadar_VDUWXRS m_cVBUWXRS;	//
};

struct NH90WeatherRadar_PayloadOut
{
	NH90WeatherRadar_StatusIndicators m_cPilot;	//
	NH90WeatherRadar_StatusIndicators m_cCopilot;	//
	NH90WeatherRadar_StreamState m_cABSWXRAR252;	//
	NH90WeatherRadar_StreamState m_cABSWXRAR253;	//
};

struct NH90WeatherRadar_WeatherRadar
{
	NH90WeatherRadar_StatusIndicators m_cPilot;	//
	NH90WeatherRadar_StatusIndicators m_cCopilot;	//
};

struct NH90WeatherRadar_WXR
{
	NH90WeatherRadar_StreamState m_cAR252;	//
	NH90WeatherRadar_StreamState m_cAR253;	//
};


#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(pop)
#endif

#endif // ELM_INFO__OWNSHIPNH90__H
