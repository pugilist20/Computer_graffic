#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include "GLee/GLee.h"  //GL header file, including extensions
#include <GL/glut.h>
#include "Maths/Maths.h"
#include "TIMER.h"
#include "FPS_COUNTER.h"
#include "scene.h"
#include "main.h"

TIMER timer;

FPS_COUNTER fpsCounter;

const double PI = 3.141592653589793;
float angle = 0.0f;
float cameraangle = PI / 2;
VECTOR3D cameraPosition(0, 1.5f, 3.5f);
VECTOR3D lightPosition(2.0f, 2.0f, -2.0f);
bool rotate_light = false;
GLuint textureID[1];

float x = 3.0f, y = 1.5f, z = 3.0f;

const int shadowMapSize = 512;

GLuint shadowMapTexture;

int windowWidth, windowHeight;

MATRIX4X4 lightProjectionMatrix, lightViewMatrix;
MATRIX4X4 cameraProjectionMatrix, cameraViewMatrix;

bool Init(void)
{
	unsigned char header1[54];
	unsigned int dataPos1;
    unsigned int width1, height1;
    unsigned int imageSize1;

    unsigned char * data1;

	FILE * file1 = fopen("1.bmp","rb");
	fread(header1, 1, 54, file1);

    dataPos1 = *(int*)&(header1[0x0A]);
    imageSize1 = *(int*)&(header1[0x22]);
    width1 = *(int*)&(header1[0x12]);
    height1 = *(int*)&(header1[0x16]);

    if (imageSize1==0)    imageSize1=width1*height1*3;
    if (dataPos1==0)      dataPos1=54;
    data1 = new unsigned char [imageSize1];
    fread(data1,1,imageSize1,file1);
    fclose(file1);

    glGenTextures(1, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, textureID[0]);

	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width1, height1, 0, GL_BGR, GL_UNSIGNED_BYTE, data1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);

    if (!GLEE_ARB_depth_texture || !GLEE_ARB_shadow)
    {
        printf("I require ARB_depth_texture and ARB_shadow extensionsn\n");
        return false;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

    glClearDepth(1.0f);

    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glEnable(GL_NORMALIZE);

    glGenTextures(1, &shadowMapTexture);
    glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,
        GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    //Use the color as the ambient and diffuse material
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    //White specular material color, shininess 16
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 16.0f);

    //Calculate & save matrices
    glPushMatrix();

    glLoadIdentity();
    gluPerspective(45.0f, (float)windowWidth / windowHeight, 1.0f, 100.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);

    glLoadIdentity();
    gluLookAt(x * cos(cameraangle), y, z * sin(cameraangle),
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);

    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 2.0f, 8.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, lightProjectionMatrix);

    glLoadIdentity();
	gluLookAt(lightPosition.x, lightPosition.y, lightPosition.z,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, lightViewMatrix);

    glPopMatrix();
	glClearColor(0.18, 0.2, 0.266, 0.0);

    //Reset timer
    timer.Reset();

    return true;
}

