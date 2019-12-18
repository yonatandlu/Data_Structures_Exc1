#pragma once
// The Stack is implement using a linked list of nodes.

#ifndef __STACK_H__
#define __STACK_H__

#include "Node.h"
using namespace std;

class Stack {
private:
	Node* top;		//points to top of stack

public:
	Stack();
	~Stack();
	void MakeEmpty();  //Make empty stack
	bool IsEmpty() const;			  
	void Push(const Type& item);  //Push item onto stack
	Type Pop();		//Pop top item and return it
	Type Top() const;		//return top item

};

#endif // !__STACK_H__
