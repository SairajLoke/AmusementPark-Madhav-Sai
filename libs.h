#pragma once

#ifndef LIBS_H
#define LIBS_H

#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#ifdef __APPLE_CC__
#include <GL/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <GL/glext.h>
#include <math.h>
#include <string.h>
#include<unistd.h>    
using namespace std;

#endif