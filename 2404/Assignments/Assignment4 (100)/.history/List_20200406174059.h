#include <iostream>
using namespace std;

#include "Student.h"

#include <cstdlib>

template <class T>
class List
{
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
List<T>::~List(){
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
void List<T>::add(Student* stu){
    Node* currNode;
    currNode = head;

    Node* tmpNode = new Node;
    tmpNode->data = stu;
    tmpNode->next = NULL;

    while(currNode != NULL){
        if(stu->getName() < currNode->data->getName()){
            break;
        }
        currNode = currNode->next;
    }

    if(head == NULL && tail == NULL){
        cout << "List is empty" << endl;
        head = tmpNode;
        tail = tmpNode;
        tmpNode -> prev = NULL;
        return;
    }

    if(currNode == head){
        cout << "Adding to head" << endl;
        tmpNode->prev = NULL;
        tmpNode->next = currNode;
        currNode -> prev = tmpNode;
        head = tmpNode; 
    }else if(currNode == NULL){
        cout << "Adding to tail" << endl;
        tail->next = tmpNode;
        tmpNode->prev = tail;
        tail = tmpNode;
    }else{
        cout << "Adding to middle" << endl;
        tmpNode->prev = currNode->prev;
        currNode->prev->next = tmpNode;
        currNode->prev = tmpNode;
        tmpNode->next = currNode;
    }

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
