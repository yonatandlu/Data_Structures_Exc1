#pragma once
#pragma warning(disable:4996)
#ifndef __MAZE_H__
#define __MAZE_H__

#define MAX_NEIGHBOURS 4

#include <iostream>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"
#include <time.h>
using namespace std;

class Maze 
{
private:
	int numOfRows, numOfColumns;
	char** field;

	bool setDataInSquare(int row, int columns, char data);
	char** createFullMaze(int rows, int columns);
	
	int findCurrentNonVisitedNeighbours(int row, int column, Square* neighbours);
	void clearRandomCheckPath();
public:
	Maze(int numOfRows, int numOfColumns);
	Maze(int numOfRows, int numOfColumns, char** field);
	~Maze();
	char getData(int row, int colom) const;
	bool solveMaze();
	void printMaze();
	void createRandomMaze();
};

#endif // !__MAZE_H__