//Called to draw scene
void Display(void)
{

	glBegin(GL_LINE);
	glColor3f(1, 1, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(lightPosition.x, lightPosition.y, lightPosition.z);
	glColor3f(0, 0, 0);
	glEnd();

	glLoadIdentity();
    gluLookAt(x * cos(cameraangle), y, z * sin(cameraangle),
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, cameraViewMatrix);
    //angle of spheres in scene. Calculate from time
	angle = timer.GetTime() / 50;

    //First pass - from light's point of view
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(lightProjectionMatrix);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(lightViewMatrix);

    //Use viewport the same size as the shadow map
    glViewport(0, 0, shadowMapSize, shadowMapSize);

    //Draw back faces into the shadow map
    glCullFace(GL_FRONT);

    //Disable color writes, and use flat shading for speed
    glShadeModel(GL_FLAT);
    glColorMask(0, 0, 0, 0);

    //Draw the scene
    drawCube();
    drawName(angle, textureID);

    //Read the depth buffer into the shadow map texture
    glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
    glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, shadowMapSize, shadowMapSize);

    //restore states
    glCullFace(GL_BACK);
    glShadeModel(GL_SMOOTH);
    glColorMask(1, 1, 1, 1);

    //2nd pass - Draw from camera's point of view
    glClear(GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(cameraProjectionMatrix);

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(cameraViewMatrix);

    glViewport(0, 0, windowWidth, windowHeight);

    //Use dim light to represent shadowed areas
    glLightfv(GL_LIGHT1, GL_POSITION, VECTOR4D(lightPosition));
    glLightfv(GL_LIGHT1, GL_AMBIENT, white * 0.2f);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white * 0.2f);
    glLightfv(GL_LIGHT1, GL_SPECULAR, black);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHTING);


    // we draw the model
    drawCube();
    drawName(angle, textureID);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);

    //Calculate texture matrix for projection
    //This matrix takes us from eye space to the light's clip space
    //It is postmultiplied by the inverse of the current view matrix when specifying texgen

    static MATRIX4X4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.5f, 1.0f);    //bias from [-1, 1] to [0, 1]
    MATRIX4X4 textureMatrix = biasMatrix * lightProjectionMatrix * lightViewMatrix;

    //Set up texture coordinate generation.
    //selects a texture-coordinate generation function or supplies coefficients for one
    //of the functions. coord names one of the (s, t, r, q)
    //If the texture generation function is GL_EYE_LINEAR, the function  = g = p1' xe + p2' ye + p3' ze + p4' we

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
    glEnable(GL_TEXTURE_GEN_S);

    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
    glEnable(GL_TEXTURE_GEN_T);

    glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
    glEnable(GL_TEXTURE_GEN_R);

    glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
    glEnable(GL_TEXTURE_GEN_Q);

    //Bind & enable shadow map texture
    glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
    glEnable(GL_TEXTURE_2D);

    //Enable shadow comparison
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

    //Shadow comparison should be true (ie not in shadow) if r<=texture
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

    //Shadow comparison should generate an INTENSITY result
    glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);

    glAlphaFunc(GL_GEQUAL, 0.99f);
    glEnable(GL_ALPHA_TEST);
    //The scene is then drawn for the third and final time, then any changed states are reset.

        // We draw the shadow
	drawCube();
	drawName(angle, textureID);

    //Disable textures and texgen
    glDisable(GL_TEXTURE_2D);

    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_R);
    glDisable(GL_TEXTURE_GEN_Q);

    //Restore other states
    glDisable(GL_LIGHTING);
    glDisable(GL_ALPHA_TEST);

    glFinish();
    glutSwapBuffers();
    Sleep(20);
    glutPostRedisplay();
}

//Called on window resize
void Reshape(int w, int h)
{
    //Save new window size
    windowWidth = w, windowHeight = h;

    //Update the camera's projection matrix
    glPushMatrix();
    glLoadIdentity();
    gluPerspective(45.0f, (float)windowWidth / windowHeight, 1.0f, 100.0f);
    glGetFloatv(GL_MODELVIEW_MATRIX, cameraProjectionMatrix);
    glPopMatrix();
}

//Called when a key is pressed
void Keyboard(unsigned char key, int x, int y)
{
    //If escape is pressed, exit
    if (key == 27)
        exit(0);

    //Use P to pause the animation and U to unpause
    if (key == 'P' || key == 'p')
        timer.Pause();

    if (key == 'U' || key == 'u')
        timer.Unpause();
	if (key == 'D' || key == 'd')
		cameraangle -= PI / 10;
		if (cameraangle < 0) {
			cameraangle = 2 * PI - PI / 10;
		}

	if (key == 'A' || key == 'a') {
		cameraangle += PI / 10;
		if (cameraangle > 2 * PI) {
			cameraangle = PI / 10;
		}
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 512);
    glutCreateWindow("Shadow Mapping");

    if (!Init())
        return 0;

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}
