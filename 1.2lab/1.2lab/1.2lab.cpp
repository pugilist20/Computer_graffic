#include <GL/glut.h>
#include <cmath>
#include <math.h>
void init();
void draw();
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Лаба 1, Задание 2");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
void init() 
{
	glClearColor(0.9, 0.9, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-8.0, 8.0, -5.0, 5.0); 
}
void draw()
{
	GLfloat r = 0, g = 0.5,b = 0;
	GLint x = 0, y = 0, w = 60, h = 60;
	glClear(GL_COLOR_BUFFER_BIT);
	for (x = -8; x <= 8; x += 1) {
		for (y = -10; y <= 10; y += 1)
		{
			if (r < 1.0) { r += 0.1; }
			else { r = 0; }
			if (g < 1.0) { g += 0.1; }
			else { g = 0; }
			if (b < 1.0) { b += 0.1; }
			else { b = 0; }
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);
			glVertex2f(x, y - 0.1);
			glVertex2f(x - 0.3, y - 0.3);
			glVertex2f(x - 0.1, y);
			glVertex2f(x - 0.3, y + 0.3);
			glVertex2f(x, y + 0.1);
			glVertex2f(x + 0.3, y + 0.3);
			glVertex2f(x + 0.1, y);
			glVertex2f(x + 0.3, y - 0.3);
			glEnd();
		}
	}
	glFlush();
}
