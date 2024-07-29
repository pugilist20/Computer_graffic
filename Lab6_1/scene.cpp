//////////////////////////////////////////////////////////////////////////////////////////
//	Scene.cpp
//	Draw the scene for shadow mapping
//	Downloaded from: www.paulsprojects.net
//	Created:	16th September 2003
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "GL/glut.h"
#include "Maths/Maths.h"
#include "scene.h"
#include <GL/glext.h>
static GLuint baseList = 0, nameList=0;

void drawName(float angle, GLuint textureID[])
{
	if(!nameList)
	{
		nameList=glGenLists(1);
		glNewList(nameList, GL_COMPILE);
		{
			glPushMatrix();
			glTranslatef(0.0f, 0.03f, 0.0f);
			glScalef(0.08f, 0.08f, 0.08f);
			glColor3f(1, 1, 1);
			glBindTexture(GL_TEXTURE_2D, textureID[0]);
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-18, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-17, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-17, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-18, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-17, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-17, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-17, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-17, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-17, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-18, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-18, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-17, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-18, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-18, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-18, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-18, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-18, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-17, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(-17, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-18, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-18, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-17, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-17, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-18, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-16, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-16, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-16, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-16, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-16, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-13, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(-13, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-16, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-13, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-13, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(-13, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-13, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-12, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(-12, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-12, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-12, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-16, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-12, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-12, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-16, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-16, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-12, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-12, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(-16, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-14, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-14, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-13, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(-12, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(-12, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-13, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-14, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-14, 3, -1);
			glTexCoord2f(1, 1); glVertex3f(-14, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(-14, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(-15, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-15, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(-14, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(-14, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-15, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-13, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-13, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-13, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-13, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(-13, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(-13, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(-15, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-15, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-15, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(-13, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(-13, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(-15, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-16, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-16, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(-15, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-14, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-14, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-13, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-13, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-13, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(-13, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(-12, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(-12, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-15, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(-14, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-14, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-15, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(-14, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(-14, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-15, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-15, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(-15, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(-16, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(-16, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-10, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(-10, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-10, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-10, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-13, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(-13, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-14, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(-14, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-14, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-15, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-15, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-14, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-12, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(-12, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(-13, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(-13, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-14, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-15, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-15, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-14, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-12, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-16, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-16, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(-12, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-11, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-10, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-10, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-11, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-11, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-7, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(-7, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-11, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-7, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-7, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-7, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(-7, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-10, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-7, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-7, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-10, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-11, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-11, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-11, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-11, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-10, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(-7, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(-7, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-10, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-8, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(-8, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-7, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-7, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-10, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(-8, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-8, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(-10, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-11, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-10, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-10, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-11, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-10, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-8, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-8, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-10, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-8, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-8, 3, -1);
			glTexCoord2f(1, 1); glVertex3f(-8, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(-8, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-10, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(-10, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-10, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-10, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-10, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(-8, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(-8, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-10, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-10, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(-10, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-11, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-11, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-7, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-10, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-10, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-7, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-7, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-7, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-8, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(-8, 4, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-8, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-10, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-10, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(-8, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-6, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-6, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-6, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-2, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-2, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-2, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-2, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-6, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(-2, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(-2, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-5, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(-5, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-5, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-5, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-6, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-5, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-5, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-6, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-3, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(-2, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-2, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-3, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-5, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(-3, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(-3, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-5, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-5, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(-3, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(-3, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-5, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-3, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(-3, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-3, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-3, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-3, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-3, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(-3, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(-3, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-5, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-3, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-3, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-5, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-5, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(-5, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-5, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(-5, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-5, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(-3, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(-3, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(-5, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-6, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-5, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-5, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-6, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-3, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-2, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-2, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-3, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-5, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(-3, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(-3, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(-5, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-5, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(-5, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-6, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-2, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(-2, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-3, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-3, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-3, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(-5, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(-5, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(-3, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(-3, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(-5, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(-5, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-3, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(-1, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(-1, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(-1, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-1, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(-1, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(2, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(2, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(-1, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(0, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(0, 4, -1);
			glTexCoord2f(0, 1); glVertex3f(0, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(0, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(2, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(2, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(0, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(2, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(2, 5, -1);
			glTexCoord2f(1, 1); glVertex3f(2, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(2, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(-1, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(0, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(0, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(-1, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(-1, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(0, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(-1, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(0, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(2, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(2, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(0, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(2, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(0, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(0, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(2, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(0, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(0, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(-1, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(-1, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(3, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(4, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(4, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(3, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(4, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(4, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(4, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(4, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(4, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(3, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(3, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(4, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(3, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(3, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(3, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(3, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(3, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(4, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(4, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(3, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(3, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(4, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(4, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(3, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(5, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(5, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(5, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(5, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(5, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(6, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(6, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(5, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(9, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(9, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(9, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(9, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(8, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(9, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(9, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(8, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(6, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(7, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(7, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(8, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(8, 5, -1);
			glTexCoord2f(1, 1); glVertex3f(7, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(7, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(5, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(6, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(6, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(5, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(8, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(9, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(9, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(8, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(6, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(6, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(6, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(6, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(8, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(8, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(8, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(8, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(6, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(7, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(7, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(6, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(8, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(7, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(7, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(8, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(5, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(6, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(6, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(5, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(8, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(9, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(9, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(8, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(7, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(7, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(8, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(8, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(7, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(7, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(6, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(6, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(7, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(7, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(6, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(7, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(7, 3, -1);
			glTexCoord2f(1, 1); glVertex3f(8, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(8, 2, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(6, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(5, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(5, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(6, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(9, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(8, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(8, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(9, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(10, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(11, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(11, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(10, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(13, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(14, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(14, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(13, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(11, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(13, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(13, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(11, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(11, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(13, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(13, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(11, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(14, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(14, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(14, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(14, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(10, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(10, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(10, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(10, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(10, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(14, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(14, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(10, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(10, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(14, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(14, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(10, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(11, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(10, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(10, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(11, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(14, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(13, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(13, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(14, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(13, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(11, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(11, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(13, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(13, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(11, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(11, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(13, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(11, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(11, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(11, 4, -1);
			glTexCoord2f(0, 1); glVertex3f(11, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(11, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(13, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(13, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(11, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(13, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(13, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(13, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(13, 4, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(11, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(13, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(13, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(11, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(15, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(15, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(15, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(15, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(15, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(18, 5, 0);
			glTexCoord2f(1, 1); glVertex3f(18, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(15, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(18, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(18, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(18, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(18, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(19, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(19, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(19, 0, -1);
			glTexCoord2f(0, 1); glVertex3f(19, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(15, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(19, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(19, 0, 0);
			glTexCoord2f(0, 1); glVertex3f(15, 0, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(15, 0, 0);
			glTexCoord2f(1, 0); glVertex3f(19, 0, 0);
			glTexCoord2f(1, 1); glVertex3f(19, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(15, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(17, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(17, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(18, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(19, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(19, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(18, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(17, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(17, 3, -1);
			glTexCoord2f(1, 1); glVertex3f(17, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(17, 4, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(16, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(16, 4, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(17, 3, 0);
			glTexCoord2f(1, 1); glVertex3f(17, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(16, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(-1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(18, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(18, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(18, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(18, 2, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(1, 0, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 1, -1);
			glTexCoord2f(1, 0); glVertex3f(16, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(16, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 1, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 1, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 1, 0);
			glTexCoord2f(1, 0); glVertex3f(18, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(18, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(16, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(15, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(15, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(16, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(17, 5, 0);
			glTexCoord2f(1, 0); glVertex3f(17, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(18, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(18, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(18, 3, 0);
			glTexCoord2f(1, 0); glVertex3f(18, 1, 0);
			glTexCoord2f(1, 1); glVertex3f(19, 1, 0);
			glTexCoord2f(0, 1); glVertex3f(19, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(16, 2, 0);
			glTexCoord2f(1, 0); glVertex3f(17, 2, 0);
			glTexCoord2f(1, 1); glVertex3f(17, 3, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 3, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			glTexCoord2f(0, 0); glVertex3f(16, 4, 0);
			glTexCoord2f(1, 0); glVertex3f(17, 4, 0);
			glTexCoord2f(1, 1); glVertex3f(17, 5, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 5, 0);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(16, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(16, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(15, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(15, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(18, 5, -1);
			glTexCoord2f(1, 0); glVertex3f(18, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(17, 2, -1);
			glTexCoord2f(0, 1); glVertex3f(17, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(17, 4, -1);
			glTexCoord2f(1, 0); glVertex3f(16, 4, -1);
			glTexCoord2f(1, 1); glVertex3f(16, 5, -1);
			glTexCoord2f(0, 1); glVertex3f(17, 5, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(19, 3, -1);
			glTexCoord2f(1, 0); glVertex3f(19, 1, -1);
			glTexCoord2f(1, 1); glVertex3f(18, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(18, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(17, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(16, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(16, 3, -1);
			glTexCoord2f(0, 1); glVertex3f(17, 3, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, -1);
			glTexCoord2f(0, 0); glVertex3f(19, 0, -1);
			glTexCoord2f(1, 0); glVertex3f(15, 0, -1);
			glTexCoord2f(1, 1); glVertex3f(15, 1, -1);
			glTexCoord2f(0, 1); glVertex3f(19, 1, -1);
			glEnd();
			glBegin(GL_POLYGON);
			glNormal3f(0, -1, 0);
			glTexCoord2f(0, 0); glVertex3f(16, 2, -1);
			glTexCoord2f(1, 0); glVertex3f(18, 2, -1);
			glTexCoord2f(1, 1); glVertex3f(18, 2, 0);
			glTexCoord2f(0, 1); glVertex3f(16, 2, 0);
			glEnd();
			glPopMatrix();

			glBindTexture(GL_TEXTURE_2D, 0);
		}
		glEndList();
	}
	glPushMatrix();
		glRotatef(angle, 0, 1, 0);
		glCallList(nameList);
	glPopMatrix();
}

void drawCube() {
	if(!baseList)
	{
		baseList=glGenLists(1);
		glNewList(baseList, GL_COMPILE);
		{
			glPushMatrix();
			glColor3f(0, 0, 1);
			glScalef(1.0f, 0.01f, 1.0f);
			glutSolidCube(3.0f);

			glPopMatrix();
		}
		glEndList();
	}
	glCallList(baseList);
}