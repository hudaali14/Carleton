#include <iostream>
using namespace std;

#include <cstdlib>

/*

LIST CLASS
PURPOSE: Singly linked list that uses Book pointers as data
COMPLEX OR CRITICAL MEMBERS:
    - Node class: Stores data and next pointers
    - Function del(const int, Book**): Deletes book to match specified id
    - Function add(Book*):  Adds book in ascending order by author name
    - Function find(int id): Returns book with matching id in list. If not found returns NULL

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
        Node* tail;
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
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

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
        if(*k == *(currNode->data)){
            delete tmpNode->data;
            delete tmpNode;
            return *this;
        }
        if(*k < *(currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(head == NULL && tail == NULL) {
        head = tmpNode;
        tail = tmpNode;
    }else if(prevNode == NULL){
        tmpNode->next = currNode;
        currNode->prev = tmpNode;
        head = tmpNode;
    }else{
        tmpNode->prev = prevNode;
        prevNode->next = tmpNode;

        if(currNode == NULL){
            tail = tmpNode;
        }else{
            tmpNode->next = currNode;
            currNode->prev = tmpNode;
        }
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

    // we get here if we didn't find the name or if we did find the name
    if (currNode == NULL){
        throw "Student with that ID does not exist";
    }

    if (head == tail){
        head = NULL;
        tail = NULL;
    }else if(prevNode == NULL){
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
