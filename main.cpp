// #include "libs.h"
#include "index.h"

double degToRad(double angle)
{
    double pi = 3.14159265359;
    return (angle * (pi / 180));
}
static int lastX, lastY;
static int rotateX = 0;
static int rotateY = 0;
double zoom = 1.0;

// void mouse(int button, int state, int x, int y) {
//     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//         lastX = x;
//         lastY = y;
//     }
//     else if (button == 4) { // Scroll up
//         zoom *= 1.1;
//     }
//     else if (button == 3) { // Scroll down
//         zoom /= 1.1;
//         if (zoom < 0.1) // Avoid zooming in too much
//             zoom = 0.1;
//     }
//     glutPostRedisplay();
// }

// void myKeyboardFunc(unsigned char key, int x, int y) {
//     switch (key) {
//     case 'm': // Increase zoom with 'm'
//         zoom *= 1.1;
//         break;
//     case 'n': // Decrease zoom with 'n'
//         zoom /= 1.1;
//         if (zoom < 0.1) // Avoid zooming in too much
//             zoom = 0.1;
//         break;
//     }
//     glutPostRedisplay();
// }

void motion(int x, int y) {
    rotateX += y - lastY;
    rotateY += x - lastX;
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}
//flags to toggle the rides
GLboolean  aroundTheWorldFlag = false, rideFlag = false, carouselFlag = false, doorFlag = false,  day = true;

//variables to track the motion of mouse
double mouse_x = -1, mouse_y = -1;
double mouse_x_prev = -1, mouse_y_prev = -1;

static double windowHeight = 1000, windowWidth = 1000;

//intensity of the diffused light
float intensity = 0;

Human* human = new Human();
Human* human2 = new Human(false,100, -40, 100);
// human2->drawHuman();

Rides* rides = new Rides();
Objects* objects = new Objects();

struct Camera {
    
    double eyeX, eyeY, eyeZ; //looking from
    double refX, refY, refZ; //looking at
    int currView;

    Camera() {
        eyeX = -10;
        eyeY = 5.0;
        eyeZ = 100;
        refX = 0;
        refY = 0;
        refZ = 0;  
    }

    void setView(int view) {

        currView = view;

        if(view == 0) {
            //world view
            eyeX = -10;
            eyeY = 5.0;
            eyeZ = 100;
            refX = 0;
            refY = 0;
            refZ = 0;  
        }

        else if(view == 1) {
            //human view
            eyeX = human->human_x - 15*cos(degToRad(human->angle_x));
            eyeY = -5;
            eyeZ = human->human_z + 15*sin(degToRad(human->angle_x));
            refX = human->human_x + 15*cos(degToRad(human->angle_x));
            refY = -10;
            refZ = human->human_z - 15*sin(degToRad(human->angle_x));
        }
        else if(view == 2) {

            // ride view
            vector<double> viewRef = rides->getRollerCoasterViewRef();

            eyeX = viewRef[0];
            eyeY = viewRef[1];
            eyeZ = viewRef[2];
            refX = viewRef[3];
            refY = viewRef[4];
            refZ = viewRef[5];

        }
    }
};

Camera* camera = new Camera();

void mouseMove(int x, int y)
{
    //function to change the view reference according to mouse motion

    mouse_x = (double)x;
    mouse_y = (double)y;

    if (mouse_x_prev == -1)
        mouse_x_prev = mouse_x;
    if (mouse_y_prev == -1)
        mouse_y_prev = mouse_y;


    double delta_x = mouse_x - mouse_x_prev;
    double delta_y = mouse_y - mouse_y_prev;

    camera->eyeX += (-delta_x);
    camera->eyeY += (-delta_y);

    mouse_x_prev = mouse_x;
    mouse_y_prev = mouse_y;
}

