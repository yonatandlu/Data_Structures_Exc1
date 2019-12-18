#pragma once
// A Node is part of a Stack class.

#ifndef __NODE_H__
#define __NODE_H__

#include <stdlib.h>
#include "Square.h"
using namespace std;

typedef Square Type;

class Node {
private:
	Type data;   //data field
	Node* next;	 //points to next node

public:
	Node();
	Node(Type item, Node* ptr = NULL);
	void InsertAfter(Node* newNode);  //Insert newNode after current node
	Node* DeleteAfter();			  //Delete node after current node

	friend class Stack;

};

#endif // !__NODE_H__
