#ifndef BOOK_H
#define BOOK_H

/*

BOOK CLASS
PURPOSE: Book class with a id, nextId, title, author, and checkedIn value
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
