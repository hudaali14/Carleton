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
    cout<< "Name: " << name << endl;
    books.print();
}

CheckInLogger::CheckInLogger() : name("Checked-in"){
    cout<<"-- default Check In ctor:  "<< name <<endl;
}

CheckInLogger::~CheckInLogger(){
    cout<<"-- dtor Check In:  "<< name <<endl;
}

void CheckInLogger::update(Book* b){
    if(b->isCheckedIn()){
        books->add(b);
    }else{
        Book** bb = b;
        books->del(b->getId(), bb);
    }
}

CheckOutLogger::CheckOutLogger() : name("Checked-out"){
    cout<<"-- default Check Out ctor:  "<< name <<endl;
}

CheckOutLogger::~CheckOutLogger(){
    cout<<"-- dtor Check Out:  "<< name <<endl;
}

void CheckOutLogger::update(Book* b){
    if(b->isCheckedIn()){
        Book** bb = b;
        books->del(b->getId(), bb);
    }else{
        books->add(b);
    }
}