void mouseButton(int button, int state, int x, int y)
{
    cout<<x<<" "<<y<<" "<<state<<endl;
    int tempx=x-camera->eyeX,tempy=y-camera->eyeY;

    
    //function to handle mouse button press
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_UP)
        {
            mouse_x_prev = -1;
            mouse_y_prev = -1;
        }
    }

    //function to handle mousepad scroll for zoom functionality
    if(button == 3 || button == 4) 
    {
        if (state == GLUT_UP) return;
        // camera->refX=x;
        // camera->refY=y;
        if(button == 3) {
            //scroll up, i.e move fingers down hence zoom out
            // camera->eyeZ += 1;
            // camera->refX += tempx/100;
            // camera->refY += tempy/100;
            zoom*=1.1;
        }
        else {
            //scroll down, i.e move fingers up hence zoom in
            // camera->eyeZ -= 1;
            // camera->refX -= tempx/100;
            // camera->refY -= tempy/100;
            zoom/=1.1;
        }
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 300);
    
    //set the view reference
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // GLdouble ortho = 5 * zoom;
    // glOrtho(-ortho, ortho, -ortho, ortho, -5, 5);
    gluLookAt(camera->eyeX, camera->eyeY, camera->eyeZ, camera->refX, camera->refY, camera->refZ, 0, 1, 0);

    //enable lighting in the scene
    glEnable(GL_LIGHTING);

    //draw the sky
    glPushMatrix();
    sky(camera->eyeX + (0.05 * camera->refX), camera->eyeY + (0.05 * camera->refY), camera->eyeZ + (0.05 * camera->refZ), 250, 250, 250);
    glPopMatrix();

    glEnable(GL_DEPTH_TEST);

    //draw the four spotLights
    spotLight1();
    spotLight2();
    spotLight3();
    spotLight4();

    //generate the circular, sandy ground
    ground();

    //draw the boundary wall
    objects->walls();
    
    //draw the boundary flags
    objects->flags();

    //draw the swimming pool
    objects->drawPool();


    //draw the four lamp posts

    glPushMatrix();
    glTranslatef(-25, 0, 0);
    objects->lampPost1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 0, 0);
    objects->lampPost2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 0, 30);
    objects->lampPost3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25, 0, 30);
    objects->lampPost4();
    glPopMatrix();

    //draw the cafeteria
    glPushMatrix();
    glTranslatef(0, 0, 10);
    objects->cafeteria();
    glPopMatrix();

    //draw the scary house
    glPushMatrix();
    glTranslatef(5,-18,-60);
    glScalef(3,4,4);
    objects->scaryHouse();
    glPopMatrix();

    Human* coasterHuman = NULL;

    if(!human->sittingRollerCoaster) {
        glPushMatrix();
        glTranslatef(human->human_x, human->human_y, human->human_z);
        glScalef(0.3,0.3,0.3);
        glRotatef(-(90-human->angle_x), 0, 1, 0); // rotate w.r.t y axis to simulate orientation of human
        human->drawHuman();
        glPopMatrix();
    }
    else {
        coasterHuman = human;
        camera->setView(2);
    }
    //draw human
    glPushMatrix();
    glTranslatef(human2->human_x, human2->human_y, human2->human_z);
    glScalef(0.6,0.6,0.6);
    glRotatef(-(90-human2->angle_x), 0, 1, 0); // rotate w.r.t y axis to simulate orientation of human
    human2->drawHuman();
    glPopMatrix();

    //Draw the roller coster ride
    glPushMatrix();
    glTranslatef(-70, -5, 40);
    glTranslatef(0, 8, 0);
    glScalef(1.5, 1.5, 1.5);
    rides->rollerCoaster(coasterHuman);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70, 15, 40);
    glScalef(1.5, 1.5, 1.5);
    rides->rideFence();
    glPopMatrix();

    //Draw the around-the-world ride
    glPushMatrix();
    glTranslatef(-70, 0, -30);
    glTranslatef(0, 10, 0);
    glScalef(1.5, 1.5, 1.5);
    rides->aroundTheWorld();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-70, 15, -30);
    glScalef(1.5, 1.5, 1.5);
    rides->rideFence();
    glPopMatrix();
    

    //draw the carousel ride
    glPushMatrix();
    glTranslatef(70,10,-60);
    rides->carousel();
    glPopMatrix();

    double test_theta = -45;

    glDisable(GL_LIGHTING);

    glFlush();
    glutSwapBuffers();
}







void myKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        camera->refX -= 1.0; //look left
        break;
    case 'd':
        camera->refX += 1.0; //look right
        break;
    case 's':
        human->sittingRollerCoaster = true; //sit in roller coaster
        camera->setView(2);
        break;
    case 'e':
        human->sittingRollerCoaster = false; //exit roller coaster
        camera->setView(1);
        break;
    case 'r':
        camera->setView(0); //reset view reference
        break;
    case 'c':
        camera->setView((camera->currView  + 1)%3); //toggle view references
        break;
    case '1':
        aroundTheWorldFlag = !aroundTheWorldFlag; //toggle around-the-world ride
        break;
    case '2':
        rideFlag = !rideFlag; //toggle roller coaster ride
        break;
    case '3': 
        carouselFlag = !carouselFlag; //toggle carousel ride
        break;

    //toggle the four lamp posts
    case '6':
        if (objects->switchOne == false)
        {
            objects->switchOne = true;
            glEnable(GL_LIGHT1);
            break;
        }
        else if (objects->switchOne == true)
        {
            objects->switchOne = false;
            glDisable(GL_LIGHT1);
            break;
        }
    case '7':
        if (objects->switchTwo == false)
        {
            objects->switchTwo = true;
            glEnable(GL_LIGHT2);
            break;
        }
        else if (objects->switchTwo == true)
        {
            objects->switchTwo = false;
            glDisable(GL_LIGHT2);
            break;
        }
    case '8':
        if (objects->switchThree == false)
        {
            objects->switchThree = true;
            glEnable(GL_LIGHT3);
            break;
        }
        else if (objects->switchThree == true)
        {glutKeyboardFunc(myKeyboardFunc);
            objects->switchThree = false;
            glDisable(GL_LIGHT3);
            break;
        }
    case '9':
        if (objects->switchFour == false)
        {
            objects->switchFour = true;
            glEnable(GL_LIGHT4);
            break;
        }
        else if (objects->switchFour == true)
        {
            objects->switchFour = false;
            glDisable(GL_LIGHT4);
            break;
        }
    case 'z':
        if (objects->controlPointsFlag == false)
        {
            objects->controlPointsFlag = true;
            break;
        }
        else if (objects->controlPointsFlag == true)
        {
            objects->controlPointsFlag = false;
            break;
        }
    case 'g':
        if (doorFlag == false)
        {
            doorFlag = true;
            break;
        }
        else
        {
            doorFlag = false;
            break;
        }

    case '0':
        if (day == false)
        {
            day = true;
            lighting1(-100, 100, 100, intensity);
            lighting2(100, 100, -100, intensity);
            lighting3(-100, 100, -100, intensity);
            lighting4(100, 100, 100, intensity);
            break;
        }
        else if (day == true)
        {
            day = false;
            glDisable(GL_LIGHT0);
            break;
        }
        // increase intensity
    case 'i':
        if (intensity < 1.0)
        {
            intensity += 0.1;
            lighting1(-100, 100, 100, intensity);
            lighting2(100, 100, -100, intensity);
            lighting3(-100, 100, -100, intensity);
            lighting4(100, 100, 100, intensity);
            break;
        }
        else
        {
            intensity = 1.0;
            break;
        }
        // decrease intensity
    case 'k':
        if (intensity > 0.0)
        {
            intensity -= 0.1;
            lighting1(100, 100, 100, intensity);
            lighting2(-100, 100, 100, intensity);
            lighting3(100, 100, -100, intensity);
            lighting4(-100, 100, -100, intensity);
            break;
        }
        else
        {
            intensity = 0.0;
            break;
        }
    case 27:
        exit(1);
    }

    glutPostRedisplay();
}

