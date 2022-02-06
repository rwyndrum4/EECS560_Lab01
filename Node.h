#ifndef NODE_H
#define NODE_H
#include<string>

class Node
{
private:
	int m_entry;
	Node* m_next;

public:
	//pre: takes in an entry
	//post: creates node with value entry and moves the pointer
	//return:n/a
	Node(int entry);
	//pre:Node exists;
	//post: nothing changes
	//return: entry
	int getEntry() const;
	//pre:entry exists
	//posts Sets the entry
	//return:n/a
	void setEntry(int entry);
	//pre:next exists
	//post:get next
	//return:next
	Node* getNext() const;
	//pre:next exists
	//posts next set
	//return:n/a
	void setNext(Node* next);

};
#include "Node.cpp"
#endif
