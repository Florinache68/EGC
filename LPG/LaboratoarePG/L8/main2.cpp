#include <GL\glut.h> 

GLdouble radius = 0.5;
GLfloat xRotated = 0.0;
GLfloat yRotated = 0.0;
GLfloat zRotated = 0.0;
GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat emitLight[] = { 0.9, 0.9, 0.9, 0.01 };
GLfloat Noemit[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat qaLightPosition[] = { 0.5, 0, -3.5, 0.5 };

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glScalef(1.0, 1.0, 1.0);
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
	glutSolidSphere(radius, 25, 25);
	glFlush();
	glutSwapBuffers();
}

void reshape(int x, int y)
{
	if (y == 0 || x == 0)
	{
		return;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0.6, 21.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}

void idleFunc(void)
{
	zRotated += 0.02;
	display();
}

void initLighting()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(350, 350);
	glutCreateWindow("L8E2");

	initLighting();
	glutIdleFunc(idleFunc);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
