#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Library.h"

Library::~Library(){
    for(int i=0; i<loggers.size(); ++i){
        loggers[i]->printLogs();
        delete loggers[i];
    }
    master->cleanup();
}

