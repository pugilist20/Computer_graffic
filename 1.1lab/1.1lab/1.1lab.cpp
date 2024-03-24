#include <GL/glut.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

void drawGraph() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // синий цвет

    for (float x = 0.0f; x <= 1.0f; x += 0.1f) {
        float y = 6.6e-4 * sin(10e5 * x - 179.43);
        glVertex2f(x * WIDTH, y * HEIGHT);
    }

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT); // Устанавливаем ортографическую проекцию
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Graph");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(drawGraph);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
