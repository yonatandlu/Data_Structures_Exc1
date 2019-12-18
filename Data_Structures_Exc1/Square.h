#pragma once
// A Square is part of a Node class.
#ifndef __SQUARE_H__
#define __SQUARE_H__	
#include <stdlib.h>
#include <iostream>
using namespace std;

class Square {

	int row, column;   //Location in maze
	char data;		//'*' = wall , ' ' =  empty place, '$' = previously visited cell // TODO - consider getting rid of this as it's a duplication of the data in Maze.field.
public:
	Square() = default;
	Square(int row, int column, char data);

	//Square(Square&& other); // Move c'tor
	char getData() const;
	bool setData(char ch);
	int getRow() const;
	int getColumn() const;
	friend ostream& operator<<(ostream& os, const Square& s);
};

#endif // !__SQUARE_H__
