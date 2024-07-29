#pragma warning (disable : 4996)
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <GL/glext.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

GLfloat angle = 0, rotate_fig = 0;
GLfloat light_angle = 0, rotate_light = 0;
GLfloat ratio = (float)640.0 / 480;
int ch1 = 0, ch2 = 0;
bool mode = false;
GLuint list = 0, list2 = 0;


void init() {
	glClearColor(0.18, 0.2, 0.266, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 0.33f, 0.001f, 55.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -13.0);

	// Данные, прочитанные из заголовка BMP-файла
	unsigned char header1[54], header2[54], header3[54]; // Каждый BMP-файл начинается с заголовка, длиной в 54 байта
	unsigned int dataPos1, dataPos2, dataPos3;     // Смещение данных в файле (позиция данных)
	unsigned int width1, height1, width2, height2, width3, height3;
	unsigned int imageSize1, imageSize2, imageSize3;   // Размер изображения = Ширина * Высота * 3
	// RGB-данные, полученные из файла
	unsigned char* data1;
	unsigned char* data2;
	unsigned char* data3;

	FILE* file1 = fopen("C:\\Users\\ogrrn\\source\\repos\\KG\\5.1lab\\5.1lab\\a.bmp", "rb");
	fread(header1, 1, 54, file1);

	// Читаем необходимые данные
	dataPos1 = *(int*)&(header1[0x0A]); // Смещение данных изображения в файле с 11 байта
	imageSize1 = *(int*)&(header1[0x22]); // Размер изображения в байтах с 35 байта
	width1 = *(int*)&(header1[0x12]); // Ширина с 18 
	height1 = *(int*)&(header1[0x16]); // Высота

	// Некоторые BMP-файлы имеют нулевые поля imageSize и dataPos, поэтому исправим их
	if (imageSize1 == 0)    imageSize1 = width1 * height1 * 3; // Ширину * Высоту * 3, где 3 - 3 компоненты цвета (RGB)
	if (dataPos1 == 0)      dataPos1 = 54; // В таком случае, данные будут следовать сразу за заголовком
	// Создаем буфер
	data1 = new unsigned char[imageSize1];
	// Считываем данные из файла в буфер
	fread(data1, 1, imageSize1, file1);
	// Закрываем файл, так как больше он нам не нужен
	fclose(file1);

	FILE* file2 = fopen("C:\\Users\\ogrrn\\source\\repos\\KG\\5.1lab\\5.1lab\\b.bmp", "rb");
	fread(header2, 1, 54, file2);

	dataPos2 = *(int*)&(header2[0x0A]);
	imageSize2 = *(int*)&(header2[0x22]);
	width2 = *(int*)&(header2[0x12]);
	height2 = *(int*)&(header2[0x16]);

	if (imageSize2 == 0)    imageSize2 = width2 * height2 * 3;
	if (dataPos2 == 0)      dataPos2 = 54;
	data2 = new unsigned char[imageSize2];

	fread(data2, 1, imageSize2, file2);
	fclose(file2);

	FILE* file3 = fopen("C:\\Users\\ogrrn\\source\\repos\\KG\\5.1lab\\5.1lab\\c.bmp", "rb");
	fread(header3, 1, 54, file3);

	dataPos3 = *(int*)&(header3[0x0A]);
	imageSize3 = *(int*)&(header3[0x22]);
	width3 = *(int*)&(header3[0x12]);
	height3 = *(int*)&(header3[0x16]);

	if (imageSize3 == 0)    imageSize3 = width3 * height3 * 3;
	if (dataPos3 == 0)      dataPos3 = 54;

	data3 = new unsigned char[imageSize3];
	fread(data3, 1, imageSize3, file3);
	fclose(file3);

	// Создадим одну текстуру OpenGL
	GLuint textureID[3];
	glGenTextures(3, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// Сделаем созданную текстуру текущий, таким образом все следующие функции будут работать именно с этой текстурой
	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	// Передадим изображение OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_BGR, GL_UNSIGNED_BYTE, data1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_BGR, GL_UNSIGNED_BYTE, data2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width3, height3, 0, GL_BGR, GL_UNSIGNED_BYTE, data3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	list = glGenLists(1);
	glNewList(list, GL_COMPILE);
	// грань f0 (основание)
	glBindTexture(GL_TEXTURE_2D, textureID[0]);
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); 
	glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); 
	glVertex3f(1, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, 0, 1);
	glTexCoord2f(1, 1); 
	glVertex3f(0, 0, 1);
	glEnd();

	// грань f1 (задняя стенка)
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); 
	glVertex3f(0, 0, 0);
	glTexCoord2f(0.5f, 1.0f); 
	glVertex3f(0.45, 0.75, 0);
	glTexCoord2f(1, 0); 
	glVertex3f(1, 0, 0);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, textureID[1]);
	// грань f2 (передняя стенка)
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 1);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.45, 0.75, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureID[2]);
	// грань f4 (левая стенка)
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0, 0, 1);
	glTexCoord2f(1, 0); glVertex3f(0.45, 0.75, 1);
	glTexCoord2f(1, 1); glVertex3f(0.45, 0.75, 0);
	glEnd();

	// грань f5 (правая стенка)
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0.45, 0.75, 0);
	glTexCoord2f(1, 0); glVertex3f(0.45, 0.75, 1);
	glTexCoord2f(1, 1); glVertex3f(1, 0, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	glEndList();

	list2 = glGenLists(1);
	glNewList(list2, GL_COMPILE);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();
	glEndList();
}

void reshape(int width, int height) {
	if (width / height < 1) {
		glViewport(0, 0, width, width);
	}
	else {
		glViewport(0, 0, height, height);
	}
}

void display(void) {
	if (rotate_light) {
		light_angle += 0.5;
		if (light_angle == 360) {
			light_angle = 0;
		}
	}

	if (rotate_fig) {
		angle += 0.5;
		if (angle == 360) {
			angle = 0;
		}
	}

	glPushMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(3.0, 1.5, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// Свет
	glPushMatrix();
	glRotatef(light_angle, 0.0, 1.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat myLightPosition[] = { 3, 3, 3, 1.0 };
	GLfloat myAmbient[] = { 0.25, 0.25, 0.25, 1 }; //фоновый
	GLfloat myDiffuse[] = { 0.4, 0.4, 0.4, 1 }; // диффузный
	GLfloat mySpecular[] = { 0.774597, 0.774597, 0.774597, 1 }; // зеркальный
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]); glVertex3f(0, 0, 0);
	glEnd();

	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);

	GLfloat myShininess[] = { 76.8 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
	glPopMatrix();


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	glScalef(4.0f, 4.0f, 4.0f);
	glCallList(list);
	glPopMatrix();


	glDisable(GL_LIGHTING);
	glCallList(list2);
	glPopMatrix();

	glFlush();

	if (mode) {
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
	else {
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}

	glutSwapBuffers();
	Sleep(20);
}

void rotateView(unsigned char key, int _x, int _y) {
	switch (key) {
	case 'f':
		mode = false;
		break;
	case 'b':
		mode = true;
		break;
	case 'l':
		rotate_light = !rotate_light;
		break;
	case 'o':
		rotate_fig = !rotate_fig;
		break;
	}
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Пример текстурирования");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(rotateView);
	glutMouseFunc(mouseButton);
	glutIdleFunc(display);
	init();
	glutMainLoop();
	return 0;
}
