#include <iostream>
#include <cstdlib>
using namespace std;

#include "Fighter.h"


int random(int);

Fighter::Fighter(char ava, int str1, int str2){
    health = 5;
    avatar = ava;

    // Calcuates random strength between values str1 and str2
    int randstr = rand() % (str2 - str1 + 1) + str1;
    strength = randstr;
    //Assigns random vertical position
    int r = random(5) + 1;
    setPosition(r, 23);
}

Fighter::~Fighter(){ }

//If fighter has landed on the dragon attack position, health is increased by 5
void Fighter::dragonAttack(){
    health += 5;
    if(health > 5){
        health = 5;
    }
}

//Sets position to fit within DragonHallow boundaries
void Fighter::setPosition(int newx , int newy){

    int x = newx;
    int y = newy;

    if(newx <= 0){
        x = 1;
    }else if(newx > 5){
        x = 5;
    }

    if(newy <= 0){
        y = 1;
        //If fighter gets to left most edge remove
        down = true;
    }
    currentPosition.setPosition(x, y);
}

//Updates fighters positions to move one horizontal position to the left, with a vertical position
//randomly generated between the same vertical position, one position up, or one position down
Position Fighter::updatePosition(){

    int r, x, y;

    if(down){
        return currentPosition;
    }

    r = random(3) + 1;
    x = currentPosition.getX();
    y = currentPosition.getY() - 1;

    if(r == 1){
        x += 1;
    }else if(r == 2){
        x += -1;
    }else{
        x = x;
    }

    if(!down){
        setPosition(x, y);
    }

    return currentPosition;
}
