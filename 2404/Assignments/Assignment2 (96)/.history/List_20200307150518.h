#ifndef LIST_H
#define LIST_H

#include "Animal.h"

class List
{
  class Node 
  {
/*
    friend class List;
    private:
*/
    public:
      Animal* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    void add(Animal*);
    void del(const string, Animal**);
    void print() const;

  private:
    Node* head;
    Node* tail;
};

#endif
