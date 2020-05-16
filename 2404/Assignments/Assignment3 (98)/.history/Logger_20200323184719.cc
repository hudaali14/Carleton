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
    if(b->isCheckedIn()){
        b->checkOut();
    }else{
        b->checkIn();
    }
}

void Logger::printLogs(){
    cout<< "LOGS: " << name << endl;
    books.print();
}

CheckInLogger::CheckInLogger() : Logger("Checked-in"){
    cout<<"-- default Check In ctor:  "<< name <<endl;
}

CheckInLogger::~CheckInLogger(){
    cout<<"-- dtor Check In:  "<< name <<endl;
}

void CheckInLogger::update(Book* b){
    if(b->isCheckedIn()){
        books.add(b);
    }else{
        books.del(b->getId(), &b);
    }
}

CheckOutLogger::CheckOutLogger() : Logger("Checked-out"){
    cout<<"-- default Check Out ctor:  "<< name <<endl;
}

CheckOutLogger::~CheckOutLogger(){
    cout<<"-- dtor Check Out:  "<< name <<endl;
}

void CheckOutLogger::update(Book* b){
    if(b->isCheckedIn()){
        books.del(b->getId(), &b);
    }else{
        books.add(b);
    }
}