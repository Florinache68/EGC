#include <GL\glut.h> 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glutSolidTeapot(0.5);
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
	glutCreateWindow("L7E3");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glutMainLoop();
}