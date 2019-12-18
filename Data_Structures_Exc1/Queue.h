//#pragma once
// The Queue is implement using a static array of Squares.

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Square.h"
#include "Maze.h"
using namespace std;

typedef Square Type;

class Queue {
private:
	int head,tail, size;
	Type* data;

	int headAddOne() const;
	int tailAddOne() const;
	//static int addOne(int x);
public:
	Queue(int size);
	~Queue();
	void MakeEmpty();  //Make empty queue
	int IsEmpty() const;
	void enQueue(const Type& item);  //insert item to end of the queue
	Type deQueue();		//remove head item and return it
	Type front() const;		//return front item
};

#endif // !__QUEUE_H__
