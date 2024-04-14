#include "objects.h"

//-------------------

void Objects::shoot_arrow(){
    

    // cout<<arrow_tip_z<<endl;
    if (arrow_currently_shot == true)
    {   
        arrow_centre_z -= 0.5;
        arrow_tip_z -= 0.5;

        
        if ( 0 >= arrow_tip_z ){ //arrow_tip_z is rel to shop
            arrow_currently_shot = false;
            // cout<<"called reset0"<<endl;
            resetArrow();
        }
        //     theta -= 360.0 * floor(theta / 360.0);

        // rideTheta = ((rideTheta - 1)%360 + 360)%360;
    }
}
void Objects::resetArrow(){
    // cout<<"reset called<<"<<endl;
    arrow_centre_x = arrow_centre_x_init;
    arrow_centre_y = arrow_centre_y_init;
    arrow_centre_z = arrow_centre_z_init;
    arrow_tip_z = arrow_centre_z_init-2;
    arrow_tip_x = arrow_centre_x;
    arrow_tip_y = arrow_centre_y;
    // arrow_dir_x = 0; //check angle
    // arrow_dir_y = 0; //
    
}

bool Objects::check_bln_arrow_intersection(ShopBalloon& ball){
    // if(ball.balloon_id == 5){cout<<"!!!!!"<<ball.x<<ball.y<<ball.z<<" | "<<arrow_tip_x<<" "<<arrow_tip_y<<endl;}
    return arrow_tip_x >= (ball.x - ball_rad +0.5)  && arrow_tip_x <= (ball.x + ball_rad+2) && //shifting x compo of intersection as x of ball is end pt of balloon
           arrow_tip_y >= (ball.y - ball_rad)  && arrow_tip_y <= (ball.y + ball_rad) &&
           arrow_tip_z >= (ball.z -4 - ball_rad)  && arrow_tip_z <= (ball.z -4 + ball_rad) ;
}

void Objects::balloonUpdater(){

    for(auto& ball : shopballoons ){
        if(check_bln_arrow_intersection(ball) )
        {
            ball.ispresent = false;
            cout<<"intersected"<<ball.balloon_id<<ball.x<<"/"<<ball.y<<"--|at---"<<arrow_tip_x<<","<<arrow_tip_y<<","<<arrow_tip_z;
            // sleep(2);
        }
    }
}

void Objects::moveArrow(int key, int x, int y)
{
    double delta_x = 1, delta_y = 1;

    switch (key)
    {
        case GLUT_KEY_UP:

            //move the human forward in the direction which he is currently facing

            arrow_tip_y += delta_y;
            arrow_centre_y += delta_y;

            if(arrow_centre_y> shop_height ) { //shop height , as arrow center y is rel to shooter_shop_y
                arrow_centre_y = shooter_shop_y;
                arrow_tip_y = shooter_shop_y;
            }
            break;


            
        case GLUT_KEY_DOWN:
            //move the human backward
         
            arrow_tip_y -= delta_y;
            arrow_centre_y -= delta_y;

            if(arrow_centre_y< 0 ) { //arrow centre y is rel to shop
                arrow_centre_y = shop_height;
                arrow_tip_y = shop_height;
            }
            break;


        case GLUT_KEY_LEFT:
            //turn the human anti-clockwise
            arrow_tip_x -= delta_x;
            arrow_centre_x -= delta_x;

            if(arrow_centre_x< 0) { ///arrow centre x is wrt shooter_shop_x
                // cout<<"shooter shop x"<<shooter_shop_x<<endl;
                arrow_centre_x = shop_width;
                arrow_tip_x = shop_width;
            }
            break;
        case GLUT_KEY_RIGHT:
            //turn the human clockwise
            arrow_tip_x += delta_x;
            arrow_centre_x += delta_x;

            if(arrow_centre_x> shop_width ) {
                arrow_centre_x = 0;
                arrow_tip_x = 0;
            }
            break;
    }
}

void Objects::draw_shop_balloons(vector<ShopBalloon>& shopballoons){
    
    // cout<<"size: "<<shopballoons.size()<<endl;
    for(auto&bln : shopballoons){
        // cout<<"balloons: "<<bln.balloon_id<<" "<<bln.ispresent<<", "<<bln.x<<" "<<bln.y<<" "<<bln.z<<endl;
        if(bln.ispresent){ balloon(0,bln.x,bln.y, bln.z);}
    }
    // cout<<endl<<endl;
}
void drawSolidCylinder(GLdouble radius, GLdouble height, GLint slices, GLint stacks) {
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluCylinder(quadric, radius, radius, height, slices, stacks);
    gluDeleteQuadric(quadric);
}

