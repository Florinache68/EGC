#include <GL/freeglut.h> 

#define ACCSIZE 16 //numarul de esantionari 

static float W = 6; //dimensiunea maxima a ferestrei 
static float WX, WY; //dimensiuni fereastra 
static float N = -10; //distanta de vizualizare near 
static float F = 10; //distanta de vizualizare far 

void Init()
{
	GLfloat ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 1.0, 0.2, 1.0, 0.0 };
	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.9, 0.2, 0.1, 1.0 };
	GLfloat mat_specular[] = { 0.9, 0.6, 0.6, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearAccum(0.0, 0.0, 0.0, 0.0);
	glClearColor(0.8, 0.8, 0.8, 1.0);
}

GLfloat jitter16[][2] = { { 0.375, 0.4375 }, { 0.625, 0.0625 }, { 0.875, 0.1875 },
{ 0.125, 0.0625 }, { 0.375, 0.6875 }, { 0.875, 0.4375 },
{ 0.625, 0.5625 }, { 0.375, 0.9375 }, { 0.625, 0.3125 },
{ 0.125, 0.5625 }, { 0.125, 0.8125 }, { 0.375, 0.1875 },
{ 0.875, 0.6875 }, { 0.875, 0.0625 }, { 0.125, 0.3125 },
{ 0.625, 0.8125 } };

void Display()
{
	int i;
	glClear(GL_ACCUM_BUFFER_BIT);
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	//Redarea cu anti-aliasing a obiectului  
	for (i = 0; i < ACCSIZE; i++)
	{
		glPushMatrix();
		glTranslatef(jitter16[i][0] * 2 * WX / viewport[2], jitter16[i][1] * 2 * WY / viewport[3], 0.0);
		glTranslated(1.5, -1, -8);
		glRotatef(15.0, 1.0, 0.0, 0.0);
		glRotatef(20.0, 0.0, 1.0, 0.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glutSolidTeapot(1.0);   glPopMatrix();   glAccum(GL_ACCUM, 1.0 / ACCSIZE);
	}

	glAccum(GL_RETURN, 1.0);

	//Obiectul redat fara anti-aliasing  
	glPushMatrix();
	glTranslated(-1.5, -1.0, -8.0);
	glRotatef(15.0, 1.0, 0.0, 0.0);
	glRotatef(20.0, 0.0, 1.0, 0.0);
	glutSolidTeapot(1.0);
	glPopMatrix();
	glFlush();
}

void Reshape(int w, int h)
{
	h = (h == 0) ? 1 : h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		WX = W / 2;
		WY = W * (GLfloat)h / (GLfloat)(w * 2);
	}
	else
	{
		WX = W * (GLfloat)w / (GLfloat)(h * 2);
		WY = W / 2;
	}

	glOrtho(-WX, WX, -WY, WY, N, F);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA | GLUT_ACCUM);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("L11E1");
	Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

