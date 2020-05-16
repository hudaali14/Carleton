#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"

Libray::Library(){

    cout<<"-- default Library ctor:  "<<endl;
}

Library::~Library(){

    cout<<"-- dtor:  Library" <<endl;
    for(int i=0; i<loggers.size(); ++i){
        loggers[i]->printLogs();
        delete loggers[i];
    }
    master->cleanup();
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
    master->add(b);
    notify(b);
}

Book* Library::find(int id){
    return master->find(id);
}

