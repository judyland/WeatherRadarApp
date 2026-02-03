//#include "magUtils/magShader.h"
#include "magOgl/magOglShader.h"
#include "whrdrPosition.h"
#include "whrdrAntenna.h"

namespace whrdr
{
	class Texture
	{
	public:
		void bind();
		void download(int uiRow, const void* pixels);
	private:
		uint32_t m_unTexId = 0;

	};

	class Channel : public Position
	{
	public:
		Channel();
		virtual ~Channel();
		void draw();

		// meters
		double getScanRange() const {
			return m_pAntenna->getScanRange();
		}

		// meters
		void setScanRange(double val) {
			m_pAntenna->setScanRange(val);
		}

		void setStartAzimuth(float az) {
			m_pAntenna->setStartAzimuth(az);
		}

		void setSweep(float sw) {
			m_pAntenna->setSweep(sw);
		}
		void setHeading(double dHeading) {
			m_dHeading = dHeading;
		}
		double getHeading() const {
			return m_dHeading;
		}

	private:

		bool createShaders();

		double m_dHeading;
		std::unique_ptr<Antenna>	m_pAntenna;
		Texture						m_cTexture;
		std::unique_ptr<float[]>	m_vVertices;
		int							m_VtxArraySize = 0;

		std::string					m_sFragmentShaderName;
		std::string					m_sVertexShaderName;

		bool						m_bFirstDraw = true;

		magOglShaderProgram::SPtr	m_pShaderProgram;

		//magShader	m_pFragmentShader;
		//magRefMemPtr<magShader> m_pVertexShader;
	};

}