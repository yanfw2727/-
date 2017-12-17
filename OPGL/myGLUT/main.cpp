#include "stdafx.h"

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "trackball.c"
#include <string.h>

typedef float vec[3];
typedef int tri[3];

struct myModel {
	int num_v;		// number of vertex
	int num_vn;		// number of vertex normal
	int num_tri;	// number of triangle
	vec* v;			// vertex
	vec* vn;		// vertex normal
	tri* fi;		// face index
	tri* fni;		// face normal index
	float maxLen;	// max edge length of bounding box
	vec center;

	vec* flatNormal;	// flat normal, polygon normal
};


myModel* pModel;
myModel* ReadModel(char* filename);
void myDraw(myModel* p);
int WindWidth = 600, WindHeight = 600;

void Reshape(int width, int height)
{

	tbReshape(width, height);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 128.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, pModel->maxLen*0.7f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	WindWidth = width;
	WindHeight = height;
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	tbMatrix();

	// place object center at (0, 0, 0)
	glTranslatef(-pModel->center[0], -pModel->center[1], -pModel->center[2]);

	myDraw(pModel);
	glPopMatrix();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	tbMouse(button, state, x, y);
}

void motion(int x, int y)
{
	tbMotion(x, y);
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(1.0f);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(WindWidth, WindHeight);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("OBJ Reader");

	init();

	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	tbInit(GLUT_LEFT_BUTTON);
	tbAnimate(GL_TRUE);

	pModel = ReadModel("Angel2.obj");

	glutMainLoop();

	return 0;
}



myModel* ReadModel(char* filename)
{
	myModel* p = new myModel;
	FILE* fp;
	char line[256];
	int vc = 0;		// vertex count
	int vnc = 0;	// vertex normal count
	int fc = 0;		// face count


	// read first time:
	// count 	int num_v;		// number of vertex
	//			int num_vn;		// number of vertex normal
	//			int num_tri;	// number of triangle

	p->num_v = p->num_vn = p->num_tri = 0;

	fp = fopen(filename, "r");
	while (fscanf(fp, "%s", line) != EOF) {
		if (!strcmp("v", line))
			p->num_v++;
		else if (!strcmp("vn", line))
			p->num_vn++;
		else if (!strcmp("f", line))
			p->num_tri++;

		fgets(line, 255, fp);
	}

	// read second time
	rewind(fp);

	// index 0 not used
	p->v = new vec[p->num_v + 1];
	p->vn = new vec[p->num_vn + 1];
	p->fi = new tri[p->num_tri + 1];
	p->fni = new tri[p->num_tri + 1];

	while (fscanf(fp, "%s", line) != EOF) {
		if (!strcmp("v", line)) {
			vc++;
			fscanf(fp, "%f %f %f", p->v[vc], p->v[vc] + 1, p->v[vc] + 2);
		}
		else if (!strcmp("vn", line)) {
			vnc++;
			fscanf(fp, "%f %f %f", p->vn[vnc], p->vn[vnc] + 1, p->vn[vnc] + 2);
		}
		else if (!strcmp("f", line)) {
			fc++;
			fscanf(fp, "%d//%d%d//%d%d//%d",
				p->fi[fc], p->fni[fc],
				p->fi[fc] + 1, p->fni[fc] + 1,
				p->fi[fc] + 2, p->fni[fc] + 2);
		}
		else
			fgets(line, 255, fp);
	}

	fclose(fp);

	// find maxLen
	int i;
	float xMin, xMax, xL, yMin, yMax, yL, zMin, zMax, zL;
	xMin = xMax = p->v[1][0];
	yMin = yMax = p->v[1][1];
	zMin = zMax = p->v[1][2];

	for (i = 2; i <= p->num_v; i++) {
		if (xMin > p->v[i][0])
			xMin = p->v[i][0];
		else if (xMax < p->v[i][0])
			xMax = p->v[i][0];

		if (yMin > p->v[i][1])
			yMin = p->v[i][1];
		else if (yMax < p->v[i][1])
			yMax = p->v[i][1];

		if (zMin > p->v[i][2])
			zMin = p->v[i][2];
		else if (zMax < p->v[i][2])
			zMax = p->v[i][2];
	}

	xL = xMax - xMin;
	yL = yMax - yMin;
	zL = zMax - zMin;

	p->maxLen = xL;
	if (p->maxLen < yL)
		p->maxLen = yL;
	if (p->maxLen < zL)
		p->maxLen = zL;

	// center
	p->center[0] = (xMin + xMax) / 2.0f;
	p->center[1] = (yMin + yMax) / 2.0f;
	p->center[2] = (zMin + zMax) / 2.0f;

	// compute polygon normal
	p->flatNormal = new vec[p->num_tri + 1];

	vec e1, e2;			// edge vector
	int vi1, vi2, vi3;	// vertex_index
	float veclen;		// vector length

	for (i = 1; i <= p->num_tri; i++) {
		vi1 = p->fi[i][0];
		vi2 = p->fi[i][1];
		vi3 = p->fi[i][2];
		e1[0] = p->v[vi2][0] - p->v[vi1][0];
		e1[1] = p->v[vi2][1] - p->v[vi1][1];
		e1[2] = p->v[vi2][2] - p->v[vi1][2];
		e2[0] = p->v[vi3][0] - p->v[vi2][0];
		e2[1] = p->v[vi3][1] - p->v[vi2][1];
		e2[2] = p->v[vi3][2] - p->v[vi2][2];

		// cross product
		p->flatNormal[i][0] = e1[1] * e2[2] - e1[2] * e2[1];
		p->flatNormal[i][1] = e1[2] * e2[0] - e1[0] * e2[2];
		p->flatNormal[i][2] = e1[0] * e2[1] - e1[1] * e2[0];

		// normalize
		veclen = sqrt(pow(p->flatNormal[i][0], 2) + pow(p->flatNormal[i][1], 2) + pow(p->flatNormal[i][2], 2));
		p->flatNormal[i][0] /= veclen;
		p->flatNormal[i][1] /= veclen;
		p->flatNormal[i][2] /= veclen;
	}

	return p;
}

void myDraw(myModel* p)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);
	for (int i = 1; i <= p->num_tri; i++) {		// for each triangle
		for (int j = 0; j<3; j++) {		// for 3 vertices
			glVertex3fv(p->v[p->fi[i][j]]);
		}
	}
	glEnd();
}
