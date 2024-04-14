#ifndef OBJECTS_H
#define OBJECTS_H

#include "../../libs.h"

#include "../shapes/shapes.h"
#include "../../bmpLoader.h"


const int nt = 60;
const int ntheta = 20;
const double PI = 3.14159265389;


class ShopBalloon{

public: 
    float x = 0;
    float y = 0;
    float z = 0;
    int balloon_id = 0;
    bool ispresent = true;
    // color 

    ShopBalloon(){}
    ShopBalloon(float x, float y, float z, int balloon_id, bool ispresent): x(x), y(y), z(z), balloon_id(balloon_id), ispresent(ispresent){}
    // ShopBalloon( const ShopBalloon& other): x(other.x), y(other.y), z(other.z){  //const as i am passing by reference
    //     cout<<"Copyied "<<x<<" "<<y<<" "<<z<<'\n';
    // }

};

struct Objects {

    //balloon additions
    bool shooting_mode = false;
    bool arrow_currently_shot = false;
    vector<ShopBalloon> shopballoons;
    
    GLfloat shooter_shop_x = -12;  //rel to world
    GLfloat shooter_shop_y = -18;
    GLfloat shooter_shop_z = -15;
    GLfloat shooting_angle_x = 90; 
    GLfloat shop_width = 8;
    GLfloat shop_height = 6;

    // float balloon_shop_z = -15;

    float arrow_centre_x_init = 4; //relative to shop origin
    float arrow_centre_y_init = 3;
    float arrow_centre_z_init = 20;
    float arrow_tip_x = arrow_centre_x_init;
    float arrow_tip_y = arrow_centre_y_init;
    float arrow_tip_z = arrow_centre_z_init-2;  //rel to the front face of wall
    float ball_rad = 0.5;
    
    float arrow_dir_x_init = 0; //check angle
    float arrow_dir_y_init = 0; //

    float arrow_centre_x = arrow_centre_x_init;
    float arrow_centre_y = arrow_centre_y_init;
    float arrow_centre_z = arrow_centre_z_init;
    float arrow_dir_x = arrow_dir_x_init ; //check angle
    float arrow_dir_y = arrow_dir_y_init; //
    


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

        float front_plane_balloon_zdelta = 4.0;//rel to the shop 
        int temp_balloon_id = 0;
        for (float x = 0 ; x < 9 ; x+=4){
            for(float y = 0 ; y < 9 ; y+=3){
                shopballoons.emplace_back(x,y,front_plane_balloon_zdelta,temp_balloon_id,true);
                temp_balloon_id++;
            }
        }
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
    void balloon(int);
    void balloonLine();
    void flagpole(int seed);
    void flags();

    void animateFlag();

    void draw_shop_balloons(vector<ShopBalloon>&);
    void shoot_arrow();
    void balloonShooterStall();
    vector<double> getBalloonShooterViewRef();
    void drawArrow();
    void resetArrow();
    void balloonUpdater();
    bool check_bln_arrow_intersection(ShopBalloon& ball );
    void moveArrow(int key, int x, int y);
    void testvec();
    void balloon(int type, float x, float y, float z);
};

#endif

