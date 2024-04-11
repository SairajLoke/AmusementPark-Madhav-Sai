#include "human.h"

double radian(double angle)
{
    double pi = 3.14159265359;
    return (angle * (pi / 180));
}

void Human::cubicalShapeBodyPart()
{
    //draw cubical body part of the human
    cubicalShape(0.545, 0.271, 0.075, 0.2725, 0.1355, 0.0375);
}

void Human::sphericalShapeBodyPart()
{
    //draw spherical body part of the human
    sphericalShape(0.545, 0.271, 0.075, 0.2725, 0.1355, 0.0375);
}

void Human::cylindricalShapeBodyPart() 
{
    //draw cylindrical body part of the human
    cylindricalShape(0.545, 0.271, 0.075, 0.2725, 0.1355, 0.0375);
}


void Human::drawHuman()
{
    int body_x = human_x, body_y = human_y, body_z = human_z;

    // mainbody
    glPushMatrix();
    // cubicalShapeBodyPart();
    glTranslatef(3,-2,0);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(1.5, 1.5, 1);
    cylindricalShapeBodyPart();
    glPopMatrix();

    
    if(sittingRollerCoaster) {

        // hand1
        glPushMatrix();
        glTranslatef(2, 9, 0);                 // translate relative to the main body of the human
        glRotatef(-60,0,0,1);
        glRotatef(90,0,1,0);
        glScalef(0.5, 0.8, 2);                 // scaling
        glTranslatef(-3, -3, -3);              // take top right corner of box to origin
        cubicalShapeBodyPart();
        glPopMatrix();

        // hand2
        glPushMatrix();
        glTranslatef(4, 9, 1.5);
        glRotatef(60,0,0,1);
        glRotatef(-90,0,1,0);
        glScalef(0.5, 0.8, 2);
        glTranslatef(-3, -3, -3);
        cubicalShapeBodyPart();
        glPopMatrix();

    }

    else {

        // hand1
        glPushMatrix();
        glTranslatef(1, 7, 1);                 // translate relative to the main body of the human
        glRotatef(hand_angle_1, 1, 0, 0);        // rotate w.r.t x axis to simulate hand movement
        glScalef(0.8, 0.8, 2);                 // scaling
        glTranslatef(-3, -3, -3);                // take top right corner of box to origin
        cubicalShapeBodyPart();
        glPopMatrix();

        // hand2
        glPushMatrix();
        glTranslatef(7, 7, 1);
        glRotatef(hand_angle_2, 1, 0, 0);
        glScalef(0.8, 0.8, 2);
        glTranslatef(-3, -3, -3);
        cubicalShapeBodyPart();
        glPopMatrix();

        // leg1
        glPushMatrix();
        glTranslatef(2, 0, 1);
        glRotatef(leg_angle_1, 1, 0, 0);
        glScalef(0.5, 4 , 0.5);
        glTranslatef(-3, -3, -3);
        cubicalShapeBodyPart();
        glPopMatrix();

        // leg2
        glPushMatrix();
        glTranslatef(5, 0, 1);
        glRotatef(leg_angle_2, 1, 0, 0);
        glScalef(0.5, 4, 0.5);
        glTranslatef(-3, -3, -3);
        cubicalShapeBodyPart();
        glPopMatrix();


        Objects obj;

        //balloon body
        materialCurve(1, 0, 0);
        glPushMatrix();
        glTranslatef(6, 15, -4);
        obj.balloon();
        glPopMatrix();

        //balloon rope
        glPushMatrix();
        glTranslatef(5, 0.5, -4);
        glScalef(1,1.7,1);
        obj.balloonLine();
        glPopMatrix();
    }    
}

void Human::move(int key, int x, int y)
{
    double delta_hand = 5, delta_leg = 10;

    switch (key)
    {
        case GLUT_KEY_UP:

            //move the human forward in the direction which he is currently facing

            human_x += (cos(radian(angle_x)));
            human_z -= (sin(radian(angle_x)));

            if(human_x>=121 || human_x<=-120) {
                human_x -= (cos(radian(angle_x)));
            }

            if(human_z>=80 || human_z<=-95) {
                human_z += (sin(radian(angle_x)));
            }
 
            if (!leg_flag)
            {
                if (!leg_coming_back)
                {
                    leg_angle_1 += delta_leg;
                    hand_angle_1 -= (delta_hand);
                    hand_angle_2 += (delta_hand);
                }
                else
                {
                    leg_angle_1 -= delta_leg;
                    hand_angle_1 += (delta_hand);
                    hand_angle_2 -= (delta_hand);
                }

                if (leg_angle_1 <= 0 && leg_coming_back)
                {
                    leg_angle_1 = leg_angle_2 = 0;
                    leg_flag = 1;
                    leg_coming_back = 0;
                }
                else if (leg_angle_1 >= 90 && !leg_coming_back)
                {
                    leg_angle_1 = 90;
                    leg_angle_2 = 0;
                    leg_flag = 0;
                    leg_coming_back = 1;
                }
            }
            else
            {
                if (!leg_coming_back)
                {
                    leg_angle_2 += delta_leg;
                    hand_angle_1 += (delta_hand);
                    hand_angle_2 -= (delta_hand);
                }
                else
                {
                    leg_angle_2 -= delta_leg;
                    hand_angle_1 -= (delta_hand);
                    hand_angle_2 += (delta_hand);
                }

                if (leg_angle_2 <= 0 && leg_coming_back)
                {
                    leg_angle_1 = leg_angle_2 = 0;
                    leg_flag = 0;
                    leg_coming_back = 0;
                }
                else if (leg_angle_2 >= 90 && !leg_coming_back)
                {
                    leg_angle_1 = 0;
                    leg_angle_2 = 90;
                    leg_flag = 1;
                    leg_coming_back = 1;
                }
            }
            break;


            
        case GLUT_KEY_DOWN:
            //move the human backward
            human_x -= (cos(radian(angle_x)));
            human_z += (sin(radian(angle_x)));
            break;

        case GLUT_KEY_LEFT:
            //turn the human anti-clockwise
            angle_x = angle_x + 5;
            if (angle_x <= -360 || angle_x >= 360)
            {
                angle_x = 0;
            }
            break;

        case GLUT_KEY_RIGHT:
            //turn the human clockwise
            angle_x = (angle_x - 5);
            if (angle_x <= -360 || angle_x >= 360)
            {
                angle_x = 0;
            }
            break;
    }
}