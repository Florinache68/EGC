#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <GL/glut.h> 

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void draw(void)
{
	int r = 10;
	GLfloat theta;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

	for (theta = 0; theta <= 360; theta += 0.01)
	{
		glVertex2f(5 * sin(theta*3.142 / 180), 2 * cos(theta*3.142 / 180));
	}

	glEnd();
	glFlush();
}

void gasket()
{
	GLfloat v[3][2] = { { 1.0, 1.0 }, { 6.0, 1.0 }, { 3.5, 5.5 } };
	GLfloat p[2] = { 2.5, 2.5 };
	int j, i;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	for (i = 0; i < 50000; i++)
	{
		j = rand() % 3;
		p[0] = (p[0] + v[j][0]) / 2.0;
		p[1] = (p[1] + v[j][1]) / 2.0;
		glVertex2fv(p);
	}

	glEnd();
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		draw();
	}
	else
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			gasket();
		}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myKey(unsigned char key, int x, int y)
{
	if (key == 'g' || key == 'G')
	{
		gasket();
	}
	else
		if (key == 'c' || key == 'C')
		{
			draw();
		}
		else
		{
			exit(0);
		}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("L4E2");

	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKey);
	myinit();
	glutMainLoop();

	return 0;
}