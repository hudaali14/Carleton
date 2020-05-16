#ifndef LIST_H
#define LIST_H

#include "Animal.h"

/*

LIST CLASS
PURPOSE: Singly linked list that uses Animal pointers as data
COMPLEX OR CRITICAL MEMBERS:
  - Node class: Stores data and next pointers
  - Function del(const int, Animal**): Deletes first animal to match age int
  - Function add(Animal*):  Adds each animal in descending (decreasing) order by age

NODE CLASS
PURPOSE: Stores data and next pointers

*/

class List
{
  class Node
  {
    public:
      Animal* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(Animal*);
    void del(const int, Animal**);
    void print() const;

  private:
    Node* head;
};

#endif
