#include <iostream>
#include <iomanip>
using namespace std;

#include "Position.h"

Position::Position(int posx, int posy){
    x = posx;
    y = posy;
}

Position::~Position(){ }

int Position::getX(){
    return x;
}

int Position::getY(){
    return y;
}

bool Position::operator==(Position& p)
{
  return ( x == p.x
        && y == p.y );
}

void Position::setPosition(int newx, int newy){
    x = newx;
    y = newy;
}