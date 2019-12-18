#include "Node.h"
using namespace std;

Node::Node()	//C'tor
{
	next = NULL;
}

Node::Node(Type item, Node* ptr) : data(item.getRow(), item.getColumn(), item.getData())  //C'tor
{
	next = ptr;
}

void Node::InsertAfter(Node* newNode)	//Insert newNode after current node
{
	newNode->next = this->next;
	this->next = newNode;
}

Node* Node::DeleteAfter()	//Delete node after current node
{
	Node* temp = this->next;
	if (this->next == NULL)
		return NULL;
	this->next = temp->next;
	return temp;
}
