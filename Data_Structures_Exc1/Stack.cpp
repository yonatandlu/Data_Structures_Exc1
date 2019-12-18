#include "Stack.h"
using namespace std;

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	this->MakeEmpty();
}

void Stack::MakeEmpty()
{
	Node* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

bool Stack::IsEmpty() const
{
	if (top == NULL)
		return true;
	return false;
}

void Stack::Push(const Type& item)
{
	top = new Node(item, top);
}

Type Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "Error: STACK UNDERFLOW\n";
		exit(1);
	}
	Node* temp = top;
	Type data = Type(top->data.getRow(), top->data.getColumn(), top->data.getData());
	top = top->next;
	delete temp;
	return data;
}

Type Stack::Top() const
{
	return Type(top->data.getRow(), top->data.getColumn(), top->data.getData());
}
