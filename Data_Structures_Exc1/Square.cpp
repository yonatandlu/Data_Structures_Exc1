#include "Square.h"


Square::Square(int row, int column, char data)	//C'tor with params
{
	this->row = row;
	this->column = column;
	this->data = data;
}

char Square::getData() const //return data
{
	return data;
}

bool Square::setData(char ch) //set data
{
	if (ch != ' ' && ch != '*' && ch != '$')
	{
		cout << "ERROR: WRONG DATA !!\n";
		return false;
	}
	this->data = ch;
	return true;
}

int Square::getRow() const
{
	return row;
}
int Square::getColumn() const
{
	return column;
}

ostream& operator<<(ostream& os, const Square& s)
{
	os << "(" << s.row << "," << s.column << ", data = " << s.data << ")";
	return os;
}

