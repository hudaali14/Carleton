#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"


Library::Library(){

    cout<<"-- default Library ctor:  "<<endl;
}

Library::~Library(){

    cout<<"-- dtor:  Library" <<endl;
    for(int i=0; i<loggers.size(); ++i){
        loggers[i]->printLogs();
        delete loggers[i];
    }
    master.cleanup();
}

void Library::subscribe(Logger* logger){
    loggers.push_back(logger);
}

void Library::notify(Book* b){
   for(int i=0; i<loggers.size(); ++i){
       loggers[i]->update(b);
   } 
}

void Library::add(Book* b){
    master.add(b);
    notify(b);
}

Book* Library::find(int id){
    return master.find(id);
}

void Library::checkOut(Book* b){
    b->checkOut();
    notify(b);
}

void Library::checkIn(Book* b){
    b->checkIn();
    notify(b);
}

void Library::print(){
    cout << endl << endl << "LIBRARY:" << endl;
    master.print();
}