#include <GL\glut.h> 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glutWireTeapot(0.5);
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
	glutCreateWindow("L7E4");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutMainLoop();
}