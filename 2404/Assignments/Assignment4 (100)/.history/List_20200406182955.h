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
        T& del(int);
        void print() const;

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
        if(*k < *(currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (prevNode == NULL){
        head = tmpNode;
        tail = tmpNode;
    }else if(currNode == NULL){
        prevNode->next = tmpNode;
        tmpNode->prev = prevNode;
        tail = tmpNode;
    }else{
        prevNode->next = tmpNode;
        tmpNode->prev = prevNode;
        tmpNode->next = currNode;
        currNode->prev = tmpNode;
    }
    tmpNode->next  = currNode;

}

template <class T>
T& List<T>::del(int id){
    Node* currNode;
    currNode = head;
    
    while(currNode != NULL){
        if (currNode->data->getID() == id){
            break;
        }
        currNode = currNode -> next;
    }

    // Removing item if it doesn't exist
    if(currNode == NULL){
        *stu = NULL;
        return;
    }

    //Removing item if its head
    if(currNode == head){
        head = currNode->next;
        head-> prev = NULL;
    
    // Removing item if its at the end
    }else if(currNode == tail){
        tail = tail->prev;
        tail->next = NULL;

    // Removing item in middle    
    }else{
        currNode->prev->next = currNode -> next;
        currNode->next->prev = currNode -> prev;
    }  

    *stu = currNode->data;
    // delete currNode->data;
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
