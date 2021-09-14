#pragma once
#include <time.h>
#include <cstdlib>



static class cellGrid
{
	bool** alive;
	bool** tempAlive;
	int size;

public:

	cellGrid();
	cellGrid(int sizeIn);

	bool setSize(const int sizeIn);
	const int getSize();
	void cycle();
	const bool getAlive(int tempX, int tempY);
	void seedGrid();
};

