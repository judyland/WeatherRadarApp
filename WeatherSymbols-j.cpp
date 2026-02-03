#include <Windows.h>
#include <GL/glew.h>
#include <GL/gl.h>d
#include <cmath>
#include "magOgl/magOglMatrix.h"
#include "magOgl/magOglVbo.h"

#include "WeatherRadarApp.h"
#include "WeatherSymbols.h"
#include "whrdrAntenna.h"

using namespace magOGL;

void drawAzimuth(float angle)
{
	ProjectionMat prjMat(Matrix::Push);
	ModelViewMat mvMat(Matrix::Push);

	glDisable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glRotatef(-angle, 0, 0, 1);
	float len = 0.025f;
	glTranslatef(0, 1.0f - len, 0);


	glBegin(GL_LINES);
	glVertex2f(-len, 0);
	glVertex2f(len, 0);
	glVertex2f(0, -len);
	glVertex2f(0, len);
	glEnd();

	//glColor3f(1, 1, 1);
//	drawArcs(50, 0, 280, 160, 0, 0.3);

}

//void DrawCircle(float cx, float cy, float r, int num_segments)
//{
//	glBegin(GL_LINE_LOOP);
//	for (int ii = 0; ii < num_segments; ii++)
//	{
//		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
//
//		float x = r * cosf(theta);//calculate the x component
//		float y = r * sinf(theta);//calculate the y component
//
//		glVertex2f(x + cx, y + cy);//output vertex
//
//	}
//	glEnd();
//}
void drawCircle(float x, float y, float r, float inner, int slices, int loops)
{
	static GLUquadricObj* quadObj = NULL;
	if (!quadObj)
		quadObj = gluNewQuadric();

	glPushMatrix();
	gluQuadricDrawStyle(quadObj, GLU_SILHOUETTE);
	glTranslatef(x, y, 0.0);
	gluDisk(quadObj, (GLdouble)inner, (GLdouble)r, (GLint)slices, (GLint)loops);
	glPopMatrix();
}
void drawArc(float x, float y, float r, float inner, int slices, int loops, int start, int sweep)
{
	static GLUquadricObj* quadObj = NULL;
	if (!quadObj)
		quadObj = gluNewQuadric();

	glPushMatrix();
	gluQuadricDrawStyle(quadObj, GLU_SILHOUETTE);
	glTranslatef(x, y, 0.0);
	gluPartialDisk(quadObj, (GLdouble)inner, (GLdouble)r,
		(GLint)slices, (GLint)loops, (GLdouble)start, (GLdouble)sweep);
	glPopMatrix();
}

void   drawArcs(float cx, float cy, float start, float sweep, int full, float color)
{
	int		nof_steps, i;
	float	max_range;
	float	arc_step;
	float	range, /*rmin,*/ arc_color;
	/*ULONG	mk_int;*/


	//if (CConv::MeterToNauticalMile(static_cast<double>(pGmapParameters->m_iMaxRange)) < 15)
	//	nof_steps = 2;
	//else
		nof_steps = 4;

		max_range = 40; //(float)GMapSizeWorldToScreen((long)pGmapParameters->m_iMaxRange, pGmapWArea);
	arc_step = max_range / nof_steps;

	/*mk_int = pGmapParameters->m_iMkInt;*/
	/* when target is out fcr fov and only the arcs are drawn
	the arcs should be in the highest intensity
	regardless of the cm */
	arc_color = 1.0;/*GMapGetRdkMkInt(mk_int);*/

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glColor3f(arc_color * color, arc_color * color, arc_color * color);
	glLineWidth(2.0f);
	/*glColor3f(1.0f, 1.0f, 1.0f);*/   

	for (i = 1; i < nof_steps; ++i)
	{
		range = arc_step * i;
		if (full)
			drawCircle(cx, cy, range, 0, 200, 2);
		else
			drawArc(cx, cy, range, 0, 200, 2, (int)start, (int)sweep);
	}
	/* lironf 10.9.02 */
	//glColor3f(0.0, 0.0, 0.0);
	//glBegin(GL_QUADS);
	//glVertex2f(-max_range / 2.0f, 0.0f);
	//glVertex2f(-max_range / 2.0f, max_range / 5.0f);
	//glVertex2f(max_range / 2.0f, max_range / 5.0f);
	//glVertex2f(max_range / 2.0f, 0.0f);
	//glEnd();
	//glLineWidth(1.0f);
}

void drawElevation()
{
	ProjectionMat prjMat(Matrix::Push);
	ModelViewMat mvMat(Matrix::Push);

	auto pAnt = whrdr::getRadarData().pAntenna;
	float elev = 0;
	if (pAnt)
	{
		elev = pAnt->getElevation();
	}

	const float offx = 2;
	const float sizex = 2;
	float offy = -30;
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 100, -10, 90, -1, 1);
	glBegin(GL_LINES);

	for (; offy < 31; offy += 5)
	{
		glVertex2f(offx, offy);
		glVertex2f(offx + sizex, offy);

	}

	glVertex2f(offx, 0);
	glVertex2f(offx + sizex * 2, 0);
	glColor3f(0, 0, 1);
	glVertex2f(offx, elev);
	glVertex2f(offx + sizex * 2, elev);

	glEnd();

///	glColor3f(1, 1, 1);
//	drawArcs(50, 0, 280, 160, 0, 0.3);
	//DrawCircle(50, 0, 5, 1000);
}

void draw_antenna_angle(float angle)
{
	//ProjectionMat prjMat(-1, 1, -1, 1, Matrix::Push);
	drawAzimuth(angle);

	drawElevation();
	glColor3f(1, 1, 1);
	drawArcs(50, 0, 280, 160, 0, 0.3);

}

