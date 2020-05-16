#include <iostream>
using namespace std;

#include <cstdlib>

/*

LIST CLASS
PURPOSE: Singly linked list that uses Book pointers as data
COMPLEX OR CRITICAL MEMBERS:
    - Node class: Stores data and next pointers
    - Function operator+=(T*): Deletes object matching object identifier specifed
    in parameter
    - Function operator-=(const int): Adds non-duplicate objects to collection

NODE CLASS
PURPOSE: Stores data and next pointers

*/

template <class T>
class List{

    class Node{
        public:
            T* data;
            Node* next;
            Node* prev;
    };

    public:
        List();
        ~List();
        List<T>& operator+=(T*);
        List<T>& operator-=(const int);
        void print();

    private:
        Node* head;
};

template <class T>
List<T>::List() : head(NULL){ }

template <class T>
List<T>::~List(){
    Node* currNode;
    Node* nextNode;

    currNode = head;

    while (currNode != NULL) {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

// Adds non-duplicate objects to collection
template <class T>
List<T>& List<T>::operator+=(T* k){

    Node* tmpNode;
    Node* currNode;
    Node* prevNode;

    tmpNode = new Node;
    tmpNode->data = k;
    tmpNode->next = NULL;
    tmpNode->prev = NULL;

    prevNode = NULL;
    currNode = head;

    while(currNode != NULL){
        //If found duplicate deallocate and return
        if(*k == *(currNode->data)){
            delete tmpNode->data;
            delete tmpNode;
            return *this;
        }
        // Once insertion spot is found break
        if(*k < *(currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Adding to empty list
    if(head == NULL) {
        head = tmpNode;

    // Adding to end
    }else if(currNode == NULL){
        tmpNode->prev = prevNode;
        prevNode->next = tmpNode;
    }else{

        // Adding to beginning
        if(prevNode == NULL){
            head = tmpNode;
        }

        // Adding to middle
        tmpNode->next = currNode;
        currNode->prev = tmpNode;
    }

    return *this;
}

template <class T>
List<T>& List<T>::operator-=(const int id){
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

    // List is empty or item wasn't found
    if (currNode == NULL){
        throw "Student with that ID does not exist";
    }

    // Removing last element from list
    if(prevNode== NULL && currNode->next== NULL){
        head = NULL;

    // Removing head 
    }else if(prevNode == NULL){
        head = currNode->next;
        head->prev = NULL;
    }else{

        // Removing tail
        if(currNode->next == NULL){
            currNode = currNode->prev;
            currNode->next = NULL;

        // Removing from middle
        }else{
            prevNode->next = currNode->next;
            currNode->next->prev = prevNode;
        }
    }

    delete currNode->data;
    delete currNode;

    return *this;
}

template <class T>
void List<T>::print(){
    Node* currNode;
    currNode = head;

    cout << endl << "FRONT SIDE:" << endl;
    while(currNode != NULL){
        cout << *(currNode->data) << endl;
        currNode = currNode->next;
    }

    currNode = tail;

    cout << endl << "BACK SIDE:" << endl;
    while(currNode != NULL){
        cout << *(currNode->data) <<endl;
        currNode = currNode->prev;
    }
}
