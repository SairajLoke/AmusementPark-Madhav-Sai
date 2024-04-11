#include "shapes.h"

static GLfloat cubeVertices[8][3] =
    {
        {0.0, 0.0, 0.0}, // 0
        {0.0, 0.0, 3.0}, // 1
        {3.0, 0.0, 3.0}, // 2
        {3.0, 0.0, 0.0}, // 3
        {0.0, 3.0, 0.0}, // 4
        {0.0, 3.0, 3.0}, // 5
        {3.0, 3.0, 3.0}, // 6
        {3.0, 3.0, 0.0}  // 7
};

static GLubyte quadricIndices[6][4] =
    {
        {0, 1, 2, 3}, // bottom
        {4, 5, 6, 7}, // top
        {5, 1, 2, 6}, // front
        {3, 7, 4, 0}, // back
        {2, 3, 7, 6}, // right
        {0, 4, 5, 1}  // left
};

static GLfloat boxVertices[8][3] =
    {
        {0.0, 0.0, 0.0}, // 0
        {3.0, 0.0, 0.0}, // 1
        {0.0, 0.0, 3.0}, // 2
        {3.0, 0.0, 3.0}, // 3
        {0.0, 3.0, 0.0}, // 4
        {3.0, 3.0, 0.0}, // 5
        {0.0, 3.0, 3.0}, // 6
        {3.0, 3.0, 3.0}, // 7

};

static GLubyte quadricBoxIndices[6][4] =
    {
        {0, 2, 3, 1},
        {0, 2, 6, 4},
        {2, 3, 7, 6},
        {1, 3, 7, 5},
        {1, 5, 4, 0},
        {6, 7, 5, 4}
    };


static GLfloat trapezoidVertices[8][3] =
    {
        {0.0, 0.0, 0.0}, // 0
        {0.0, 0.0, 3.0}, // 1
        {3.0, 0.0, 3.0}, // 2
        {3.0, 0.0, 0.0}, // 3
        {0.5, 3.0, 0.5}, // 4
        {0.5, 3.0, 2.5}, // 5
        {2.5, 3.0, 2.5}, // 6
        {2.5, 3.0, 0.5}  // 7
};

static GLubyte quadricTrapezoidIndices[6][4] =
    {
        {0, 1, 2, 3}, // bottom
        {4, 5, 6, 7}, // top
        {5, 1, 2, 6}, // front
        {3, 7, 4, 0}, // back
        {2, 3, 7, 6}, // right
        {0, 4, 5, 1}  // left
};

void materialProperty()
{
    glColor3f(1, 1, 1);
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {60};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1;
    Uy = y2 - y1;
    Uz = z2 - z1;

    Vx = x3 - x1;
    Vy = y3 - y1;
    Vz = z3 - z1;

    Nx = Uy * Vz - Uz * Vy;
    Ny = Uz * Vx - Ux * Vz;
    Nz = Ux * Vy - Uy * Vx;

    glNormal3f(Nx, Ny, Nz);
}


void quadricShape1()
{
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10, 4, 3);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 4, 3);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, 3);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10, 0, 3);
    glEnd();
}

void quadricShape2()
{
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0, 8, 5);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 8, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, 0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0, 0, 5);
    glEnd();
}

void materialCurve(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambfactor, GLfloat specfactor, GLfloat shine)
{
    glColor3f(1, 1, 1);
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {difX * ambfactor, difY * ambfactor, difZ * ambfactor, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {60};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
}

void cubicalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX , GLfloat ambY , GLfloat ambZ , GLfloat shine )
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {ambX, ambY, ambZ, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glBegin(GL_QUADS);

    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(cubeVertices[quadricIndices[i][0]][0], cubeVertices[quadricIndices[i][0]][1], cubeVertices[quadricIndices[i][0]][2],
                    cubeVertices[quadricIndices[i][1]][0], cubeVertices[quadricIndices[i][1]][1], cubeVertices[quadricIndices[i][1]][2],
                    cubeVertices[quadricIndices[i][2]][0], cubeVertices[quadricIndices[i][2]][1], cubeVertices[quadricIndices[i][2]][2]);
        glVertex3fv(&cubeVertices[quadricIndices[i][0]][0]);
        glVertex3fv(&cubeVertices[quadricIndices[i][1]][0]);
        glVertex3fv(&cubeVertices[quadricIndices[i][2]][0]);
        glVertex3fv(&cubeVertices[quadricIndices[i][3]][0]);
    }
    glEnd();
}

void sphericalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine)
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {ambX, ambY, ambZ, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glutSolidSphere(1.0, 16, 16);
}


void boxShape()
{
    materialProperty();
    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(boxVertices[quadricBoxIndices[i][0]][0], boxVertices[quadricBoxIndices[i][0]][1], boxVertices[quadricBoxIndices[i][0]][2],
                    boxVertices[quadricBoxIndices[i][1]][0], boxVertices[quadricBoxIndices[i][1]][1], boxVertices[quadricBoxIndices[i][1]][2],
                    boxVertices[quadricBoxIndices[i][2]][0], boxVertices[quadricBoxIndices[i][2]][1], boxVertices[quadricBoxIndices[i][2]][2]);

        glVertex3fv(&boxVertices[quadricBoxIndices[i][0]][0]);
        glTexCoord2f(1, 1);
        glVertex3fv(&boxVertices[quadricBoxIndices[i][1]][0]);
        glTexCoord2f(1, 0);
        glVertex3fv(&boxVertices[quadricBoxIndices[i][2]][0]);
        glTexCoord2f(0, 0);
        glVertex3fv(&boxVertices[quadricBoxIndices[i][3]][0]);
        glTexCoord2f(0, 1);
    }
    glEnd();
}

void toroidShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine)
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {ambX, ambY, ambZ, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glutSolidTorus(innerRadius, outerRadius, nsides, rings);
}

void cylindricalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine)
{
    GLfloat no_mat[] =   {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {ambX, ambY, ambZ, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, 1.5, 1.5, 19, 32, 32);
}


void trapezoidalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine)
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {ambX, ambY, ambZ, 1.0};
    GLfloat mat_diffuse[] = {difX, difY, difZ, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(trapezoidVertices[quadricTrapezoidIndices[i][0]][0], trapezoidVertices[quadricTrapezoidIndices[i][0]][1], trapezoidVertices[quadricTrapezoidIndices[i][0]][2],
                    trapezoidVertices[quadricTrapezoidIndices[i][1]][0], trapezoidVertices[quadricTrapezoidIndices[i][1]][1], trapezoidVertices[quadricTrapezoidIndices[i][1]][2],
                    trapezoidVertices[quadricTrapezoidIndices[i][2]][0], trapezoidVertices[quadricTrapezoidIndices[i][2]][1], trapezoidVertices[quadricTrapezoidIndices[i][2]][2]);

        glVertex3fv(&trapezoidVertices[quadricTrapezoidIndices[i][0]][0]);
        glVertex3fv(&trapezoidVertices[quadricTrapezoidIndices[i][1]][0]);
        glVertex3fv(&trapezoidVertices[quadricTrapezoidIndices[i][2]][0]);
        glVertex3fv(&trapezoidVertices[quadricTrapezoidIndices[i][3]][0]);
    }
    glEnd();
}