void Objects::drawArrow() {

   
    glEnable( GL_COLOR_MATERIAL ); //required for below glcolor cmd why?
    glColor3f(1,0,1);
    // Draw arrowhead (cone)
    glColor3f(1.0, 0.0, 0.0); // Red color
    glPushMatrix();
    glTranslatef(arrow_centre_x, arrow_centre_y, arrow_centre_z); // Move to the tip of the arrow
    glRotatef(-180.0, 1.0, 0.0, 0.0); 
    glScalef(0.2,0.2,0.2);
    glColor3f(1,0,0);
    glutSolidCone(2, 5, 30, 30); // Parameters: base radius, height, slices, stacks
    glPopMatrix();
    
    // Draw arrow shaft (cylinder)
    glColor3f(1,0,1); // Blue color
    glPushMatrix();
    glTranslatef(arrow_centre_x, arrow_centre_y, arrow_centre_z+2); 
    glRotatef(180.0, 1.0, 0.0, 0.0); // Rotate to make the cylinder stand up
    glScalef(0.2,0.2,0.2);
    glColor3f(1,0,0);
    drawSolidCylinder(1, 10, 30, 30); // Parameters: radius, height, slices, stacks
    glPopMatrix();


    glDisable(GL_COLOR_MATERIAL);
}

void Objects::balloonShooterStall()
{
    float ytranslate = 0;

    //function to draw a desert shop

    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, ID2[25]); //
    glPushMatrix();
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, ytranslate+11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quadricShape1();
    glPopMatrix();

    // glBindTexture(GL_TEXTURE_2D, ID2[17]);
    glPushMatrix();
    glTranslatef(0, ytranslate+0, -5);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    // glBindTexture(GL_TEXTURE_2D, ID2[18]);

    glPushMatrix();
    glTranslatef(0, ytranslate+3, -2);
    glRotatef(90, 1, 0, 0);
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, ytranslate+ 0, -2);
    quadricShape2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -2);
    quadricShape2();
    glPopMatrix();

    //top bill board plane
    glPushMatrix();
        glTranslatef(0,shop_height, -1);
        glScalef(1, 2, 1);
        quadricShape1();
    glPopMatrix();

    
    glDisable(GL_TEXTURE_2D); //if done below gives issue in text of balloons

    draw_shop_balloons(shopballoons);
    stroke_output(2, 12, 4, 0.01, 5, 0, "Balloon");
	stroke_output(1, 10, 4, 0.01, 8, 0, "Shooting");

    glPushMatrix();
    // glTranslatef(->shooter_shop_y, objects->shooter_shop_z); //10 from ground wala
    // glScalef(1, 2, 1);
    drawArrow();
    glPopMatrix();



}

void Objects::testvec(){
    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);
    //baskin and robins toward swiming pool :   pos x axis
    //up :   pos y axis
    //outward from baskin towards gate(open) : pos z axis


    float zero = 0.0;   
    // glColor3f(1.0,0.0,0.0);
    // glBegin(GL_LINES);   // straight
    // glVertex2f(100,zero);
    // glVertex2f(zero,zero);
    // glEnd();

    
    // glColor3f(0.0,1.0,0.0);
    // glBegin(GL_LINES);   // straight
    // glVertex2f(zero,100.0);
    // glVertex2f(zero,zero);
    // glEnd();


    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);   // straight
    glVertex3f(zero,zero,100.0);
    glVertex3f(zero,zero,zero);
    glEnd();

    float X1mark = 50.0;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);   // 
    glVertex3f(X1mark,0.0,zero);
    glVertex3f(X1mark,50.0,zero);
    glEnd();

    float X2mark = 200.0;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);   // 
    glVertex3f(X2mark,0.0,zero);
    glVertex3f(X2mark,50.0,zero);
    glEnd();

    // glFlush();
}
void Objects::balloon(int type, float x, float y, float z)
{
    if (type == 0){
        //function to draw a balloon
        glEnable( GL_COLOR_MATERIAL ); //required for below glcolor cmd why?
        glColor3f(0,1,0);
        // materialCurve(1, 0, 0);
        glPushMatrix();
        // glRotatef(90, 0, 0, 1);
        glTranslatef(x,y,z);
        glScalef(1, 1, 2);
        balloonBezier();
        glPopMatrix();
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        //function to draw a balloon
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glScalef(2, 2.5, 2);
        balloonBezier();
        glPopMatrix();
    }   
    
}

