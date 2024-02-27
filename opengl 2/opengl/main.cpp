#include <GL\glut.h>
GLfloat xRotated, yRotated, zRotated;
GLdouble size = 1;
void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	// goleste zona tampon de desenare.
	glClear(GL_COLOR_BUFFER_BIT);
	// sterge matricea de identitate.
	glLoadIdentity();
	// translateaza desenul cu z = -4.0
	// Retineti ca atunci cand z este -8.0 desenul va parea a fi mai departe sau mai mic.
	glTranslatef(0.0, 0.0, -4.5);
	// Este utilizata culoarea rosie pentru a desena.
	glColor3f(0.8, 0.8, 0.1);
	// schimabrea in matricea de transformare.
	// rotatie dupa axa X
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotatie dupa axa Y
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotatie dupa axa X
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// transformarea de scalare
	glScalef(1.0, 1.0, 1.0);
	// functie inclusa in bibloteca (glut library), pentru desenarea unui ceainic.
	glutSolidTeapot(size);
	// Golirea tamponului de afisare

	glFlush();
	// este apelat dublu buffer
	// glutSwapBuffers();
}
void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return; //Nimic nu este vizibil, reintoarcere
	//Setarea unei noi matrici de proiectie
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Vizualizare sub unghi de:40 grade
	//Distanta de plan de aproape in perspectiva: 0.5
	//Distanta de plan de departare in perspectiva: 20.0

	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glViewport(0, 0, x, y); //Foloseste fereastra de randare
}
void idleFunc(void)
{
	yRotated += 0.01;

	display();
}
int main(int argc, char** argv)
{
	//Initializare GLUT
	glutInit(&argc, argv);
	//double buffering utilizat pentru a evita problemele de palpaire in animatie
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Dimensionare fereastra
	glutInitWindowSize(400, 350);
	// Crearea ferestrei
	glutCreateWindow("Rotatia Animata a unui ceainic");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	xRotated = yRotated = zRotated = 30.0;
	xRotated = 33;
	yRotated = 40;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//Atribuire functie folosita in evenimente
	glutDisplayFunc(display);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);
	//Intrare in bucla de evenimente
	glutMainLoop();
	return 0;
}