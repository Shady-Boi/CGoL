#include "display.h"
#include <iostream>

cellGrid CG;

void myInit()
{
	int tempSize = 0;
	
	std::cout << "How large a grid do you want (min 10): ";
	std::cin >> tempSize;
	if (tempSize < 10) {
		std::cout << "Size entered too small, grid set to 10" << std::endl;
		tempSize = 10;
	}
	std::cout << "Life begins" << std::endl;

	CG.setSize(tempSize);
	CG.seedGrid();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(0.1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-CG.getSize() / 2, CG.getSize() / 2, -CG.getSize() / 2, CG.getSize() / 2, 0.1, 5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float tempSize = CG.getSize();

	gluLookAt(tempSize / 2.0,
		tempSize / 2.0,
		-1.0,
		tempSize / 2.0,
		tempSize / 2.0,
		5.0,
		0.0,
		1.0,
		0.0);


	for (int i = 0; i < tempSize; i++)
	{
		for (int j = 0; j < tempSize; j++)
		{
			if (!CG.getAlive(i, j))
			{
				glColor3f(0.0, 0.0, 0.0);
			}
			else 
			{
				glColor3f(1.0, 1.0, 1.0);
			}
			glPushMatrix();
				glBegin(GL_QUADS);
					glVertex3f(i, j, 2);
					glVertex3f(i+1, j, 2);
					glVertex3f(i+1, j+1, 2);
					glVertex3f(i, j+1, 2);
				glEnd();
			glPopMatrix();

		}


	}
	glutSwapBuffers();
}

void animate(int a)
{
	glutTimerFunc(100, animate, 0);
	CG.cycle();
	glutPostRedisplay();
}
