#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

Logger::Logger(string n){
    name = n;
    cout<<"-- default Logger ctor:  "<< name <<endl;
}

Logger::~Logger(){
    cout<<"-- dtor Logger:  "<< name <<endl;
}
