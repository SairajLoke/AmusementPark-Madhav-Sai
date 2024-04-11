#!/bin/bash
g++ bmpLoader.cpp ./src/shapes/shapes.cpp ./src/background/background.cpp  ./src/human/human.cpp ./src/objects/objects.cpp ./src/rides/rides.cpp ./src/light/light.cpp main.cpp -lglut -lGLU -lGL && ./a.out

