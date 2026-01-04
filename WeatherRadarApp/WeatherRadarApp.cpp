#include <Windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <memory>
#include <thread>
#include <chrono>

#include "magEnvVarParam.h"
#include "whrdrAntenna.h"
#include "whrdrChannel.h"
#include "whrdrComm.h"
#include "WeatherRadarApp.h"
#include "WeatherSymbols.h"
#include "magFrameRateLimiter.h"

using namespace std;
using namespace whrdr;

static int _windowSizeX = 800;
static int _windowSizeY = 800;
static int _windowPosX = 0;
static int _windowPosY = 0;

inline double deg2rad(double deg)
{
	return deg / 180. * M_PI;
}

unique_ptr<whrdr::Channel>	theChannel;
unique_ptr<whrdr::Comm>		theComm;
magFrameRateLimiter			theFrameRateLimiter;

void printOGLError(const char* msg);

void onReshapeFunc(int w, int h)
{
	glutPostRedisplay();
}

void onDrawFunc()
{
	theFrameRateLimiter.sleepForFrameRate();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glOrtho(-1, 1, 0.8, -0.2, -1, 1);
	//glTranslatef(0, -1, 0);
	theComm->update(theChannel.get());
	//printOGLError("After Update");
	float azimuth = getRadarData().pAntenna->getCurAngle();
	{
		theChannel->draw();
		draw_antenna_angle(azimuth);
	}
	//printOGLError("After Draw");
	//std::this_thread::sleep_for(std::chrono::milliseconds(33));

#if 0
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glColor3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(0.8f, 0.2f);
	glVertex2f(0.8f, 0.8f);
	glVertex2f(0.2f, 0.8f);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
#endif

	glutSwapBuffers();

}

void setRangescale(double scale)
{
	auto pChan = whrdr::getRadarData().pChannel;
	if (pChan)
	{
		double r = pChan->getScanRange() * scale;
		pChan->setScanRange(r);
	}
}

void changeAntennaElevation(float de)
{
	auto pAnt = whrdr::getRadarData().pAntenna;
	if (pAnt)
	{
		float e = pAnt->getElevation() + de;
		pAnt->setElevation(e);
	}
}

void onKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		//throw 0;
		//exit(1);
		break;

	case 'a':
		break;

	case 'e':
		changeAntennaElevation(0.1f);
		break;

	case 'E':
		changeAntennaElevation(-0.1f);
		break;

	case 'r':
		setRangescale(2.0);
		break;

	case 'R':
		setRangescale(0.5);
		break;

	}
}

void onMouseMotionFunc(int x, int y)
{
	glutPostRedisplay();
}

void pick(long sx, long sy, double* wx, double* wy)
{
	GLint viewport[4];
	GLdouble mvmatrix[16];
	GLdouble projmatrix[16];
	GLdouble dx, dy, dz;
	GLint realy;

	glGetIntegerv(GL_VIEWPORT, viewport);
	//printGlError();
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	//printGlError();
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
	//printGlError();
	realy = viewport[3] - sy;

	gluUnProject((GLdouble)sx, (GLdouble)realy, 0.0,
		mvmatrix, projmatrix, viewport, &dx, &dy, &dz);
	//printf("world coordinates = %f %f %f\n", dx, dy, dz);

	*wx = dx;
	*wy = dy;
}


void onMouseEventFunc(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		double wx, wy;
		pick(x, y, &wx, &wy);
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{

	}

	glutPostRedisplay();
}

void onIdleFunc()
{
	glutPostRedisplay();
}

void onSpecialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		changeAntennaElevation(-0.1f);
		break;

	case GLUT_KEY_UP:
		changeAntennaElevation(0.1f);
		break;

	case GLUT_KEY_LEFT:
		break;

	case GLUT_KEY_RIGHT:
		break;

	case GLUT_KEY_PAGE_UP:
		break;

	case GLUT_KEY_PAGE_DOWN:
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

//void createObject(qryIsectDB::UniquePtr& pDB, uint32_t objId, 
//	qryIsectDB::ModelPtr& pModel, 
//	qryIsectTranslationParams& cParams)
//{
//	auto pObj = pDB->createObject(objId, pModel, cParams);
//	if (pObj != nullptr)
//	{
//		whrdr::getRadarData().vActiveAreas.push_back(pObj); // pModel);
//	}
//}