void specialKeyboardFunc(int key, int x, int y)
{
    human->move(key, x, y); //handle motion of the human
    
    if(camera->currView == 1){
        camera->setView(1);
    }

    glutPostRedisplay();
}

void animate()
{
    //animate all the motions 
    rides->animateRides(aroundTheWorldFlag, rideFlag, carouselFlag, doorFlag);
    objects->animateFlag();
    glutPostRedisplay();
}

void fullScreen(int w, int h)
{
    if (h == 0)
        h = 1;
    float ratio = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, w, h);
    gluPerspective(60, ratio, 1, 500); //fov-y, aspect, zNear, zFar
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Imagica Amusement Park");
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    light();

    LoadTexture("sgi_images/grass.sgi", 2);
    LoadTexture("sgi_images/grass.sgi", 3);
    LoadTexture("sgi_images/pirate-copy.sgi", 4);
    LoadTexture("sgi_images/blue_gradient.sgi", 5);
    LoadTexture("sgi_images/baskinrobbinslogo.sgi", 6);
    LoadTexture("sgi_images/iitindore.sgi", 7);
    LoadTexture("sgi_images/dunkindonuts.sgi", 8);

    LoadTexture("sgi_images/nightsky.sgi", 9);
    LoadTexture("sgi_images/nightsky.sgi", 12);
    LoadTexture("sgi_images/nightsky.sgi", 11);
    LoadTexture("sgi_images/nightsky.sgi", 10);
    LoadTexture("sgi_images/nightsky.sgi", 28);
    LoadTexture("sgi_images/nightsky.sgi", 29);

    LoadTexture("sgi_images/skydrop.sgi", 13);
    LoadTexture("sgi_images/skydroplogo.sgi", 14);
    LoadTexture("sgi_images/spgrass.sgi", 15);

    LoadTexture("sgi_images/blue_gradient.sgi", 16);
    LoadTexture("sgi_images/pinkblue.sgi", 17);
    LoadTexture("sgi_images/baskin-robin-ad.sgi", 18);
    LoadTexture("sgi_images/de5b9e.sgi", 19);
    LoadTexture("sgi_images/pinkorange.sgi", 20);

    LoadTexture("sgi_images/ff6d0d.sgi", 21);

    LoadTexture("sgi_images/dd.sgi", 22);

    LoadTexture("sgi_images/treetext.sgi", 44);

    LoadTexture("sgi_images/abhinandan.sgi", 23);
    LoadTexture("sgi_images/bush.sgi", 24);
    // LoadTexture("sgi images/treetext.sgi", 44);
    LoadTexture("sgi_images/bushflower.sgi", 25);
    LoadTexture("sgi_images/brickwall.sgi", 26);
    LoadTexture("sgi_images/redwhite.sgi", 27);
    LoadTexture("sgi_images/treebark.sgi", 30);
    LoadTexture("sgi_images/bush.sgi", 31);
    
    // LoadTexture("sgi images/treetext.sgi", 44);
    // LoadTexture("sgi images/plant_texture1.sgi", 32);
    LoadTexture("sgi_images/tiles.sgi", 33);
    LoadTexture("sgi_images/water.sgi", 34);

    LoadTexture("sgi_images/scary.sgi", 35);
    LoadTexture("sgi_images/brick_wall.sgi", 35);
    LoadTexture("sgi_images/treetext.sgi", 44);

    glutReshapeFunc(fullScreen);
    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(specialKeyboardFunc);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMotionFunc(mouseMove);
    glutMouseFunc(mouseButton);
    glutMainLoop();

    return 0;
}
