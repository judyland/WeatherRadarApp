#include "magCoordSysConverter.h"
#include "whrdrPosition.h"

using namespace whrdr;

using CsConvPtr = std::unique_ptr<magCoordSysConverter>;
CsConvPtr Position::s_pCsConverter;


CsConvPtr CreateFlatEarthProj(double lon, double lat)
{
	auto p = std::make_unique<magFlatEarthConverter>();
	p->setOrigin(lon, lat);
	return p;
}

Position::Position()
{
}

Position::~Position()
{
}

// Setters

void Position::setPositionLLA(const PosLLA& posLLA)
{
	if (posLLA.lat == 0 || posLLA.lon == 0)
	{
		m_bValid = false;
		return;
	}
	m_cPosLLA = posLLA;
	if (s_pCsConverter == nullptr)
	{
		s_pCsConverter = CreateFlatEarthProj(posLLA.lon, posLLA.lat);
	}
	
	s_pCsConverter->geoPosToProjection(posLLA.lon, posLLA.lat, &(m_cPosXYZ.x), &(m_cPosXYZ.y));
	m_cPosXYZ.z = posLLA.alt;
	m_bValid = true;

	if (m_fnOnUpdate)
	{
		m_fnOnUpdate(*this);
	}
}



void Position::SetProjectionCenter(double lon, double lat)
{
	s_pCsConverter = CreateFlatEarthProj(lon, lat);

	// for future optimization, don't make new projection when same as the current 
	//if (s_pCsConverter == nullptr)
	//{
	//	s_pCsConverter = CreateFlatEarthProj(lon, lat);
	//}
	//else
	//{

	//}
}


