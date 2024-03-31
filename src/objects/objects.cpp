#include "objects.h"


void Objects::drawPyramid() {
    glBegin(GL_TRIANGLES);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(0.0f, 1.0f, 0.0f); // Top
    glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom left
    glVertex3f(1.0f, -1.0f, 1.0f); // Bottom right

    // Right face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(0.0f, 1.0f, 0.0f); // Top
    glVertex3f(1.0f, -1.0f, 1.0f); // Bottom left
    glVertex3f(1.0f, -1.0f, -1.0f); // Bottom right

    // Back face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(0.0f, 1.0f, 0.0f); // Top
    glVertex3f(1.0f, -1.0f, -1.0f); // Bottom left
    glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom right

    // Left face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(0.0f, 1.0f, 0.0f); // Top
    glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom left
    glVertex3f(-1.0f, -1.0f, 1.0f); // Bottom right
    glEnd();

    // Base of the pyramid
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-1.0f, -1.0f, 1.0f); // Top left
    glVertex3f(1.0f, -1.0f, 1.0f); // Top right
    glVertex3f(1.0f, -1.0f, -1.0f); // Bottom right
    glVertex3f(-1.0f, -1.0f, -1.0f); // Bottom left
    glEnd();
}
