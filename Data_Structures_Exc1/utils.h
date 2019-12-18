#ifndef __UTILS_H
#define __UTILS_H

#define MAX_NUM_OF_ROWS 25
#define MAX_NUM_OF_COLOMNS 80
#define BUFFER_SIZE 100

#include <iostream>
#include <string.h>
using namespace std;

void printMenu()
{
	cout << "Maze:\n";
	//cout << "0. exit" << endl; // DEBUG
	cout << " 1) From Input\n";
	cout << " 2) Random maze" << endl;
}

bool getHightWidthParams(int& rows, int& columns)
{
	int rows_temp = 0, columns_temp = 0;
	cout << "Maze Hight: ";
	cin >> rows_temp;

	cout << "Maze Width: ";
	cin >> columns_temp;
	getchar();
	if (rows_temp % 2 != 1 || columns_temp % 2 != 1)
	{
		cout << "rows and width need to be odd numbers" << endl;
		return false;
	}
	else if (rows_temp > MAX_NUM_OF_ROWS || columns_temp > MAX_NUM_OF_COLOMNS || rows_temp < 3 || columns_temp < 3)
	{
		cout << "Hight must be in range of 3 to " << MAX_NUM_OF_ROWS << " and width in range of 3 to " << MAX_NUM_OF_COLOMNS << endl;
		return false;
	}
	else
	{
		rows = rows_temp;
		columns = columns_temp;
		return true;
	}
}



// TODO - need to finish
bool validate2DField(int rows, int columns, char** field)
{
	if (strncmp(&field[1][0], " ",1) != 0 || strncmp(&field[rows - 2][columns - 1], " ",1) != 0)
	{
		cout << "invalid entrance or exit" << endl;
		return false;
	}
	for (int row = 0; row < rows; ++row)
	{
		for (int column = 0; column < columns; ++column)
		{
			if (row == 0 || row == rows - 1) // upper and lower walls
			{
				if (strncmp(&field[row][column], "*",1) != 0) // check all chars in row are *
					return false;
			}
			else if (row == 1) // case for the entrance row with only the right wall
			{
				if (strncmp(&field[row][columns - 1], "*",1) != 0)
					return false;
			}
			else if (row == rows - 2) // case for the exit row, with only the left wall
			{
				if (strncmp(&field[row][0], "*",1) != 0)
					return false;
			}

			else // all others
			{
				if (strncmp(&field[row][0], "*",1) != 0 || strncmp(&field[row][columns - 1],"*",1) != 0)
					return false;
			}
		}
	}
	return true;
}

void clearBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}


#endif // !__UTILS_H

