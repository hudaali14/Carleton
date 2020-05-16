#include <iostream>
using namespace std;

#include "List.h"

List::List() : head(NULL) { }

List::~List()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

void List::add(Animal* animal)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = animal;
  tmpNode->next = NULL;

  prevNode = NULL;
  currNode = head;

  while (currNode != NULL) {
    if (animal->getName() < currNode->data->getName())
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }  

  if (prevNode == NULL)
    head = tmpNode;
  else
    prevNode->next = tmpNode;

  tmpNode->next  = currNode;

}

void List::del(const string name, Animal** animal)
{
  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = NULL;
  
  while (currNode != NULL) {
    if (currNode->data->getName() == name)
      break;

    prevNode = currNode;
    currNode = currNode->next;
  }

// we get here if we didn't find the name or if we did find the name
  if (currNode == NULL) {
    *animal = NULL;
    return;
  }

  if (prevNode == NULL)
    head = currNode->next;
  else
    prevNode->next = currNode->next;

  *animal = currNode->data;
  delete currNode;




}

void List::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

