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

void List::add(Book* b)
{
    Node* tmpNode;
    Node* currNode;
    Node* prevNode;

    tmpNode = new Node;
    tmpNode->data = b;
    tmpNode->next = NULL;

    prevNode = NULL;
    currNode = head;

    while (currNode != NULL) {
        if(b = currNode->data){
            delete tmpNode;
            return;
        }
        if (b->getAuthor() < currNode->data->getAuthor())
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

void List::del(const int id, Book** b)
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
        *b = NULL;
        return;
    }

    if (prevNode == NULL)
        head = currNode->next;
    else
        prevNode->next = currNode->next;

    *b = currNode->data;
    delete currNode;

}

Book* List::find(int id){
    Node* currNode;
    currNode = head;

    while(currNode != NULL){
        if(id == currNode->data->getId()){
            break;
        }
        currNode = currNode->next;
    }
    if(currNode == NULL){
        return NULL;
    }

    return currNode->data;
}

void List::cleanup(){
    Node* currNode;
    Node* nextNode;

    currNode = head;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }
}

void List::print() const
{
    Node* currNode = head;

    while (currNode != NULL) {
        currNode->data->print();
        currNode = currNode->next;
    }
}