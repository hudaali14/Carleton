#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

int Book::nextId = 1001;

Book::Book(string t, string a)
{
  id     = nextId;
  ++nextId;
  title  = t;
  author = a;
  cout<<"-- default ctor:  "<< id <<endl;
}

Book::Book(Book& orig)
{
  cout<<"-- copy ctor:  "<< orig.id <<endl;

  id     = orig.id;
  title  = orig.title;
  author = orig.author;
}

Book::~Book()
{
  cout<<"-- dtor:  "<< id <<endl;
}

int Book::getNextId() { return nextId; }

void Book::print() const
{
  cout<<"** "<< title <<" by "<<author<<endl;
}

