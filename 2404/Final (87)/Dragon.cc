#include <iostream>
using namespace std;

#include "Dragon.h"

int random(int);

Dragon::Dragon(){
    avatar = 'D';
    setPosition(3, 24); //Sets intital dragon position
    setAttack();        //Sets intital attack position
}

Dragon::~Dragon(){ }

// Sets random y value, and uses dragon current X value to decide new attack position
void Dragon::setAttack(){
    int r = random(23) + 1;
    int x = currentPosition.getX();
    attack.setPosition(x, r);
}

Position Dragon::attackPosition(){
    return attack;
}

void Dragon::setPosition(int newx, int newy){
    currentPosition.setPosition(newx, newy);
}

//Updates dragon position so he paces up and down the cave
Position Dragon::updatePosition(){

    int x, oldx;

    oldx = currentPosition.getX();
    if(oldx == 2){
        x = 3;
        direction = 0;
    }else if(oldx == 4){
        x = 3;
        direction = 1;
    }else{
        if(direction == 0){
            x = 4;
        }else if(direction == 1){
            x = 2;
        }
    }

    setPosition(x, currentPosition.getY());

    return currentPosition;
}
