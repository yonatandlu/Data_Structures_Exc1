#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "utils.h"
#include "Maze.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

void getUserMaze(Maze* theMaze);
void genrateRandomMaze(Maze* theMaze);

int main()
{
	int option = -1;

	Maze* theMaze = nullptr;
	while (option != 0)
	{
		//cout << "option = " << option << endl;
		printMenu();
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "exit from menu 0" << endl;
			break;
		case 1:
			getUserMaze(theMaze);
			if (theMaze->solveMaze())
				theMaze->printMaze();
			else
				cout << "There is no path from starting point to finish point!!!\n";
			break;
		case 2:
			genrateRandomMaze(theMaze);
			if (theMaze->solveMaze())
				theMaze->printMaze();
			else
				cout << "There is no path from starting point to finish point!!!\n";
			break;
		default:
			cout << "invalid input" << endl;
			break;
		}
		cout << endl;
	}
	delete theMaze;
	return 1;
}


void getUserMaze(Maze* theMaze)
{
	char** field2d = nullptr;
	char buffer[BUFFER_SIZE];
	cout << "in getUserMaze()" << endl; //DEBUG
	clearBuffer();
	bool isValidInput = false;
	int rows = 0, columns = 0;
	
	isValidInput = getHightWidthParams(rows, columns);
	if(isValidInput)
	{
		field2d = new char*[rows];
		cout << "enter your maze:" << endl;
		for (int row = 0; row < rows; ++row)
		{
			cin.getline(buffer, BUFFER_SIZE); //PROBLEM WITH BUFFER - BUFFER IS EMPTY!!
			if (strlen(buffer) == columns)
			{
				field2d[row] = new char[columns];
				strncpy(field2d[row], buffer, columns);
			}
			else
			{
				cout << "ERROR. Entered row with " << strlen(buffer) << " expected size is " << columns << endl;
				return;
			}
		}
		if(validate2DField(rows,columns,field2d))
		{
			theMaze = new Maze(rows, columns, field2d);
			return;
		}
	}
	cout << "Invalid input" << endl;
	return;
}


void genrateRandomMaze(Maze* theMaze)
{
	cout << "build random maze." << endl;
	clearBuffer();
	bool isValidInput = false;
	int rows = 0, columns = 0;

	isValidInput = getHightWidthParams(rows, columns);
	if (isValidInput)
	{
		theMaze = new Maze(rows, columns);
		theMaze->createRandomMaze();
	}
	else
	{
		cout << "Error in input of random maze" << endl;
	}
	return;
}
