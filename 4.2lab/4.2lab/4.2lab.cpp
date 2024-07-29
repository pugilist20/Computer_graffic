#include "stdio.h"
#include <Windows.h>
#include <GL\glut.h>

GLfloat angleLight = 0;
GLfloat angle0 = 0;
GLfloat li = 0;
GLfloat ob = 0;

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
	gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0); // VM=Fwe

	glPushMatrix();// Источник све-та в CKw
	glRotatef(angleLight, 0, 1, 0);
	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); /*Позиция источника света будет преобразована в CKe*/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPopMatrix();

	glColor3f(1, 1, 1);

	GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1 }; //фоновый
	GLfloat myDiffuse[] = { 0.4, 0.4, 0.4, 1 }; // диффузный
	GLfloat mySpecular[] = { 0.774597, 0.774597, 0.774597, 1 }; // зеркальный
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	GLfloat myShininess[] = { 76.8 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);

	glPushMatrix();
	glRotatef(angle0, 0, 1, 0); // VM=Fwe*R*R
	//правая боковая
	glBegin(GL_POLYGON);
	glNormal3f(0.75, 0.55, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0.45, 0.75, 0);
	glVertex3f(0.45, 0.75, 1);
	glVertex3f(1, 0, 1);

	//задняя

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -0.75);
	glVertex3f(0, 0, 0);
	glVertex3f(0.45, 0.75, 0);
	glVertex3f(1, 0, 0);
	glEnd();
	//левая бюоковая
	glBegin(GL_POLYGON);
	glNormal3f(-0.75, 0.45, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glVertex3f(0.45, 0.75, 1);
	glVertex3f(0.45, 0.75, 0);
	glEnd();
	//передняя
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 0, 1);
	glVertex3f(1, 0, 1);
	glVertex3f(0.45, 0.75, 1);
	glEnd();

	// нижняя
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(1, 0, 1);
	glVertex3f(0, 0, 1);

	glEnd();

	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
	glEnd();

	glPushMatrix();
	glRotatef(angleLight, 0, 1, 0);

	glBegin(GL_LINES);
	glColor3f(1, 1, 1); glVertex3f(1, 2, 2); glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glPopMatrix();
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
	angleLight += li;
	angle0 += ob;
	if (angleLight > 360.0) angleLight = 0;
	if (angle0 > 360.0) angle0 = 0;

	glutPostRedisplay();
	Sleep(25);

}

void Keybord(unsigned char key, int x, int y)
{
	if (key == 'l' || key == 'L')
	{
		if (li == 0) li = 5;
		else li = 0;
	}
	if (key == 'o' || key == 'O')
	{
		if (ob == 0) ob = 5;
		else ob = 0;
	}
	if (key == 'f' || key == 'F')
	{
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	if (key == 'b' || key == 'B')
	{
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
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
	glutKeyboardFunc(Keybord);
	init();
	glutMainLoop();
}
