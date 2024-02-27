#include <GL\glut.h> 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSolidTeapot(.5);
	glFlush();
}

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("L7E1");

	glutDisplayFunc(display);
	glutMainLoop();
}