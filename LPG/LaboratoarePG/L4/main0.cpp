#include <math.h> 
#include <GL/glut.h>  

GLuint theTorus;

static void torus(int numc, int numt)
{
	float M_PI = 3.1415926;
	int i, j, k;
	double s, t, x, y, z, twopi;
	twopi = 2 * M_PI;

	for (i = 0; i < numc; i++)
	{
		glBegin(GL_LINE_STRIP);

		for (j = 0; j <= numt; j++)
		{
			for (k = 1; k >= 0; k--)
			{
				s = (i + k) % numc + 0.5;
				t = j % numt;
				x = (1.5 + .5*cos(s*twopi / numc))*cos(t*twopi / numt);
				y = (1.5 + .5*cos(s*twopi / numc))*sin(t*twopi / numt);
				z = .5 * sin(s * twopi / numc);
				glVertex3f(x, y, z);
			}
		}

		glEnd();
	}
}

static void init(void)
{
	theTorus = glGenLists(1);
	glNewList(theTorus, GL_COMPILE);
	torus(10, 20);
	glEndList();
	glShadeModel(GL_FLAT);
	glClearColor(0.2, 0.0, 0.2, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glCallList(theTorus);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
	case 'X':
		glRotatef(10., 1.0, 0.0, 0.0);
		glutPostRedisplay();
		break;
	case 'y':
	case 'Y':
		glRotatef(10., 0.0, 1.0, 0.0);
		glutPostRedisplay();
		break;
	case 'i':
	case 'I':
		glLoadIdentity();
		gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

void main(int argc, char **argv)
{
	glutInitWindowSize(700, 700);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("L6E2");

	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
}