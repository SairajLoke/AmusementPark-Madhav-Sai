#include "light.h"


//sun ---------------------
void LightObject::renderLightObject()//vector<float> sun_pos
{
    glPushMatrix();
    if( LIGHT_OBJ_ANGLE <=180 ){ glEnable(GL_LIGHT5);} //daytime
    else{glDisable(GL_LIGHT5);
            glEnable(GL_LIGHT3);
    }  //night time

    // glLightfv(GL_LIGHT5, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT5, GL_SPECULAR, light_specular);
    // glLightfv(GL_LIGHT5, GL_POSITION, light_position);
    glLightfv(GL_LIGHT5, GL_POSITION, light_position_direction);
    // glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, light_direction);


    glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 90.0);
    glPopMatrix();
}

void LightObject::animateLightObject(){

    //glutSolidSphere(5,20,20);
    if(LIGHT_OBJ_ANGLE >= 360 ){
        LIGHT_OBJ_ANGLE = 0.0;
    }
    else{
        LIGHT_OBJ_ANGLE = LIGHT_OBJ_ANGLE + 1.0 ;
    }
    
    double angle = degToRad(LIGHT_OBJ_ANGLE);
    // cout<<"angle from axis"<<angle<<endl;
    light_position_direction[0] = LIGHT_OBJ_DIST*cos(angle);
    light_position_direction[1] = LIGHT_OBJ_DIST*sin(angle);
    // light_position[2] = LIGHT_OBJ_DIST*sin(angle);
    // light_position[2] = 0.0; 

    // light_direction[0] = (0.0-light_position[0] )/LIGHT_OBJ_DIST;
    // light_direction[1] = (0.0-light_position[1] )/LIGHT_OBJ_DIST;
    // light_direction[2] = 0.0-light_position[2] ;


    // for(auto&p: light_position_direction){cout<<p<<"|";}
    // cout<<"\n";
    // for(auto&p: light_direction){cout<<p<<"@";}
    // cout<<"\n";
    // if(TIME<24*10){
    //     // light_position[0] += INCRE_POS;
    //     // light_direction[0] += INCRE_DIR;
    //     // light_direction[0] =
    //     light_direction[2] += INCRE_DIR;
    //     TIME++;
    // }
    // else{
    //     // light_position[0] = INIT_POS_X;
    //     // light_direction[0] = INIT_DIR_X;
    //     light_direction[2] = INIT_DIR_Z;
    //     TIME=0;
    // }
    

    // if(light_position[2]<MAX_POSITION){
    //     light_position[2] += 1.0;
    // }
    // else{
    //     light_position[2]= 0.0;
    // }

    return;
}

void LightObject::drawLightObjectRepresentative(std::vector<float>& vertices, std::vector<unsigned int>& indices, float radius, int rings, int sectors){

// Function to create a sphere mesh
    float const R = 1.0f / (float)(rings - 1);
    float const S = 1.0f / (float)(sectors - 1);

    for (int r = 0; r < rings; ++r) {
        for (int s = 0; s < sectors; ++s) {
            float const y = sin(-M_PI_2 + M_PI * r * R);
            float const x = cos(2 * M_PI * s * S) * sin(M_PI * r * R);
            float const z = sin(2 * M_PI * s * S) * sin(M_PI * r * R);

            vertices.push_back(x * radius);
            vertices.push_back(y * radius);
            vertices.push_back(z * radius);
        }
    }

    for (int r = 0; r < rings - 1; ++r) {
        for (int s = 0; s < sectors - 1; ++s) {
            indices.push_back(r * sectors + s);
            indices.push_back((r + 1) * sectors + (s + 1));
            indices.push_back(r * sectors + (s + 1));

            indices.push_back(r * sectors + s);
            indices.push_back((r + 1) * sectors + s);
            indices.push_back((r + 1) * sectors + (s + 1));
        }
    }


}

//--------------------------------

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