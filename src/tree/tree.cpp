#include "tree.h"
int ptr = 0;
int flag=1;
int randomNumbers[100000];
int maxDepth;
// voidglutSolidCylinder(GLdouble radius, GLdouble height, GLint slices, GLint stacks) {
//     GLUquadricObj* quadric = gluNewQuadric();
//     gluQuadricDrawStyle(quadric, GLU_FILL);
//     gluCylinder(quadric, radius, radius, height, slices, stacks);
//     gluDeleteQuadric(quadric);
// }
int getRandomNumber()
{
    ptr++;
    return randomNumbers[ptr - 1];
}
void drawLeaves(float branchLength){
    // we want tiny spiky leaves
    // they will be uniformly distributed across the branch
    // mostly the terminal branch
    float currentLength = 0;

}
void drawBranch(float parentLength, float parentRadius, int depth, int branchingFactor, float altitude, float zAngle)
{

    if (depth > maxDepth)
        return;
    float branchRadius = parentRadius * (depth) / (depth + 1);
    float branchLength = parentLength * (depth) / (depth + 1);
    float phi = static_cast<float>(rand() % 361 - 180);
    float theta = static_cast<float>(rand() % 121 - 60);
    glPushMatrix();
    glRotatef(theta, 1, 0, 0);
    glPushMatrix();
    glRotatef(phi, 0, 0, 1);
    // 50-50 chance of branching and terminating
    glColor3f(105.0 / 255.0, 75.0 / 255.0, 55.0 / 255.0);
    if (rand() > RAND_MAX / 3)
    {
        // we want to draw a cylinder representing this branch
       glutSolidCylinder(branchRadius, branchLength, 8, 8);

        // in this context we want to draw branchingFactor branches
        for (int i = 0; i < branchingFactor; i++)
        {
            // calculate and do shift from branch base
            float heightFromBase = (0.5f + (getRandomNumber() * 1.0f / RAND_MAX) * 0.5f) * branchLength;
            glPushMatrix();
            glTranslatef(0, 0, heightFromBase);
            drawBranch(branchLength, branchRadius, depth + 1, branchingFactor, altitude + heightFromBase * cos(zAngle), zAngle + theta);
            glPopMatrix();
        }
        // glEnable(GL_TEXTURE_2D);
        // glBindTexture(GL_TEXTURE_2D, ID2[44]);
        glPushMatrix();
        // glClearColor(05.0 / 255.0, 75.0 / 255.0, 55.0 / 255.0, 1.0f);
        glTranslatef(0, 0, branchLength);
        glColor3f(105.0 / 255.0, 75.0 / 255.0, 55.0 / 255.0);
        glutSolidCone(branchRadius, branchLength, 8, 8);

        glColor3ub(95, 150 * atan (depth), 68);
        // glColor3ub(0, 255, 0);
        glTranslatef(0, 0, branchLength);
        glutSolidSphere(atan(altitude) * branchRadius * 2, 8, 8); // for fruits.
        glTranslatef(0, 0, -branchLength);

        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
    else
    {   
        glColor3ub(105, 75, 55);
        glutSolidCone(branchRadius, branchLength, 8, 8);

        glColor3ub(95, 150 * atan( depth), 68);
        glTranslatef(0, 0, branchLength);
        glutSolidSphere(atan(altitude) * branchRadius * 2, 8, 8); // for fruits.
        glTranslatef(0, 0, -branchLength);
    }

    glPopMatrix();
    glPopMatrix();
}





void drawTree(int seed, int depth)
{
    ptr = seed;
    maxDepth = depth;
    GLfloat radius = 5, height = 100;
    int branchingFactor = 3;

    glColor3f(105.0 / 255.0, 75.0 / 255.0, 55.0 / 255.0);

    glPushMatrix();
    glRotatef(90, -1, 0, 0);

   glutSolidCylinder(radius, height, 30, 30);

    for (int i = 0; i < branchingFactor; i++)
    {
        float heightFromBase = (0.5f + ((getRandomNumber() * 0.5f) / RAND_MAX)) * height;
        // float heightFromBase = 0;
        // glPushMatrix();
        glTranslatef(0, 0, heightFromBase);
        glColor3f(105.0 / 255.0, 75.0 / 255.0, 55.0 / 255.0);
        drawBranch(height, radius * 2, 1, branchingFactor, heightFromBase, 0);
        glTranslatef(0, 0, -heightFromBase);
        // glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(0, 0, height);
     
    drawBranch(height, radius * 2, 1, branchingFactor, height, 0);
    glPopMatrix();
    glPopMatrix();
}
