#ifndef LIGHT_H
#define LIGHT_H

#include "../../libs.h"
#include "../utils/utils.h"

class LightObject{
//can be Sun , Moon

public:
    string name = "SUN";
    int redeffect = 0;
    
    float LIGHT_OBJ_DIST = 100;    //from origin
    float LIGHT_OBJ_ANGLE = 0.0;  //with pos x-axis
    

    GLfloat light_ambient[4] = {0.5, 0.5, 0.5, 1.0}; 
    GLfloat light_diffuse[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat light_specular[4] = {0.5, 0.5, 0.5, 1.0};
    // GLfloat light_position[4] = {-5.0, 30, 0.0, 1.0};   //{-5.0, 30, 0.0, 1.0}; 
    // GLfloat light_position[4] = { LIGHT_OBJ_DIST*cos(LIGHT_OBJ_ANGLE),0.0, 0.0, 1.0};   //{-5.0, 30, 0.0, 1.0};
    GLfloat light_position_direction[4] = {-1.0, 0.0, 0.0, 0.0};
    GLfloat light_direction[3] ={ -1.0 ,0.0, 0.0};  //initially axis towards origin


    LightObject(string name): name(name){}
    void renderLightObject();
    void animateLightObject();
    void drawLightObjectRepresentative(std::vector<float>& , std::vector<unsigned int>& , float , int, int );
private:
};



void light();
void lighting1(float X, float Y, float Z, float intensity);
void lighting2(float X, float Y, float Z, float intensity);
void lighting3(float X, float Y, float Z, float intensity);
void lighting4(float X, float Y, float Z, float intensity);
void spotLight1();
void spotLight2();
void spotLight3();
void spotLight4();

#endif