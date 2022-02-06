#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>


class LinkedList
{
private:
  Node* m_front;
  int m_length;

public:

  LinkedList();

  LinkedList(const LinkedList& orig);

  ~LinkedList();

  /**
  * @pre The index is valid
  * @post The entry is added to the list at the index, increasing length by 1
  * @param index, position to insert at (1 to length+1)
  * @param entry, value/object to add to the list
  * @throw std::runtime_error if the index is invalid
  */
    void insert(int index, int entry);

    /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    void remove(int index);

    /**
    * @pre The index is valid
    * @post None
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    int getEntry(int index) const;

    /**
    * @pre None
    * @post None
    * @throw None
    */
    int length() const;

    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    void clear();

    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */
    void setEntry(int index, int entry);

    bool isEmpty();

    void print();

    //differently than the findindex, it hands off the index to the remove
    void findindexfordelete(int target);

    bool findindex(int target);

    void reverse();

    void append(std::string filename);

};
#include "LinkedList.cpp"
#endif
