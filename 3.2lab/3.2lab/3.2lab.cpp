#include <gl\glut.h>
#include <math.h>
#include <Windows.h>
GLfloat angle = 0;
GLfloat size = 1;
GLfloat nap = 0.5;
GLfloat nab = 3;
void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(nab, 3, 3, 0, 0, 0, 0, 1, 0); // VM=Fwe
	GLfloat myLightPosition[] = { 10.0, 0.0, 7.0, 1.0 }; // Источник све-та в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция ис-точника света будет преобразована в CKe*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle, 0, 1, 0); // VM=Fwe*R
	glutSolidCone(size, size, 50, 50);
	//glutWireCu(0.95);
	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1); glVertex3f(10, 0, 7); glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}
void myReshape(int width, int height)
{
	if (width / height < 1) glViewport(0, 0, width, width);
	else glViewport(0, 0, height, height);
}
void myIdle()
{
	angle += nap;
	if (angle > 360.0) angle = 0;
	glutPostRedisplay();
	Sleep(50);
}

void Mose(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		size += 0.5;
		if (size >= 2) size = 2;
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		size -= 0.5;
		if (size <= 0.5) size = 0.5;
	}

}

void kl(unsigned char key, int x, int y)
{
	if (key == 'V' || key == 'v')
		nap = -nap;

	if (key == 'X' || key == 'x')
	{
		nab += 0.5;
		if (nab > 10) nab = 10;
	}
	if (key == 'Z' || key == 'z')
	{
		nab -= 0.5;
		if (nab < 0) nab = 0;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("my window");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutMouseFunc(Mose);
	glutKeyboardFunc(kl);
	init();
	glutMainLoop();
}
