#ifndef BOOK_H
#define BOOK_H

/*

BOOK CLASS
PURPOSE: 
the library. These classes also serve as the observers in our Observer design pattern
COMPLEX OR CRITICAL MEMBERS:
    - Function checkIn(): Changes checkedIn to true
    - Function checkOut(): Changes checkedIn to false
*/

class Book
{
    public:
        Book(string="", string="");
        Book(Book&);
        ~Book();
        void print() const;
        static int getNextId();
        int getId();
        string getAuthor();
        bool isCheckedIn();
        void checkIn();
        void checkOut();

    private:
        static int nextId;
        int id;
        string title;
        string author;
        bool checkedIn;
};

#endif
