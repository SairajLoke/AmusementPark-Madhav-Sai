#include "include_libs.h"
#include "cpp_libs.h"

static Objects objects;
static int lastX, lastY;
static int rotateX = 0;
static int rotateY = 0;
double zoom = 1.0;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        lastX = x;
        lastY = y;
    }
    else if (button == 4) { // Scroll up
        zoom *= 1.1;
    }
    else if (button == 3) { // Scroll down
        zoom /= 1.1;
        if (zoom < 0.1) // Avoid zooming in too much
            zoom = 0.1;
    }
    glutPostRedisplay();
}

void myKeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
    case 'm': // Increase zoom with 'm'
        zoom *= 1.1;
        break;
    case 'n': // Decrease zoom with 'n'
        zoom /= 1.1;
        if (zoom < 0.1) // Avoid zooming in too much
            zoom = 0.1;
        break;
    }
    glutPostRedisplay();
}

void motion(int x, int y) {
    rotateX += y - lastY;
    rotateY += x - lastX;
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLdouble ortho = 10 * zoom;
    glOrtho(-ortho, ortho, -ortho, ortho, -10, 10);

    glTranslatef(0.0f, 0.0f, -5.0f); // Move the scene back a bit
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f); // Rotate around x-axis
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f); // Rotate around y-axis
    // glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    objects.drawPyramid();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutCreateWindow("CS352 AmusementPark Madhav Sai");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutKeyboardFunc(myKeyboardFunc);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}