#include "cellGrid.h"

cellGrid::cellGrid()
{
	alive = nullptr;
	tempAlive = nullptr;
	size = 0;
}

cellGrid::cellGrid(int sizeIn)
{
	size = sizeIn;
	alive = new bool*[size];
	tempAlive = new bool* [size];
	for (int i = 0; i < size; i++) {
		alive[i] = new bool[size];
		tempAlive[i] = new bool[size];
	}
}

bool cellGrid::setSize(const int sizeIn)
{
	bool valid = false;
	if (alive == nullptr) {
		size = sizeIn;
		alive = new bool* [size];
		tempAlive = new bool* [size];
		for (int i = 0; i < size; i++) {
			alive[i] = new bool[size];
			tempAlive[i] = new bool[size];
		}

		valid = true;

	}
	return valid;
}

const int cellGrid::getSize()
{
	return size;
}

void cellGrid::cycle()
{
	int overpopulation = 3; // could be derived from file to update rules at runtime
	int loneliness = 2;
	int birth = 3;

	

	if (alive != nullptr) {
		for (int i = 0; i < size; i++) {
			tempAlive[i][0] = alive[i][0];
			tempAlive[0][i] = alive[0][i];
		}

		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 1; j < size - 1; j++)
			{
				int aliveCount = 0;
				if (alive[i - 1][j - 1]) aliveCount++;
				if (alive[i    ][j - 1]) aliveCount++;
				if (alive[i + 1][j - 1]) aliveCount++;
				if (alive[i - 1][j    ]) aliveCount++;
				if (alive[i + 1][j    ]) aliveCount++;
				if (alive[i - 1][j + 1]) aliveCount++;
				if (alive[i    ][j + 1]) aliveCount++;
				if (alive[i + 1][j + 1]) aliveCount++;

				if (alive[i][j])
				{
					if (aliveCount > overpopulation)
					{
						tempAlive[i][j] = false;
					}
					else if (aliveCount < loneliness)
					{
						tempAlive[i][j] = false;
					}
					else
					{
						tempAlive[i][j] = true;
					}
				}
				else
				{
					if (aliveCount == birth)
					{
						tempAlive[i][j] = true;
					}
					else
					{
						tempAlive[i][j] = false;
					}
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				alive[i][j] = tempAlive[i][j];
			}
		}
	}
}

const bool cellGrid::getAlive(int tempX, int tempY)
{
	if (tempX < size && tempY < size)
	{
		return alive[tempX][tempY];
	}
	return false;
}

void cellGrid::seedGrid()
{
	srand(time(NULL));
	if (alive != nullptr) {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (rand() % 2 == 0)
				{
					alive[i][j] = true;
				}
				else
				{
					alive[i][j] = false;
				}
			}
		}
	}
}

