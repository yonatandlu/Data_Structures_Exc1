#include "Maze.h"


// creates a Maze object with a full 2DField.
// than creates a random maze.
Maze::Maze(int numOfRows, int numOfColumns)
{
	this->numOfRows = numOfRows;
	this->numOfColumns = numOfColumns;
	field = createFullMaze(numOfRows, numOfColumns);
}

// creates a Maze object with a given 2DFiled entered by the user.
Maze::Maze(int numOfRows, int numOfColumns, char** field)
{
	this->numOfRows = numOfRows;
	this->numOfColumns = numOfColumns;
	this->field = field;
}

Maze::~Maze()
{
	for (int i = 0; i < numOfRows; i++)
		delete[] field[i];
	delete[] field;
}

char Maze::getData(int row, int column) const
{
	return field[row][column];
}



bool Maze::setDataInSquare(int row, int column, char data)
{
	//cout << "cmp with blank = " << strncmp(&data, " ", 1) << "|cmp with * = " << strncmp(&data, "*", 1) << "|cmp with $ = " << strncmp(&data, "$", 1) << endl; //DEBUG
	if(strncmp(&data," ",1) != 0 && strncmp(&data, "*", 1) != 0 && strncmp(&data, "$", 1) != 0)
	{
		cout << "ERROR: WRONG DATA !!\n";
		return false;
	}
	strncpy(&this->field[row][column], &data, 1);
	return true;
}

char** Maze::createFullMaze(int rows, int columns)
{
	char** field2d_temp = new char* [rows];
	for (int row = 0; row < rows; ++row)
	{
		field2d_temp[row] = new char[columns];
		for (int column = 0; column < columns; ++column)
		{
			if (row % 2 == 0) // row is even, row is all ******
			{
					strncpy(&field2d_temp[row][column], "*", 1);
			}
			else // row is odd num
			{
				if (column % 2 == 0) // walls
				{
					strncpy(&field2d_temp[row][column], "*", 1);
				}
				else // spaces
				{
					strncpy(&field2d_temp[row][column], " ", 1);
				}
			}
		}
	}
	//create entrance and exit free spots.
	strncpy(&field2d_temp[1][0], " ", 1);
	strncpy(&field2d_temp[rows-2][columns-1], " ", 1);
	return field2d_temp;
}

// TODO - not finished
// requires a call to c'tor of Maze(int rows, int columns) to create a full 2d field first.
void Maze::createRandomMaze()
{
	bool validData = true;
	Stack s;
	s.MakeEmpty();

	Square currentSquare, tempNeighbour;
	Square neighbours[MAX_NEIGHBOURS];
	int neighbours_logical_size = 0;
	srand((unsigned)time(NULL));
	
	cout << "Init entrance and 1,1 as visited" << endl;//DEBUG
	this->setDataInSquare(1,0,'$'); // mark entrance as visited
	
	s.Push(Square(1, 1, '$')); //initialize with 1,1
	this->printMaze(); // DEBUG

	while (!s.IsEmpty() && validData)
	{
		currentSquare = s.Pop();
		cout << "after pop. before set data in poped item" << endl;//DEBUG

		validData = this->setDataInSquare(currentSquare.getRow(), currentSquare.getColumn(), '$'); // mark the current as visited
		
		neighbours_logical_size = findCurrentNonVisitedNeighbours(currentSquare.getRow(), currentSquare.getColumn(), neighbours);
		if (neighbours_logical_size > 0)
		{
			int neighbour_index = rand() % neighbours_logical_size;
			tempNeighbour = neighbours[neighbour_index];
			cout << "removing wall" << endl;// TODO - removeWall from current to chosen neighbour
			s.Push(currentSquare);
			s.Push(tempNeighbour);
		}
	}
	cout << "after stack ops and traversing the field" << endl;//DEBUG

	this->printMaze();

	this->clearRandomCheckPath(); // DEBUG
	cout << "after clearing the field" << endl;//DEBUG

}
/*
bool removeWall(int rowCurrent, int columnCurrent, int rowTemp, int columnTemp)
{
	int rowWall = rowTemp - rowCurrent;
	int columnWall = columnTemp - columnCurrent;
	if(rowWall == 2)
		return this->setDataInSquare(rowCurrent+1, columnCurrent, '$');
	return
	this->setDataInSquare(currentSquare.getRow(), currentSquare.getColumn(), '$');
}
*/

