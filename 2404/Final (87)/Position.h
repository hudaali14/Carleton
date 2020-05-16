#ifndef POSITION_H
#define POSITION_H

/*

POSITION CLASS
PURPOSE: Position class with x and y points
COMPLEX OR CRITICAL MEMBERS:
    - Function operator==(Position&): Returns true if positions are equal with
    x and y points

*/

class Position{

    public:
        Position(int=0, int=0);
        ~Position();
        int getX();
        int getY();
        bool operator==(Position&);
        void setPosition(int, int);

    private:
        int x;
        int y;
};

#endif
