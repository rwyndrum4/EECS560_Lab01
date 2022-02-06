#include "stdexcept"
#include "Node.h"
#include "iostream"
#include "fstream"

LinkedList::LinkedList()
{
  m_length = 0;
  m_front = nullptr;
}

/*
LinkedList::LinkedList(const LinkedList& orig)
{

  int count = orig.length();
  for(int i = 1; i <= count ; i++)
  {
    insert( i , orig.getEntry(i) );
  }

}
*/

LinkedList::~LinkedList()
{
  while(m_length != 0)
  {
    Node* current = m_front;
    Node* next = nullptr;
    while(current != nullptr)
    {
      next = current->getNext();
      delete current;
      current = next;
    }
    m_length = 0;
  }
}

void LinkedList::insert(int index, int entry)
{
  if (m_length + 1 >= index && index > 1)
  {
    Node* beforePtr = m_front;
    Node* afterPtr = nullptr;

    for(int i = 0 ; i < index - 1 ; i++)
    {
      beforePtr = beforePtr->getNext();
    }
    afterPtr = beforePtr->getNext();

    Node* newNode = new Node(entry);

    beforePtr->setNext(newNode);
    newNode->setNext(afterPtr);
  }
  else if (index == 1)
  {
    Node* newNode = new Node(entry);
    newNode->setNext(m_front);
    m_front = newNode;
  }
  else
  {
    throw(std::runtime_error("Invalid Index!\n"));
  }
  m_length++;
}

void LinkedList::remove(int index)
{
  if(index > m_length || index  < 1)
  {
    throw(std::runtime_error("Invalid Index!\n"));
  }
  else if (index == 1)
  {
    Node* next_element = m_front->getNext();
    delete m_front;
    m_front = next_element;
  }
  else
  {
    Node* pre_removal = m_front;
    for(int i = 1 ; i < index - 1; i++)
    {
      pre_removal = pre_removal->getNext();
    }
    Node* node_to_remove = pre_removal->getNext();
    Node* post_removal = node_to_remove->getNext();
    delete node_to_remove;
    pre_removal->setNext(post_removal);
  }
  m_length--;
}

int LinkedList::getEntry(int index) const
{
  if(m_front == nullptr)
  {
    throw(std::runtime_error("List is empty"));
  }
  else if(index >= 1 && index <= m_length)
  {
    Node* current = m_front;
    for(int i = 1 ; i < index ; i++)
    {
      current = current->getNext();
    }
    return(current->getEntry());
  }
  else
  {
    throw(std::runtime_error("Invalid Index!\n"));
  }

}

int LinkedList::length() const
{
 return(m_length);
}

void LinkedList::setEntry(int index, int entry)
{
  if (m_length + 1 >= index && index > 1)
  {
    Node* currentPtr = m_front;

    for(int i = 0 ; i < index ; i++)
    {
      currentPtr = currentPtr->getNext();
    }
    currentPtr->setEntry(entry);
  }
  else if (index == 1)
  {
    Node* newNode = new Node(entry);
    m_front = newNode;
  }
  else
  {
    throw(std::runtime_error("Invalid Index!\n"));
  }
}

void LinkedList::clear()
{

  while(m_length != 0)
  {
    Node* current = m_front;
    Node* next = nullptr;

    while(current != nullptr)
    {
      next = current->getNext();
      delete current;
      current = next;
    }
  }

}

bool LinkedList::isEmpty(){
  if(m_length == 0){
    std::cout << "List is empty.\n";
    return(true);
  }
  else{
    std::cout << "List is not empty.\n";
    return(false);
  }
}

void LinkedList::print(){
    Node* current = m_front;
    Node* next = nullptr;
    while(current != nullptr)
    {
      next = current->getNext();
      std::cout << current->getEntry() << "\n";
      current = next;
    }
}

void LinkedList::findindexfordelete(int target){
  int index = 1;
  Node* current = m_front;
  Node* next = nullptr;
  while(current->getEntry() != target)
  {
    next = current->getNext();
  //  std::cout << current->getEntry() << "\n";
    current = next;
    index++;
  }
  if(current->getEntry() == target){
      this->remove(index);
  }
}

bool LinkedList::findindex(int target){
  bool flag = false;
  Node* current = m_front;
  Node* next = nullptr;
  while(current->getEntry() != target && current->getNext() != nullptr)
  {
    next = current->getNext();
    current = next;
  }
  if(current->getEntry() == target){
    flag = true;
  }
    return(flag);
  }

void LinkedList::reverse(){
  Node* next = nullptr;
  Node* curr = m_front;
  Node* prev = nullptr;

  while(curr != nullptr){
    next = curr->getNext();
    curr->setNext(prev);
    prev = curr;
    curr = next;
  }
  m_front = prev;

  this->print();
}

void LinkedList::append(std::string filename){
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {
    std::cout << "infile has been opened\n\n";
    int newNum = 0;
    for(int i = 0; i < 5; i++){
      inFile >> newNum;
      this->insert(1, newNum);
    }
  }
  inFile.close();
}
