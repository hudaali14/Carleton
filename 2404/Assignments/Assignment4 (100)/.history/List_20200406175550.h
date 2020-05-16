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
    friend ostream& operator<<(ostream&, const List<V>&);

    public:
        List();
        ~List();
        void add(T*);
        void del(int);
        void print() const;

    private:
        Node* head;
        Node* tail
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
void List<T>::add(T* k){
    Node* currNode;
    currNode = head;

    Node* tmpNode = new Node;
    tmpNode->data = k;
    tmpNode->next = NULL;

    while(currNode != NULL){
        if(*k < *(currNode->data)){
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
void List<T>::del(int id){
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
void List<T>::print() const
{
    Node* currNode = head;

    while (currNode != NULL) {
        //currNode->data->print();
        currNode = currNode->next;
    }
}