void loadDatabase()
{
	//qryIsectDB::UniquePtr pDB = std::make_unique<qryIsectDB>();
	//string qryName = "";

	//qryIsectTranslationParams cParams;

	//cParams.transx = 0; // 1500;
	//cParams.transy = 1000; // 1500;
	//cParams.transz = 2000;

	//cParams.scalex = 30000;
	//cParams.scaley = 30000;
	//cParams.scalez = 3000;


	//auto pModel = pDB->loadModel("C:\\work\\Weather\\SimCore_30_3_25\\IG\\Data\\circle_area_shape_no_sw.flt"); // , cParams);

	////uint32_t objId = 1;
	//createObject(pDB, 1, pModel, cParams);


	//cParams.transx = 25000; // 1500;
	//cParams.transy = 5000; // 1500;
	//cParams.transz = 2000;

	//cParams.scalex = 24000;
	//cParams.scaley = 36000;
	//cParams.scalez = 4000;

	//cParams.rotatez = 30;

	////createObject(pDB, 2, pModel, cParams);

	//cParams.transx = -25000; // 1500;
	//cParams.transy = 5000; // 1500;
	//cParams.transz = 2000;

	//cParams.scalex = 14000;
	//cParams.scaley = 32000;
	//cParams.scalez = 4000;

	//cParams.rotatez = 30;

	////createObject(pDB, 3, pModel, cParams);


	//whrdr::getRadarData().pDatabase = std::move(pDB);
}

void init()
{
	theComm = make_unique<whrdr::Comm>();
	theComm->initMMP();
	theChannel = make_unique<whrdr::Channel>();
	theChannel->setStartAzimuth(300);
	theChannel->setSweep(120);

	loadDatabase();
	theFrameRateLimiter.setFrameRate(30);
}

void printOGLError(const char* msg)
{
	GLenum errCode;

	if ((errCode = glGetError()) != GL_NO_ERROR)
	{
		const GLubyte* errString = gluErrorString(errCode);
		if (msg)
			printf("Open GL Error %s: %s\n", msg, reinterpret_cast<const char*>(errString));
		else
			printf("Open GL Error: %s\n", reinterpret_cast<const char*>(errString));
	}
}


whrdr::RadarData& whrdr::getRadarData()
{
	static RadarData theRdrData;
	return theRdrData;
}

/**
 * @brief Returns the path to the directory containing weather data files.
 *
 * This function checks if the static path variable is empty. If it is, it attempts to retrieve
 * the path from the environment variable "WEATHER_RADAR_CHANNEL_DATA_PATH". If the environment
 * variable is not set or the path does not exist, it falls back to a default path.
 * The resolved path is cached for subsequent calls.
 *
 * @return const Path& Reference to the path of the weather data files directory.
 */
const Path& whrdr::getWeatherDataFilesPath()
{
	static Path s_path;
	if (s_path.empty())
	{
		const Path defaultPath = R"(C:\work\Weather\SimCore_30_3_25\IG\Data\WeatherData)";
		magEnvVarParam envVarParam("WEATHER_RADAR_CHANNEL_DATA_PATH", defaultPath);
		s_path = envVarParam.value();
		if (isFileExists(s_path))
		{
			std::cout << "Weather data files path: " << s_path.string() << '\n';
		}
		else
		{
			std::cout << "Weather data files path from environment variable WEATHER_RADAR_CHANNEL_DATA_PATH does not exist: "
				<< s_path.string() << "\nUsing default path: " << defaultPath.string() << std::endl;
			s_path = defaultPath;
		}
	}

	return s_path;
}

Path whrdr::getWeatherDataFilePath(const Path& filename)
{
	auto p = getWeatherDataFilesPath() / filename;
	if (!isFileExists(p))
	{
		string errMsg = "Weather data file does not exist: " + p.string();
		cout << errMsg << '\n';
		//throw std::runtime_error(errMsg);
		return {};
	}
	return p;
}


void main(int argc, char** argv)
{
	

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(_windowSizeX, _windowSizeY);
	glutInitWindowPosition(_windowPosX, _windowPosY);

	glutCreateWindow("Simple Glut");

	glutReshapeFunc(onReshapeFunc);
	glutDisplayFunc(onDrawFunc);
	glutKeyboardFunc(onKeyboardFunc);
	glutMotionFunc(onMouseMotionFunc);
	glutMouseFunc(onMouseEventFunc);
	glutSpecialFunc(onSpecialFunc);
	glutIdleFunc(onIdleFunc);

	glewInit();
	init();

	glutMainLoop();

}
