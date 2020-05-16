#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#include "Logger.h"
#include "Book.h"

Logger::Logger(string n){
    name = n;
}

Logger::~Logger(){
}

void Logger::update(Book* b){
    if(b->isCheckedIn()){
        b->checkOut();
    }else{
        b->checkIn();
    }
}

void Logger::printLogs(){
    cout<< endl << endl << "LOGS: " << name << endl;
    books.print();
}

CheckInLogger::CheckInLogger() : Logger("Checked-in"){
}

CheckInLogger::~CheckInLogger(){
}

void CheckInLogger::update(Book* b){
    if(b->isCheckedIn()){
        books.add(b);
    }else{
        books.del(b->getId(), &b);
    }
}

CheckOutLogger::CheckOutLogger() : Logger("Checked-out"){
}

CheckOutLogger::~CheckOutLogger(){
}

void CheckOutLogger::update(Book* b){
    if(b->isCheckedIn()){
        books.del(b->getId(), &b);
    }else{
        books.add(b);
    }
}