#ifndef SHAPES_H
#define SHAPES_H

#include "../../libs.h"

void materialProperty();

// prints text
// ref. https://www.opengl.org/archives/resources/code/samples/glut_examples/examples/fontdemo.c
// prints the string with a translation (x, y, z), scaling factor s and rotation of rotate degrees along y axis
// pointsize define the width of the line and point, to give a effect of bold
void stroke_output(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat pointsize, GLfloat rotate, string format);


static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3);

void materialCurve(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambfactor = 1.0, GLfloat specfactor = 1.0, GLfloat shine = 50);

void quadricShape1();
void quadricShape2();

void cubicalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX = 0, GLfloat ambY = 0, GLfloat ambZ = 0, GLfloat shine = 50);
void sphericalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);
void toroidShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings, GLfloat shine = 90);
void cylindricalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 90);
void trapezoidalShape(GLfloat difX, GLfloat difY, GLfloat difZ, GLfloat ambX, GLfloat ambY, GLfloat ambZ, GLfloat shine = 50);
void boxShape();

#endif 