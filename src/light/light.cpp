#include "light.h"

void light()
{
    //use of glLightfv to add lighting and shading effect
    
    GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {20.0, 50.0, 0.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void lighting1(float X, float Y, float Z, float intensity)
{
    GLfloat position[] = {X, Y, Z, 0.0}; // using directional source of light
    GLfloat noAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat whiteDiffuse[] = {intensity, intensity, intensity, 1.0f};

    glEnable(GL_LIGHT7);
    glLightfv(GL_LIGHT7, GL_POSITION, position);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, whiteDiffuse);
    glLightfv(GL_LIGHT7, GL_AMBIENT, noAmbient);
}


void lighting2(float X, float Y, float Z, float intensity)
{
    GLfloat position[] = {X, Y, Z, 0.0}; // using directional source of light
    GLfloat noAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat whiteDiffuse[] = {intensity, intensity, intensity, 1.0f};

    glEnable(GL_LIGHT6);
    glLightfv(GL_LIGHT6, GL_POSITION, position);
    glLightfv(GL_LIGHT6, GL_DIFFUSE, whiteDiffuse);
    glLightfv(GL_LIGHT6, GL_AMBIENT, noAmbient);
}

void lighting3(float X, float Y, float Z, float intensity)
{
    GLfloat position[] = {X, Y, Z, 0.0}; // using directional source of light
    GLfloat noAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat whiteDiffuse[] = {intensity, intensity, intensity, 1.0f};

    glEnable(GL_LIGHT5);
    glLightfv(GL_LIGHT5, GL_POSITION, position);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, whiteDiffuse);
    glLightfv(GL_LIGHT5, GL_AMBIENT, noAmbient);
}

void lighting4(float X, float Y, float Z, float intensity)
{
    GLfloat position[] = {X, Y, Z, 0.0}; // using directional source of light
    GLfloat noAmbient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat whiteDiffuse[] = {intensity, intensity, intensity, 1.0f};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, noAmbient);
}



void spotLight1()
{
    glPushMatrix();

    GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {-5.0, 30, 0.0, 1.0}; 

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    GLfloat spot_direction[] = {-0.5, -1, 0};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 70.0);
    glPopMatrix();
}


void spotLight2()
{
    glPushMatrix();

    GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {25.0, 30, 0.0, 1.0}; // 0.7, 4.5, 9.0

    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    GLfloat spot_direction[] = {1, -1, 0.5};
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 70.0);
    glPopMatrix();
}

void spotLight3()
{
    glPushMatrix();
    GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {25.0, 30, 10.0, 1.0}; // 0.7, 4.5, 9.0

    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT3, GL_POSITION, light_position);
    GLfloat spot_direction[] = {1, -1, 0};
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 60.0);
    glPopMatrix();
}

void spotLight4()
{
    glPushMatrix();

    GLfloat light_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {-20.0, 30, 10.0, 1.0}; // 0.7, 4.5, 9.0

    glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT4, GL_POSITION, light_position);
    GLfloat spot_direction[] = {-0.5, -1, 0};
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 60.0);
    glPopMatrix();
}