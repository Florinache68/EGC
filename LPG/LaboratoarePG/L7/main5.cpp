#include <GL\glut.h> 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -3);
	glutWireTeapot(1);
	glTranslatef(0, 2, 0);
	glutSolidTeapot(1);
	glPopMatrix();
	glTranslatef(0, -2, -1);
	glutSolidTeapot(1);
	glPopMatrix();
	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("L7E5");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutMainLoop();
}