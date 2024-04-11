#ifndef OBJECTS_H
#define OBJECTS_H

#include "../../libs.h"

#include "../shapes/shapes.h"
#include "../../bmpLoader.h"


const int nt = 60;
const int ntheta = 20;
const double PI = 3.14159265389;

struct Objects {

    GLboolean switchOne;
    GLboolean switchTwo;
    GLboolean switchThree;
    GLboolean switchFour;

    GLboolean xflag;
    GLboolean yflag;
    GLfloat xf ;
    GLfloat yf ;

    GLboolean controlPointsFlag;

    GLUquadric *quad;

    Objects() {
        switchOne = switchTwo = switchThree = switchFour = false;
        xflag = yflag = false;
        xf = yf = 0;
        controlPointsFlag = false;
    }

    void drawPool();

    void bush();
    void chair();
    void table();
    void DrawTree();
    void DrawUmbrella();
    void teapot();
    void diningTables();
    void tree();
    void desertShop();
    void pizzaShop();
    void scaryHouse();
    void donutsShop();
    void cafeteriaFence();
    void cafeteria();
    void DrawChristmasTree();
    void streetLampbody();
    void lampPost1();
    void lampPost2();
    void lampPost3();
    void lampPost4();

    void wall();
    void walls();
    
    void setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);
    long long nCr(int n, int r);
    void BezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3]);
    void showControlPoints(int L, GLfloat ctrlpoints[][3]);
    void balloonBezier();
    void drawFlag();
    void balloon();
    void balloonLine();
    void flagpole(int seed);
    void flags();

    void animateFlag();
};

#endif

