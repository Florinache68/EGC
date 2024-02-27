#include <GL/glut.h> 

GLfloat yang = 1.2;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(yang, 0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0, 0.45);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.45, -0.45);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.45, -0.45);
	glEnd();

	glutSwapBuffers();
	glFlush();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("L6E6");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	init();
	glutMainLoop();
}