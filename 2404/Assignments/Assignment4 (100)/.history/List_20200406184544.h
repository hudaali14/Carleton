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
            Node* prev;
    };

    template <class V>
    friend ostream& operator<<(ostream&, List<V>&);

    public:
        List();
        ~List();
        T& add(T*);
        T& del(const int);

    private:
        Node* head;
        Node* tail
};

template <class T>
List<T>::List() : head(NULL), tail(NULL){ }

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
T& List<T>::add(T* k){
    Node* tmpNode;
    Node* currNode;
    Node* prevNode;

    tmpNode = new Node;
    tmpNode->data = stu;
    tmpNode->next = NULL;
    tmpNode->prev = NULL;

    prevNode = NULL;
    currNode = head;

    while(currNode != NULL){
        if(*k == *(currNode->data)){
            return;
        }
        if(*k < *(currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == NULL){
        head = tmpNode;
        tail = tmpNode;
    }else{
        prevNode->next = tmpNode;
        tmpNode->prev = prevNode;

        if(currNode == NULL){
            tail = tmpNode;
        }else{
            tmpNode->next = currNode;
            currNode->prev = tmpNode;
        }
    }
}

template <class T>
T& List<T>::del(const int id){
    Node* currNode;
    Node* prevNode;

    currNode = head;
    prevNode = NULL;
  
    while (currNode != NULL) {
        if (currNode->data->getID() == id)
            break;

        prevNode = currNode;
        currNode = currNode->next;
    }

    // we get here if we didn't find the name or if we did find the name
    if (currNode == NULL) {
        //*stu = NULL;
        return;
    }

    if (prevNode == NULL){
        head = currNode->next;
        head->prev = NULL;
    }else{
        if(currNode == tail){
            tail = tail->prev;
            tail->next = NULL;
        }else{
            prevNode->next = currNode->next;
            currNode->next->prev = prevNode;
        }
    }

    *stu = currNode->data;
    delete currNode;

}

template <class T>
ostream& operator<<(ostream& out, T& t)
{
    Node* currNode = head;

    out << endl << "FRONT SIDE:" << endl;
    while (currNode != NULL) {
        out << currNode->data <<endl;
        currNode = currNode->next;
    }

    currNode = tail;

    out << endl << "BACK SIDE:" << endl;
    while (currNode != NULL) {
        out << currNode->data <<endl;
        currNode = currNode->prev;
    }

    return out;
}
