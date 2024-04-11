#ifndef RIDES_H
#define RIDES_H

#include "../../libs.h"

#include "../shapes/shapes.h"
#include "../../bmpLoader.h"
#include "../human/human.h"

struct Rides {

    GLfloat alpha;
    GLfloat theta;

    GLfloat atwAlpha;
    GLfloat atwTheta;
    
    int rideTheta;

    int carouselTheta;

    Rides() {

        alpha = 0.0; 
        theta = 0.0;

        atwAlpha = -45.0;
        atwTheta = 0.0;

        rideTheta = 0;

        carouselTheta = 0;
    }

    void rideGround();
    void rideFence();

    void aroundTheWorldSeat();
    void aroundTheWordLoops();
    void aroundTheWorld();

    void coasterRide();
    void track();
    void coasterSegment(double theta);
    void pole(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine, GLfloat height);
    void coasterPole(double theta);
    vector<double> getRollerCoasterViewRef();
    void rollerCoaster(Human* human);

    void carousel();

    void animateRides(GLboolean aroundTheWorldFlag, GLboolean rideFlag, GLboolean carouselFlag, GLboolean doorFlag);
};



#endif 