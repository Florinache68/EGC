#include <iostream>
#include <stdlib.h> 
#include <GL/glut.h> 

using namespace std;

float _angle = -70.0f;

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		glDisable(GL_LIGHT0);
		break;
	case 's':
		glEnable(GL_LIGHT0);
		break;
	case 'd':
		glDisable(GL_LIGHT1);
		break;
	case 'f':
		glEnable(GL_LIGHT1);
		break;
	case 27:
		exit(0);
	default:
		break;
	}

	glutPostRedisplay();
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
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
	glTranslatef(0.0f, 0.0f, -8.0f);
	GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	GLfloat diffuseLightColor0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLightColor0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightPos0[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };
	GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidTeapot(2.0);
	glutSwapBuffers();
}

void update(int value)
{
	_angle += 1.5f;

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
	glutCreateWindow("L8E5");

	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();

	return 0;
}