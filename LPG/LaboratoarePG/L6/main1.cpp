#include <iostream> 
#include <stdlib.h> 
#include <GL/glut.h>   

using namespace std;

float _angle = 30.0f;
float _cameraAngle = 0.0f;

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
	}
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.0f, 0.8f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glColor3f(0.0f, 0.9f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glColor3f(0.0f, 0.65f, 0.65f);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 2.0f;

	if (_angle > 360)
	{
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("L6E1");

	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
}