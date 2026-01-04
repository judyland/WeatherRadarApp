#pragma once

#include <memory>
#include <functional>

class magCoordSysConverter;

namespace whrdr
{
	struct PosLLA
	{
		PosLLA() {}
		PosLLA(double lon, double lat, double alt=0) : lon(lon), lat(lat), alt(alt) {}
		double lon{}; // decimal degrees
		double lat{}; // decimal degrees
		double alt{}; // meters
	};

	struct PosXYZ
	{
		PosXYZ() {}
		PosXYZ(double x, double y, double z=0) : x(x), y(y), z(z) {}
		double x{}; // meters
		double y{}; // meters
		double z{}; // meters
	};

	struct PosXYf
	{
		PosXYf() {}
		PosXYf(float x, float y) : x(x), y(y) {}
		float x{}; // meters
		float y{}; // meters
	};

	class Position;
	using OnUpdatePositionFunc = std::function<void(const Position&)>;

	class Position
	{
	public:
		Position();
		virtual ~Position();

		// Getters
		const PosLLA& getPositionLLA() const {
			return m_cPosLLA;
		}

		const PosXYZ& getPositionXYZ() const {
			return m_cPosXYZ;
		}

		bool isValid() const {
			return m_bValid;
		}

		// Setters
		void setPositionLLA(const PosLLA& posLLA);
		void setValid(bool valid) {
			m_bValid = valid;
		}

		const OnUpdatePositionFunc& getOnUpdateFunc() const {
			return m_fnOnUpdate;
		}

		void setnOnUpdateFunc(OnUpdatePositionFunc val) {
			m_fnOnUpdate = val;
		}


		static void SetProjectionCenter(double lon, double lat);

	protected:
		OnUpdatePositionFunc m_fnOnUpdate;

	private:
		PosLLA	m_cPosLLA;
		PosXYZ	m_cPosXYZ;
		bool	m_bValid = false;


		void setPositionXYZ(const PosXYZ& posXYZ) {
			m_cPosXYZ = posXYZ;
		}

		static std::unique_ptr<magCoordSysConverter> s_pCsConverter;
	};
}