void Objects::balloon(int type)
{
    if (type == 0){
        //function to draw a balloon
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glScalef(1, 1, 1);
        balloonBezier();
        glPopMatrix();
    }
    else{
        //function to draw a balloon
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glScalef(2, 2.5, 2);
        balloonBezier();
        glPopMatrix();
    }   
    
}

//------------------

void Objects::drawPool()
{
    //function to draw a swimming pool

    int tx = -115, ty = 5, tz = 15;

    // right side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(200, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(200, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // left side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(175, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // front side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, 25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // back side
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, -25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // bottom
    // glColor4f(0.5,0.77,0.87,0.8);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[32]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -40, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -40, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -40, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -40, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // water
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[33]);
    glPushMatrix();
    glTranslatef(tx, ty, tz);
    materialProperty();
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(175, -20, 25);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(175, -20, -25);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(200, -20, -25);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(200, -20, 25);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::bush()
{
    //function to draw a bush

    quad = gluNewQuadric();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[24]);
    glPushMatrix();
    gluQuadricTexture(quad, 1);
    gluSphere(quad, 1, 100, 100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::chair()
{
    //function to draw a chair

    // seat part
    glPushMatrix();
    glScalef(0.5, 0.05, 0.5);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat left back
    glPushMatrix();
    glTranslatef(0, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat right back
    glPushMatrix();
    glTranslatef(1.35, -1.5, 0);
    glScalef(0.05, 1.4, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat horizontal up back
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(0.5, 0.05, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat left front leg
    glPushMatrix();
    glTranslatef(0, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();

    // seat right front leg
    glPushMatrix();
    glTranslatef(1.35, -1.5, 1.3);
    glScalef(0.05, .55, 0.05);
    cubicalShape(0.8, 0.2, 0.4, 0, 0.6, 0.6);
    glPopMatrix();
}

void Objects::table()
{
    //function to draw a table

    // table
    glPushMatrix();
    glTranslatef(-2.5, 0, -2);
    glScalef(1.6, 0.3, 1.6);
    cubicalShape(0.8, 0.4, 0.00, 0.3, 0.5, 0.5);
    glPopMatrix();

    // stand
    glPushMatrix();
    glScalef(0.1, -1, -0.1);
    cubicalShape(0, 0, 0, 0.3, 0.5, 0.5);
    glPopMatrix();

    // stand bottom
    glPushMatrix();
    glTranslatef(0, -2.8, 0);
    glScalef(1, 0.2, 1);
    sphericalShape(1, 0.549, 0.00, 0.3, 0.5, 0.5);
    glPopMatrix();
}

void Objects::DrawUmbrella(void)
{
    //function to draw an umbrella

    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL);

    glColor4ub(255, 20, 20, 255);

    // moving the umbrella 20 units above the table
    glTranslatef(0, 12.5, 0);

    glRotatef(90, 1.0f, 0.0f, 0.0f);
    glRotatef(0, 0.0f, 1.0f, 0.0f);
    gluCylinder(qobj, 0, 6, 6, 10, 1);      // Canopy
    gluCylinder(qobj, 0.2, 0.5, 45, 10, 1); // Pole

    gluDeleteQuadric(qobj);
}

void Objects::DrawTree(void)
{
    // GLfloat no_mat[] = {0.4, 0.3, 0.2, 1.0};
    // GLfloat mat_ambient[] = {0.5, 0.2, 0.6, 1.0};
    GLfloat mat_ambient_color[] = {0.0, 0.0, 1.0, 0.0};
    // GLfloat mat_diffuse[] = {1.000, 0.443, 0.100, 1.0};
    GLfloat high_shininess[] = {100.0};
    // GLfloat mat_emission[] = {1, 1, 1, 1.0};
    
    // Draw trunk
    glColor4ub(139, 69, 19, 255); // Brown color
    glPushMatrix();
    // glTranslatef(0, -5,0); // Move the trunk slightly below the origin
    glRotatef(-90, 1, 0, 0); // Rotate the trunk to be vertical
    glScalef(1, 1, 3); // Make the trunk longer
    glutSolidCube(2); // Draw a simple cube as the trunk
    glPopMatrix();

    // Draw branches
    glColor4ub(0, 100, 0, 255); // Green color
    glPushMatrix();
    glTranslatef(0, 4, 0); // Move to the top of the trunk
    glRotatef(-90, 1, 0, 0); // Rotate to start drawing branches
    glScalef(0.5, 0.5, 1); // Scale down branches
    glutSolidCube(3); // Draw a simple cube as the branch
    glPopMatrix();

    // Draw leaves
    glColor4ub(34, 139, 34, 255); // Dark Green color
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    // glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glTranslatef(0, 10,0); // Move to the top of the trunk
    glRotatef(-90, 1, 0, 0); // Rotate to be perpendicular to the trunk
    glutSolidSphere(5, 20, 20); // Draw a sphere as the leaves
    glPopMatrix();
}

// void Objects::DrawChristmasTree(void)
// {
//     glEnable(GL_TEXTURE_2D);
//     // Draw the top of the tree (a cone as leaves)
//     glBindTexture(GL_TEXTURE_2D, ID2[44]);
//     // GLUquadricObj *qobj;
//     // qobj = gluNewQuadric();
//     // gluQuadricDrawStyle(qobj, GLU_FILL);
//     // Draw trunk
//     // glColor4ub(139, 69, 19, 255); // Brown color
//     // glColor3f(0.0f,1.0f,0.0f);
//     glPushMatrix();
//     glTranslatef(0, 4, 0); // Move the trunk slightly below the origin
//     glRotatef(-90, 1, 0, 0); // Rotate the trunk to be vertical
//     glScalef(1, 1, 10); // Make the trunk longer
//     glutSolidCube(2); // Draw a simple cube as the trunk
//     glPopMatrix();

//     // Draw layers of branches
//     // glColor4ub(0, 100, 0, 255); // Green color
//     // for (int i = 0; i < 3; ++i) {
//     //     glPushMatrix();
//     //     glTranslatef(0, 4 + i * 4, 0); // Move to the top of the trunk
//     //     // glRotatef(-90, 1, 0, 0); // Rotate to start drawing branches
//     //     glScalef(1.5 - 0.5 * i, 1.5 - 0.5 * i, 1); // Scale down branches
//     //     glutSolidCube(3); // Draw a simple cube as the branch
//     //     glPopMatrix();
//     // }
//     // glEnable(GL_TEXTURE_2D);
//     // Draw the top of the tree (a cone as leaves)
//     // glBindTexture(GL_TEXTURE_2D, ID2[44]);
//     glColor4ub(34, 139, 34, 255); // Dark Green color
//     glPushMatrix();
//     glTranslatef(0, 12, 0); 
//     glRotatef(-90, 1, 0, 0); // Move to the top of the trunk
//     glutSolidCone(5, 30, 4, 20); // Draw a cone as the leaves
    
//     glPopMatrix();
//     glDisable(GL_TEXTURE_2D);
//     // gluDeleteQuadric(qobj);
//     // Draw a star at the top
//     // glColor4ub(255, 255, 0, 255); // Yellow color
//     // glPushMatrix();
//     // glTranslatef(0, 15, 0); // Move to the top of the tree
//     // // glutSolidStar(5, 10, 5); // Draw a star
//     // glPopMatrix();
// }


void Objects::DrawChristmasTree(void)
{
    

    // Bind texture for leaves
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[42]);
    glTexCoord2f(0.5f, 0.5f);
    // Draw the trunk (brown)
    // glColor4ub(139, 69, 19, 255); // Brown color
    glPushMatrix();
    glTranslatef(0, 4, 0);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCube(2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    // Draw the leaves (green)
    glBindTexture(GL_TEXTURE_2D, ID2[44]);
    

    // glColor4ub(34, 139, 34, 255); // Green color
    glPushMatrix();
    glTranslatef(0, 12, 0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(5, 30, 4, 20);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}



void Objects::teapot(void)
{
    //function to draw a teapot

    glColor3f(1, 0.9725, 0.9059);
    glPushMatrix();
    glTranslatef(1,1,11);
    glScaled(10, 10, 10);
    glRotatef(90, -1, 0, 0);
    glutSolidTeapot(0.1);
    glPopMatrix();
}

void Objects::diningTables()
{
    //function to draw a dining set with a table, chairs, umbrella and teapot

    glPushMatrix();
    glTranslatef(0, -16, 0);
    table();
    DrawUmbrella();
    teapot();
    glPopMatrix();

    for (int i = 0; i <= 360; i += 90)
    {
        glPushMatrix();
        glRotatef(i, 0, 1, 0);
        glTranslatef(-0.75, -17, -4);
        chair();
        glPopMatrix();
    }
}

void Objects::desertShop()
{
    //function to draw a desert shop

    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, ID2[16]);
    glPushMatrix();
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[17]);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[18]);

    glPushMatrix();
    glTranslatef(0, 3, -2);
    glRotatef(90, 1, 0, 0);
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -2);
    quadricShape2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -2);
    quadricShape2();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[5]);
    glPushMatrix();
    glTranslatef(0, 6, 1);
    glScalef(1, 0.5, 1);
    quadricShape1();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void Objects::pizzaShop()
{
    //function to draw a pizza shop

    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, ID2[15]);
    glPushMatrix();
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[15]);
    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[22]);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[4]);
    glPushMatrix();
    glTranslatef(0, 3, -2);
    glRotatef(90, 1, 0, 0);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[4]);
    glPushMatrix();
    glTranslatef(0, 0, -2);
    quadricShape2();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[4]);
    glPushMatrix();
    glTranslatef(10, 0, -2);
    quadricShape2();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[6]);
    glPushMatrix();
    glTranslatef(0, 6, 1);
    glScalef(1, 0.5, 1);
    quadricShape1();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void Objects::donutsShop()
{
    //function to draw a donut shop

    materialProperty();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, ID2[19]);
    glPushMatrix();
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.5, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[21]);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 3, -2);
    glRotatef(90, 1, 0, 0);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[44]);
    glPushMatrix();
    glTranslatef(0, 6, 1);
    glScalef(1, 0.5, 1);
    quadricShape1();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, ID2[20]);
    glPushMatrix();
    glTranslatef(0, 0, -2);
    quadricShape2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10, 0, -2);
    quadricShape2();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Objects::scaryHouse()
{
    //function to draw a scary house

    materialProperty();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(70,0,50);
    glScalef(2, 2, 2);
    glRotatef(-90,0,1,0);
    // Front
    glBindTexture(GL_TEXTURE_2D, ID2[34]);
    glPushMatrix();
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    // Top
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 11, -2);
    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.25, 1);
    quadricShape1();
    glPopMatrix();

    // Back
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 2, 1);
    quadricShape1();
    glPopMatrix();

    // Left
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(0, 0, -2);
    quadricShape2();
    glPopMatrix();

    // Right
    glBindTexture(GL_TEXTURE_2D, ID2[35]);
    glPushMatrix();
    glTranslatef(10, 0, -2);
    quadricShape2();
    glPopMatrix();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::cafeteriaFence()
{
    //function for the cafeteria fence

    for (float i = -12; i <= 24; i += 4)
    {
        glPushMatrix();
        glTranslatef(-15.5, -17, i);
        glScalef(1, 2, 1);
        bush();
        glPopMatrix();
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[25]);

    glPushMatrix();
    glTranslatef(-17, -20, -16.5);
    glScalef(1, 0.5, 15);
    boxShape();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Objects::cafeteria()
{
    //function for the cafeteria fence consisting of dining tables, a pizza shop
    //a desert shop, and a donuts shop

    for (float i = -4; i <= 32; i += 18)
    {
        for (float j = 2; j <= 26; j += 24)
        {
            glPushMatrix();
            glTranslatef(i, 10, j);
            glScalef(1, 1.5, 1);
            diningTables();
            glPopMatrix();
        }
    }

    glPushMatrix();
    glTranslatef(5, -18, -25);
    glScalef(1.5, 2, 1);
    pizzaShop();
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-12, -18, -25);
    // glScalef(1.5, 2, 1);
    // desertShop();
    // glPopMatrix();
    glPushMatrix();
    glTranslatef(-12, -18, -25);
    glScalef(1, 1, 1); //this scale was messing up with my calcs for balloon popping wth!
    balloonShooterStall();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22, -18, -25);
    glScalef(1.5, 2, 1);
    donutsShop();
    glPopMatrix();

    cafeteriaFence();

    glPushMatrix();
    glTranslatef(58, 0, 0);
    cafeteriaFence();
    glPopMatrix();
}

