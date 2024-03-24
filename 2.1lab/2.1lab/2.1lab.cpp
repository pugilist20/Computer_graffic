#include <Gl/glut.h>
GLfloat angle = 0;

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

}
void figure1(void)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);	// движущийся зеленый квадрат
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glEnd();
}

void figure2(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);	//неподвижный красный квадрат
	glVertex2f(6, 6);
	glVertex2f(4, 6);
	glVertex2f(4, 4);	
	glVertex2f(6, 4);
	glEnd();
}

void axis(void) // рисование осей
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, -12);
	glVertex2f(0, 12);
	glVertex2f(-12, 0);
	glVertex2f(12, 0);
	glEnd();
}

void display(void)	//функция рисования и обновления окна
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	axis();
	figure2();
	glTranslatef(5, 5, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-5, -5, 0);
	figure1();
	glFlush();
}

void timer(int value)
{
	angle += 5;
	if (angle >= 360)
	{
		angle = 0;
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Преобразования модели");
	glutDisplayFunc(display);
	glutTimerFunc(500, timer, 0);
	init();
	glutMainLoop();
}
