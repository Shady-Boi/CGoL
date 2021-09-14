#pragma once

#ifdef _WIN32
#include <gl/freeglut.h>        // For windows
#elif __APPLE__
#include <GLUT/glut.h>            // for Mac OS
#endif

#include "cellGrid.h"



void myInit();

void display(void);

void animate(int a);

