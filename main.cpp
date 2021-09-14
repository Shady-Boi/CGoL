#ifdef _WIN32
#include <gl/freeglut.h>        // For windows
#elif __APPLE__
#include <GLUT/glut.h>            // for Mac OS
#endif

#include <iostream>
#include "display.h"
#include "cellGrid.h"

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Conway's Game of Life");

	myInit();
	glutDisplayFunc(display);

	glutTimerFunc(100, animate, 0);

	glutMainLoop();

	return 0;
}