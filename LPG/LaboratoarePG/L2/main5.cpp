#include <windows.h> 
#include <GL/gl.h> 
#include <GL/glut.h> 

float x0, y0, x1, y1, x2, y2;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(x0, y0, 0.0);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glEnd();

	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	x0 = 0.25;
	y0 = 0.25;
	x1 = 0.75;
	y1 = 0.75;
	x2 = 0.3;
	y2 = 0.45;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("L2E5");

	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
