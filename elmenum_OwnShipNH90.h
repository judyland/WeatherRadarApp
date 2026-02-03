//-----------------------------------------------------------------------------
// File Name:		Export/elmenum.h
// Project Name:	OwnShipNH90
//-----------------------------------------------------------------------------
#ifndef ELM_ENUM__OWNSHIPNH90__H
#define ELM_ENUM__OWNSHIPNH90__H

#if defined(_MSC_VER) && !defined(__KLOCWORK__)
#	pragma once
#endif


#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(push, 1)
#endif

// Enumerators

enum enmNh90Cargo_ActivationType
{
	enmNh90Cargo_Activation__NotActive = 0,
	enmNh90Cargo_Activation__Active = 1
};

enum enmNh90Cargo_MessageTypeType
{
	enmNh90Cargo_MessageType__CargoMessageNh90 = 30001
};

enum enmNh90Cargo_PowerUpType
{
	enmNh90Cargo_PowerUp__Off = 0,
	enmNh90Cargo_PowerUp__On = 1
};

enum enmNh90CircuitBrakers_ActivationType
{
	enmNh90CircuitBrakers_Activation__NotActive = 0,
	enmNh90CircuitBrakers_Activation__Active = 1
};

enum enmNh90CircuitBrakers_H2HMessageIdentifierType
{
	enmNh90CircuitBrakers_H2HMessageIdentifier__CircuitBreakerMessage = 30504
};

enum enmNh90CircuitBrakers_PowerUpType
{
	enmNh90CircuitBrakers_PowerUp__Off = 0,
	enmNh90CircuitBrakers_PowerUp__On = 1
};

enum enmNh90Configuration_ActivationType
{
	enmNh90Configuration_Activation__NotActive = 0,
	enmNh90Configuration_Activation__Active = 1
};

enum enmNh90Configuration_MessageTypeType
{
	enmNh90Configuration_MessageType__ConfigurationMessageNh90 = 30002
};

enum enmNh90Configuration_PowerUpType
{
	enmNh90Configuration_PowerUp__Off = 0,
	enmNh90Configuration_PowerUp__On = 1
};

enum enmNh90MalfunctionDamage_ActivationType
{
	enmNh90MalfunctionDamage_Activation__NotActive = 0,
	enmNh90MalfunctionDamage_Activation__Active = 1
};

enum enmNh90MalfunctionDamage_H2HMessageIdentifierType
{
	enmNh90MalfunctionDamage_H2HMessageIdentifier__MalfunctionsDamageMessage = 31510
};

enum enmNh90MalfunctionDamage_PowerUpType
{
	enmNh90MalfunctionDamage_PowerUp__Off = 0,
	enmNh90MalfunctionDamage_PowerUp__On = 1
};

enum enmNh90Malfunctions_ActivationType
{
	enmNh90Malfunctions_Activation__NotActive = 0,
	enmNh90Malfunctions_Activation__Active = 1
};

enum enmNh90Malfunctions_H2HMessageIdentifierType
{
	enmNh90Malfunctions_H2HMessageIdentifier__MalfunctionRequestMessage = 30501
};

enum enmNh90Malfunctions_PowerUpType
{
	enmNh90Malfunctions_PowerUp__Off = 0,
	enmNh90Malfunctions_PowerUp__On = 1
};

enum enmNH90ModelOutputs_ActivationType
{
	enmNH90ModelOutputs_Activation__NotActive = 0,
	enmNH90ModelOutputs_Activation__Active = 1
};

enum enmNH90ModelOutputs_MessageTypeType
{
	enmNH90ModelOutputs_MessageType__ModelOutputsMessageNh90 = 31507
};

enum enmNH90ModelOutputs_PowerUpType
{
	enmNH90ModelOutputs_PowerUp__Off = 0,
	enmNH90ModelOutputs_PowerUp__On = 1
};

enum enmNH90WeatherRadar_ActivationType
{
	enmNH90WeatherRadar_Activation__NotActive = 0,
	enmNH90WeatherRadar_Activation__Active = 1
};

enum enmNH90WeatherRadar_ConfigurationReferenceType
{
	enmNH90WeatherRadar_ConfigurationReference__NoWXRImage = 0,
	enmNH90WeatherRadar_ConfigurationReference__WXROnFSCTFormat = 1,
	enmNH90WeatherRadar_ConfigurationReference__WXROnNSCT = 3,
	enmNH90WeatherRadar_ConfigurationReference__WXRonNROS = 2,
	enmNH90WeatherRadar_ConfigurationReference__WXROnTWXR = 4
};

enum enmNH90WeatherRadar_MessageTypeType
{
	enmNH90WeatherRadar_MessageType__WeatherRadarOutMessageNh90 = 30503,
	enmNH90WeatherRadar_MessageType__WeatherRadarInMessageNh90 = 30504
};

enum enmNH90WeatherRadar_PowerUpType
{
	enmNH90WeatherRadar_PowerUp__Off = 0,
	enmNH90WeatherRadar_PowerUp__On = 1
};


#if defined(_MSC_VER) || defined(__linux__)
#	pragma pack(pop)
#endif

#endif // ELM_ENUM__OWNSHIPNH90__H
