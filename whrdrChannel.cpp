
#include <iostream>
#include <Windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "magUtils/magOglUtils.h"
//#include "OpenGL/GL/glext.h"
#include "whrdrChannel.h"
#include "WeatherRadarApp.h"

using namespace std;
using namespace whrdr;

void printOGLError(const char* msg);

Channel::Channel()
{
	m_pAntenna = std::make_unique<Antenna>();
	m_fnOnUpdate = [&](const Position& pos) {
		Position* antPos = m_pAntenna.get();
		*antPos = pos;
		};
	getRadarData().pChannel = this;

	Path configFile = "weatherRDR.fs";
	configFile = getWeatherDataFilePath(configFile);

	m_sFragmentShaderName = configFile.string();

	configFile = "weatherRDR.vs";
	configFile = getWeatherDataFilePath(configFile);

	m_sVertexShaderName = configFile.string();
}

Channel::~Channel()
{
}

inline void setVtx(float*& p, float x, float y, float u, float v)
{
	*(p++) = x;
	*(p++) = y;
	*(p++) = u;
	*(p++) = v;
}

void Channel::draw()
{
	if (m_bFirstDraw)
	{
		try
		{
			createShaders();
			m_pAntenna->startUpdateThread();
		}
		catch (const std::exception& e)
		{
			cout << "Error: Channel::draw() - " << e.what() << endl;
		}
		m_bFirstDraw = false;
	}


	auto updateLock = m_pAntenna->getUpdateMutexLock();
	auto center = getPositionXYZ();
	double dScanRange = getScanRange();
	double dHeading = getHeading();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity(); 
	
	glOrtho(-dScanRange, dScanRange, -dScanRange * 0.3, dScanRange * 1.7, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glRotated(dHeading, 0, 0, 1);
	glColor3f(1, 1, 1);

	const auto& geomBeans = m_pAntenna->getBeamsGeomArray();
	auto& infoBeans = m_pAntenna->getBeamsInfoArray();

	glEnable(GL_TEXTURE_2D);
	// Set the texture unit
	glActiveTexture(GL_TEXTURE0);  // Activate texture unit 0
	m_cTexture.bind();


	for (int i = 0; i < NumOfScanBeams; ++i)
	{
		auto& bs = infoBeans[i].cBitSet;
		if (bs[BEAM_VALID] && !bs[BEAM_DOWNLOADED])
		{
			m_cTexture.download(i, infoBeans[i].aPixelsf.data());
			bs[BEAM_DOWNLOADED] = true;
		}
	}

	GLhandleARB shaderProgram = 0;
	if (m_pShaderProgram)
	{
		shaderProgram = m_pShaderProgram->getHandle();
		glUseProgram(shaderProgram);
		GLint loc = glGetUniformLocation(shaderProgram, "sampler0"); // GetUniformLocation(szName);
		if (loc != -1) 
		{
			glUniform1i(loc, 0);  // Use texture unit 0
		}
		
	}


	float fRange = (float)getScanRange();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(fRange, fRange, 1);
	// draw with immidiate mode
	glBegin(GL_TRIANGLES);
	constexpr float texAzRes = 1.0f / static_cast<float>(NumOfScanBeams);
	for (size_t i = 0; i < NumOfScanBeams; ++i)
	{
		float v1 = i * texAzRes;
		float v2 = v1 + texAzRes;

		const auto& rBeam = geomBeans[i];
		glTexCoord2f(0, v1);
		glVertex2f(0, 0);

		glTexCoord2f(1, v1);
		glVertex2f(rBeam.cP2.x, rBeam.cP2.y);

		glTexCoord2f(1, v2);
		glVertex2f(rBeam.cP1.x, rBeam.cP1.y);
	}
	glEnd();
	glPopMatrix();


	// prepare the vtx array

	//if (m_vVertices == nullptr)
	//{
	//	constexpr size_t vtxElementSize = 12 * sizeof(float); // 3 * (vtx(2) + texCoord(2)) floats
	//	constexpr size_t vtxArraySize = vtxElementSize * NumOfScanBeams;
	//	m_vVertices = std::make_unique<float[]>(vtxArraySize);
	//	m_VtxArraySize = (int)vtxArraySize;
	//	constexpr float texAzRes = 1.0f / static_cast<float>(NumOfScanBeams);
	//	float* pb = m_vVertices.get();
	//	float* p = m_vVertices.get();
	//	for (size_t i = 0; i < NumOfScanBeams; ++i)
	//	{
	//		float v1 = i * texAzRes;
	//		float v2 = v1 + texAzRes;
	//		const auto& rBeam = geomBeans[i];
	//		setVtx(p, (float)center.x, (float)center.y, 0, v1);
	//		setVtx(p, rBeam.cP2.x, rBeam.cP2.y, 1, v1);
	//		setVtx(p, rBeam.cP1.x, rBeam.cP1.y, 1, v2);
	//	}
	//}

	// draw the vtx array

	//float* p = m_vVertices.get();
	//glBegin(GL_TRIANGLES);
	//for (size_t i = 0; i < NumOfScanBeams; ++i)
	//{
	//	glTexCoord2f(p[2], p[3]);
	//	glVertex2f(p[0], p[1]);
	//	p += 4;

	//	glTexCoord2f(p[2], p[3]);
	//	glVertex2f(p[0], p[1]);
	//	p += 4;

	//	glTexCoord2f(p[2], p[3]);
	//	glVertex2f(p[0], p[1]);
	//	p += 4;

	//}
	//glEnd();


	//glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);

	//GLsizei stride = 4 * sizeof(float);
	//glVertexPointer(2, GL_FLOAT, stride, m_vVertices.get()); // BUFFER_OFFSET(0));
	//glTexCoordPointer(2, GL_FLOAT, stride, m_vVertices.get() + 8); //BUFFER_OFFSET(8));
	//glDrawArrays(GL_TRIANGLES, 0, m_VtxArraySize);

	//glColorPointer(3, GL_FLOAT, stride, BUFFER_OFFSET(16));

	//glDisableClientState(GL_VERTEX_ARRAY);
	//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glDisableClientState(GL_COLOR_ARRAY);


	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	if (m_pShaderProgram)
	{
		m_pShaderProgram->useProgramObject(false);
	}
}

bool whrdr::Channel::createShaders()
{
	auto pVtxShader = magOglShader::CreateVertexShader();
	bool res0 = pVtxShader->loadFromFile(m_sVertexShaderName.c_str());
	if (!res0)
	{
		return false;
	}

	auto pFragShader = magOglShader::CreateFragmentShader();
	bool res1 = pFragShader->loadFromFile(m_sFragmentShaderName.c_str());
	if (!res1)
	{
		return false;
	}

	m_pShaderProgram = std::make_shared<magOglShaderProgram>();
	m_pShaderProgram->attachShaders(pFragShader, pVtxShader);

	return true;
}

void Texture::bind()
{
	if (m_unTexId == 0)	
	{
		glGenTextures(1, &m_unTexId);
		glBindTexture(GL_TEXTURE_2D, m_unTexId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

#ifdef PIXEL_IS_RGB
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, NumOfBeamSamples, NumOfScanBeams,
			0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
#else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, NumOfBeamSamples, NumOfScanBeams,
			0, GL_LUMINANCE, GL_UNSIGNED_BYTE, nullptr);

#endif
	}
	else 
	{
		glBindTexture(GL_TEXTURE_2D, m_unTexId);
	}
}

void Texture::download(int uiRow, const void* pixels)
{
	if (m_unTexId == 0)
	{
		bind();
	}
	//printOGLError("before subtex");
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, uiRow, NumOfBeamSamples, 1, GL_LUMINANCE,
		GL_UNSIGNED_BYTE, pixels);
	//printOGLError("after subtex");
}
