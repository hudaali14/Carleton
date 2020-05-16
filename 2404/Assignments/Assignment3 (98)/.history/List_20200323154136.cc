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

void List::add(Book* book)
{
    Node* tmpNode;
    Node* currNode;
    Node* prevNode;

    tmpNode = new Node;
    tmpNode->data = book;
    tmpNode->next = NULL;

    prevNode = NULL;
    currNode = head;

    while (currNode != NULL) {
        if (book->getAuthor() < currNode->data->getAuthor())
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

void List::del(const int id, Book** book)
{
    Node* currNode;
    Node* prevNode;

    currNode = head;
    prevNode = NULL;
    
    while (currNode != NULL) {
        if (currNode->data->getId() == id)
            break;

        prevNode = currNode;
        currNode = currNode->next;
    }

  // we get here if we didn't find the name or if we did find the name
    if (currNode == NULL) {
        *book = NULL;
        return;
    }

    if (prevNode == NULL)
        head = currNode->next;
    else
        prevNode->next = currNode->next;

    *book = currNode->data;
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

