#ifndef DATE_H
#define DATE_H

class Date
{
    friend ostream& operator<<(ostream&, Date&);

    public:
        Date(int=0, int=0, int=2000);
        ~Date();
        void setDate(int, int, int);
        void printShort();
        void printLong() const;
        void printLong();
        bool operator<(Student&);
        bool operator==(Student&);

    private:
        int day;
        int month;
        int year;
        int  lastDayInMonth();
        bool leapYear();
        string getMonthStr() const;
};

#endif
