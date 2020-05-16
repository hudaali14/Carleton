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

