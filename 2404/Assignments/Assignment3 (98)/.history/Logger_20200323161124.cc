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

void Logger::update(Book* b){
    if(b->isCheckedIn){
        b->checkOut();
    }else{
        b->checkIn();
    }
}

void Logger::printLogs(){
    cout<< "Name: " << name << endl;
    books.print();
}

CheckInLogger::CheckInLogger() : name("Checked-in")
