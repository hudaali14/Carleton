#include <iostream>
using namespace std;

#include "Student.h"

#include <cstdlib>

template <class T>
class List
{
    template <class T>
    class Node 
    {
        public:
            T* data;
            Node* next;
    };

    public:
        List();
        ~List();
        void add(Student*);
        void del(const string, Student**);
        void print() const;

    private:
        Node* head;
};

template <class T>
List<T>::List() : head(NULL) { }

template <class T>
List<T>::~List()
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

template <class T>
void List<T>::add(Student* stu)
{
    Node* tmpNode;
    Node* currNode;
    Node* prevNode;

    tmpNode = new Node;
    tmpNode->data = stu;
    tmpNode->next = NULL;

    prevNode = NULL;
    currNode = head;

    while (currNode != NULL) {
        if (stu->getName() < currNode->data->getName())
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

template <class T>
void List<T>::del(const string name, Student** stu)
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
        *stu = NULL;
        return;
    }

    if (prevNode == NULL)
        head = currNode->next;
    else
        prevNode->next = currNode->next;

    *stu = currNode->data;
    delete currNode;
}

template <class T>
void List<T>::print() const
{
    Node* currNode = head;

    while (currNode != NULL) {
        //currNode->data->print();
        currNode = currNode->next;
    }
}