// creates an array of Square with the non visited available neighbours.
int Maze::findCurrentNonVisitedNeighbours(int row, int column, Square* neighbours)
{
	// check sequence Right, Down, Left, Up
	int neighbours_count = 0;
	// right neighbour
	if ((column + 2 < numOfColumns) && strncmp(&field[row][column +2], " ", 1)==0 )
	{
		neighbours[neighbours_count] = Square(row, column + 2,' ');
		++neighbours_count;
	}
	// down
	else if ((row + 2 < numOfRows) && strncmp(&field[row+2][column], " ", 1) == 0)
	{
		neighbours[neighbours_count] = Square(row+2, column, ' ');
		++neighbours_count;
	}
	// left
	else if ((column - 2 >= 0) && strncmp(&field[row][column - 2], " ",1) == 0)
	{
		neighbours[neighbours_count] = Square(row, column - 2, ' ');
		++neighbours_count;
	}
	//UP
	else if ((row-2 >= 0) && strncmp(&field[row-2][column], " ",1) == 0)
	{
		neighbours[neighbours_count] = Square(row - 2, column, ' ');
		++neighbours_count;

	}
	else
	{
		cout << "Square (" << row << "," << column << ") has no neighbours" << endl; //DEBUG
	}
	return neighbours_count;
}


// clears all of the "$", 1 signs from a maze after verifying the random path.
void Maze::clearRandomCheckPath()
{
	for (int row = 1; row < numOfRows-2; ++row)
	{
		for (int column = 0; column < numOfColumns; ++column)
		{
			if (strncmp(&field[row][column], "$", 1) == 0)
			{
				strncpy(&field[row][column], " ", 1);
			}
		}
	}
}


void Maze::printMaze()
{
	for (int row = 0; row < numOfRows; ++row)
	{
		for (int column = 0; column < numOfColumns; ++column)
			cout << field[row][column];
		cout << endl;
	}
	cout << endl; // DEBUG
}

bool Maze::solveMaze() //find path from start point to finish point. return true if found, false otherwise.
{
	Queue queue(numOfRows*numOfColumns);
	Square currentSqr;
	queue.enQueue(Square(1, 0, field[1][0])); // EnQueue starting point
	while (queue.IsEmpty() != NULL)
	{
		currentSqr = queue.deQueue();
		setDataInSquare(currentSqr.getRow(), currentSqr.getColumn(), '$');
		if (currentSqr.getRow() == numOfRows - 2, currentSqr.getColumn() == numOfColumns - 1) //Check if it's the finish point
			return true;
		if (field[currentSqr.getRow()][currentSqr.getColumn() + 1] == ' ') //Check right
			queue.enQueue(Square(currentSqr.getRow(), currentSqr.getColumn() + 1, ' '));
		if (field[currentSqr.getRow() + 1][currentSqr.getColumn()] == ' ')  //Check down
			queue.enQueue(Square(currentSqr.getRow() + 1, currentSqr.getColumn(), ' '));
		if (currentSqr.getRow() != 1, currentSqr.getColumn() != 0)  //Check if it's not starting point
		{
			if (field[currentSqr.getRow()][currentSqr.getColumn() - 1] == ' ') //Check left
				queue.enQueue(Square(currentSqr.getRow(), currentSqr.getColumn() - 1, ' '));
		}
		if (field[currentSqr.getRow() - 1][currentSqr.getColumn()] == ' ') //Check up
			queue.enQueue(Square(currentSqr.getRow() - 1, currentSqr.getColumn(), ' '));
	}
	return false;
}
