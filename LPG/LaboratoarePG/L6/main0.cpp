#include <stdio.h> 
#include <GL/glut.h> 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);
	glVertex3f(2.0, 4.0, 0.0);
	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 6.0, 0.0);
	glVertex3f(2.0, 6.0, 0.0);
	glEnd();

	glFlush();
}

int main(int argc, char **argv)
{
	printf("Buna ziua dragi studenti\n");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutCreateWindow("L6E0");

	glClearColor(0.0, 0.0, 0.0, 0.0);         // fundal negru      
	glMatrixMode(GL_PROJECTION);              // setarea proiectiei de vizualizare      
	glLoadIdentity();                           // incarca matricea de identitate      
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setarea spatiului de vizualizare 10x10x2 

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}