#include "Queue.h"

Queue::Queue(int size)
{
	head = 1;
	tail = 0;
	this->size = size;
	data = new Type[size];
}

Queue::~Queue()
{
	delete[] data;
}

void Queue::MakeEmpty()
{
	head = 1;
	tail = 0;
}

//int Queue::addOne(int x)
//{
//	return ((1+x) % size);
//}

int Queue::IsEmpty() const		//return 1 if Queue is empty, 0 otherwise
{
	return (tailAddOne() == head);
}

void Queue::enQueue(const Type& item)		//insert item to end of the queue
{
	if (tailAddOne() == head)
	{
		cout << "ERROR: QUEUE FULL";
		exit(1);
	}
	tail = tailAddOne();
	data[tail] = item;
}

Type Queue::deQueue()		//remove head item and return it
{
	if (IsEmpty())
	{
		cout << "ERROR: QUEUE EMPTY\n";
		exit(1);
	}
	Type item = Type(data[head].getRow(), data[head].getColumn(), data[head].getData());
	head = headAddOne();
	return item;
}

Type Queue::front() const		//return front item
{
	if (IsEmpty())
	{
		cout << "ERROR: QUEUE EMPTY\n";
		exit(1);
	}
	return data[head];
}

int Queue::headAddOne() const
{
	return ((1 + head) % size);
}

int Queue::tailAddOne() const
{
	return ((1 + tail) % size);
}