void Objects::wall()
{
    //function to draw the single unit of the wall

    materialProperty();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[31]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(10, 10, 3);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 10, 3);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, 3);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(10, 0, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Objects::tree()
{
    //function to draw a bush

    quad = gluNewQuadric();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[43]);
    glPushMatrix();
    // gluQuadricTexture(quad, 1);
    // gluSphere(quad, 1, 200, 200);
    DrawUmbrella();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void Objects::walls()
{
    //function to draw the wall boundary
    // glEnable(GL_TEXTURE_2D);
    // glBindTexture(GL_TEXTURE_2D, ID2[43]);
    //first part in front
    for (float i = -360; i <= -20; i += 14)
    {
        glPushMatrix();
        glTranslatef(i, -20, 320);
        // wall();
        DrawChristmasTree();
        // DrawUmbrella();
        // tree();
        glPopMatrix();
    }

    //second part in front
    for (float i = 20; i <= 360; i += 14)
    {
        glPushMatrix();
        glTranslatef(i, -20, 320);
        // wall();
        DrawChristmasTree();
        glPopMatrix();
    }

    
    //back part
    for (float i = -360; i <= 360; i += 14)
    {
        glPushMatrix();
        glTranslatef(i, -20, -400);
        // wall();
        glScalef(1.4,1.1,1.4);
        DrawChristmasTree();
        glPopMatrix();
    }

    //left side
    for (float i = -395; i <= 315; i += 20)
    {
        glPushMatrix();
        glTranslatef(-300, -20, i);
        glScalef(1.6,3.5,1.6);
        glRotatef(90, 0, 1, 0);
        // wall();
        DrawTree();
        glPopMatrix();
    }

    //right side
    for (float i = -395; i <= 315; i += 20)
    {
        glPushMatrix();
        
        glTranslatef(300, -20, i);
        glScalef(1.6,3.5,1.6);
        glRotatef(90, 0, 1, 0);
        // wall();
        DrawTree();
        glPopMatrix();
    }
    // for (int i = 0; i < 100; i++) {
    // int xax, zax;
    // do {
    //     xax = rand() % 1200 - 600; // Generate random x within [-600, 600]
    //     zax = rand() % 1200 - 600; // Generate random z within [-600, 600]
    // } while (xax*xax + zax*zax >= 360000 || (xax <= 360 && xax >= -360) || (zax <= 400&& zax >= -340));

    // glPushMatrix();
    // glTranslatef(xax, -20, zax);
    // double sx = double(rand() % 100 + 100) / 100.0;
    // double sy = double(rand() % 100 + 100) / 100.0;
    // double sz = double(rand() % 100 + 100) / 100.0;
    // glScalef(sx, sy, sz);
    // DrawChristmasTree();
    // glPopMatrix();
    // }

    for (int i = 0; i < 500; i++) {
    int xax, zax;
    double randVal = (double)rand() / RAND_MAX; 

    if (randVal > 0.75) {
       
        do {
            xax = rand() % 1200 - 600; 
            zax = rand() % 1200 - 600; 
        } while (xax*xax + zax*zax >= 360000 || (xax <= 360 && xax >= -360) || (zax <= 400&& zax >= -340));
    } else {
        
        do {
            xax = rand() % 1200 - 600; 
            zax = rand() % 1200 - 600; 
        } while (xax*xax + zax*zax >= 360000 || (abs(xax) <= 360 && abs(zax) <= 360));
    }

    glPushMatrix();
    glTranslatef(xax, -20, zax);
    double sx = double(rand() % 100 + 100) / 100.0;
    double sy = double(rand() % 100 + 100) / 100.0;
    double sz = double(rand() % 100 + 100) / 100.0;
    glScalef(sx, sy, sz);
    DrawChristmasTree();
    glPopMatrix();
    }



    
    // glDisable(GL_TEXTURE_2D);
}

void Objects::streetLampbody()
{
    //function to draw the body of the lamp post

    //top of the lamp
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2, 0.2, 0.2);
    toroidShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 2, 5, 32, 64);
    glPopMatrix();

    //cylindrical rod of the lamp
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glScalef(0.5, 0.5, 1);
    cylindricalShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05);
    glPopMatrix();

    //bottom of the lamp
    glPushMatrix();
    glTranslatef(0, -19, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2, 0.2, 0.2);
    toroidShape(0.1, 0.1, 0.1, 0.05, 0.05, 0.05, 2, 5, 32, 64);
    glPopMatrix();
}

