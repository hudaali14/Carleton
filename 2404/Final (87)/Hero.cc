#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

#include "Hero.h"

int random(int);

Hero::Hero(char ava, int str, int arm){
    health = 15;
    avatar = ava;
    strength = str;
    armour = arm;

    srand((unsigned)time(NULL));
    int r;
    r = random(5) + 1;
    setPosition(r, 1);
}

Hero::~Hero(){ }

int Hero::getArmour(){ return armour; }
bool Hero::getEmerald(){ return emerald; }

void Hero::setHealth(int level){
    health = (level<0) ? 0 : level;
    if(health == 0){
        setDown();
    }
}

// If hero has died then sets avatar to be addition symbol
void Hero::setDown() {
    down = true;
    avatar = '+';
}

//If hero has landed on the dragon attack position, health is decreased by 10
void Hero::dragonAttack(){
    health -= 10;
    if(health < 0){
        health = 0;
        setDown();
    }
}

//Sets position to fit within DragonHallow boundaries
void Hero::setPosition(int newx, int newy){
    int x = newx;
    int y = newy;
    if(newx <= 0){
        x = 1;
    }else if(newx > 5){
        x = 5;
    }

    if(newy <= 0){
        y = 1;
    }else if(newy >= 24){
        if(x == 1){
            x = newx + 1;
        }else if(x == 5){
            x = newx - 1;
        }else{
            //If hero has reached one of the 3 dragon entrance caves then they
            //found the emerald
            emerald = true;
        }
        y = 24;
    }

    currentPosition.setPosition(x, y);
}

//Updates hero position to ove one horizontal position to the right, with a vertical
//position randomlygenerated between the same vertical position, one position up, or one position down
Position Hero::updatePosition(){

    int r, x, y;

    if(down){
        return currentPosition;
    }

    r = random(3) + 1;
    x = currentPosition.getX();
    y = currentPosition.getY() + 1;

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
