#ifndef TREE_H
#define TREE_H
// #pragma once
#include "../../libs.h"

#include "../shapes/shapes.h"
#include "../../bmpLoader.h"
// int getRandomNumber();
void drawLeaves(float branchLength);
void drawBranch(float parentLength, float parentRadius, int depth, int branchingFactor, float altitude, float zAngle);
void drawTree(int seed, int depth);


#endif