void Objects::lampPost1()
{

    GLfloat no_mat[] = {0.4, 0.3, 0.2, 1.0};
    GLfloat mat_ambient[] = {0.5, 0.2, 0.6, 1.0};
    GLfloat mat_ambient_color[] = {0.2, 0.5, 0.4, 1.0};
    GLfloat mat_diffuse[] = {1.000, 0.443, 0.100, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchOne == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost2()
{
    GLfloat no_mat[] = {0.4, 0.2, 0.0, 1.0};
    GLfloat mat_ambient[] = {0.3, 0.3, 0.5, 1.0};
    GLfloat mat_ambient_color[] = {0.5, 0.5, 0.0, 1.0};
    GLfloat mat_diffuse[] = {0.000, 0.543, 0.100, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchTwo == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost3()
{

    GLfloat no_mat[] = {0.0, 1.0, 0.4, 1.0};
    GLfloat mat_ambient[] = {0.2, 0.2, 0.1, 1.0};
    GLfloat mat_ambient_color[] = {0.4, 0.6, 0.5, 1.0};
    GLfloat mat_diffuse[] = {0.000, 0.843, 0.000, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchThree == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}

void Objects::lampPost4()
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
    GLfloat mat_diffuse[] = {1.000, 0.843, 0.000, 1.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {1, 1, 1, 1.0};

    glPushMatrix();
    glTranslatef(0, 2, 0);
    glScalef(2, 2, 2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    if (switchFour == true)
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    }
    else
    {
        glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    }
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    streetLampbody();
}



void Objects::setNormal(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
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

    glNormal3f(-Nx, -Ny, -Nz);
}

long long Objects::nCr(int n, int r)
{
    if (r > n / 2)
        r = n - r; 
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void Objects::BezierCurve(double t, float xy[2], int L, GLfloat ctrlpoints[][3])
{
    double y = 0;
    double x = 0;
    t = t > 1.0 ? 1.0 : t;
    for (int i = 0; i <= L; i++)
    {
        int ncr = nCr(L, i);
        double oneMinusTpow = pow(1 - t, double(L - i));
        double tPow = pow(t, double(i));
        double coef = oneMinusTpow * tPow * ncr;
        x += coef * ctrlpoints[i][0];
        y += coef * ctrlpoints[i][1];
    }
    xy[0] = float(x);
    xy[1] = float(y);
}

void Objects::showControlPoints(int L, GLfloat ctrlpoints[][3])
{
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <= L; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
}

void Objects::balloonBezier()
{
    int L = 5;
    GLfloat balloonctrlpoints[6][3] = {{0.0, 0.0, 0.0}, {0.7, 0.8, 0}, {2, 0.9, 0}, {2.3, 0.5, 0}, {2.5, 0.1, 0}, {2.4, 0, 0}};

    int i, j;
    float x, y, z, r;     // current coordinates
    float x1, y1, z1, r1; // next coordinates
    float theta;

    const float startx = 0, endx = balloonctrlpoints[L][0];
    // number of angular slices
    const float dx = (endx - startx) / nt; // x step size
    const float dtheta = 2 * PI / ntheta;  // angular step size

    float t = 0;
    float dt = 1.0 / nt;
    float xy[2];
    BezierCurve(t, xy, 5, balloonctrlpoints);
    x = xy[0];
    r = xy[1];
    // rotate about z-axis
    float p1x, p1y, p1z, p2x, p2y, p2z;
    for (i = 0; i < nt; ++i) // step through x
    {
        theta = 0;
        t += dt;
        BezierCurve(t, xy, 5, balloonctrlpoints);
        x1 = xy[0];
        r1 = xy[1];

        // draw the surface composed of quadrilaterals by sweeping theta
        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= ntheta; ++j)
        {
            theta += dtheta;
            double cosa = cos(theta);
            double sina = sin(theta);
            y = r * cosa;
            y1 = r1 * cosa; // current and next y
            z = r * sina;
            z1 = r1 * sina; // current and next z

            // edge from point at x to point at next x
            glVertex3f(x, y, z);

            if (j > 0)
            {
                setNormal(p1x, p1y, p1z, p2x, p2y, p2z, x, y, z);
            }
            else
            {
                p1x = x;
                p1y = y;
                p1z = z;
                p2x = x1;
                p2y = y1;
                p2z = z1;
            }
            glVertex3f(x1, y1, z1);
            // forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } 

    if (controlPointsFlag == true)
    {
        showControlPoints(L, balloonctrlpoints);
    }
}

void Objects::drawFlag()
{
    //function to draw a flag

    int L = 3;
    GLfloat ctrlpoints1[4][3] =
        {
            {0, 0, 0}, {3.5, 0 + yf, 0}, {3.5, 0 - yf, 0}, {7 + xf, 0, 0}};

    GLfloat ctrlpoints2[4][3] =
        {
            {0, 5, 0}, {3.5, 5 + yf, 0}, {3.5, 5 - yf, 0}, {7 + xf, 5, 0}};
    int i;
    
    float x1, y1, x2, y2; // current coordinates
    const float startx = 0, endx = ctrlpoints1[L][0];
    float t = 0;
    float xy1[2];
    float xy2[2];
    float dt = 1.0 / nt;
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < nt; i++)
    {
        BezierCurve(t, xy1, L, ctrlpoints1);
        x1 = xy1[0];
        y1 = xy1[1];
        glVertex3f(x1, y1, 0);
        BezierCurve(t, xy2, L, ctrlpoints2);
        x2 = xy2[0];
        y2 = xy2[1];
        glVertex3f(x2, y2, 0);
        t += dt;
    }

    glEnd();

    if (controlPointsFlag == true)
    {
        showControlPoints(L, ctrlpoints1);
        showControlPoints(L, ctrlpoints2);
    }
}

// void Objects::balloon()
// {
//     //function to draw a balloon
//     glPushMatrix();
//     glRotatef(90, 0, 0, 1);
//     glScalef(2, 2.5, 2);
//     balloonBezier();
//     glPopMatrix();
// }

void Objects::balloonLine()
{
    //function to draw the rope attached to the balloon
    materialCurve(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(1, 10);
    glVertex2f(1, 1);
    glEnd();
}

void Objects::flagpole(int seed)
{
    //function to draw the flag 
    glPushMatrix();
    glTranslatef(0, 5.5, 0);
    glRotatef(90, 1, 0, 0);
    glScalef(0.2, 0.2, 1.5);
    cylindricalShape(1, 0, 0, 0.5, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5.5, 0);
    glScalef(0.5, 0.5, 0.5);
    sphericalShape(.502, 0, 0, 0.26, 0, 0);
    glPopMatrix();

    srand(seed);

    float r1 = float(rand()) / float(RAND_MAX);
    float r2 = float(rand()) / float(RAND_MAX);
    float r3 = float(rand()) / float(RAND_MAX);

    materialCurve(r1, r2, r3);
    drawFlag();
}

void Objects::flags()
{
    //function to draw the flag boundary

    for (float i = -60; i <= 80; i += 15)
    {
        glPushMatrix();
        glTranslatef(-115, -2, i);
        flagpole(i);
        glPopMatrix();
    }

    for (float i = -60; i <= 80; i += 15)
    {
        glPushMatrix();
        glTranslatef(120, -2, i);
        flagpole(i);
        glPopMatrix();
    }
}

void Objects::animateFlag()
{
    //function to animate the waving motion of the flag
    
    if (yflag == true)
    {
        yf += 0.1;
        if (yf >= 2)
        {
            yflag = false;
        }
    }
    else
    {
        yf -= 0.1;
        if (yf <= -2)
        {
            yflag = true;
        }
    }

    if (xflag == true)
    {
        xf += 0.1;
        if (xf >= 0.6)
        {
            xflag = false;
        }
    }
    else
    {
        xf -= 0.1;
        if (xf <= -0.6)
        {
            xflag = true;
        }
    }
}