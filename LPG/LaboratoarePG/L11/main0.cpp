#include <GL/freeglut.h> 

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(1.5);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Display()
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPushMatrix();
	glTranslated(0.0, 0.0, -25.0);
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_POLYGON_SMOOTH);
	glPushMatrix();
	glTranslated(-8.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3d(-3, -3, 0);
	glVertex3d(3, -2, 0);
	glVertex3d(2, 3, 0);
	glEnd();

	glPopMatrix();
	glPushMatrix();
	glTranslated(-2.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex3d(-3, -3, 0);
	glVertex3d(3, -2, 0);
	glVertex3d(2, 3, 0);
	glEnd();

	glPopMatrix();
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glPushMatrix();
	glTranslated(4.0, 0.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3d(-3, -3, 0);
	glVertex3d(3, -2, 0);
	glVertex3d(2, 3, 0);
	glEnd();

	glPopMatrix();
	glPushMatrix();
	glTranslated(10.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex3d(-3, -3, 0);
	glVertex3d(3, -2, 0);
	glVertex3d(2, 3, 0);
	glEnd();

	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA | GLUT_ACCUM);
	glLoadIdentity();
	glutInitWindowSize(200, 200);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("L11E0");
	Init();
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}