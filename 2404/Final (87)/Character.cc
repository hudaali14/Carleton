#include <iostream>
#include <iomanip>
using namespace std;

#include "Character.h"
#include "DragonHallow.h"

int random(int);

Character::Character(){
    currentPosition.setPosition(1, 1);
    down = false;
}

Character::~Character(){ }

char Character::getAvatar(){ return avatar; }
Position Character::getPosition(){ return currentPosition; }
int Character::getHealth(){ return health; }
int Character::getStrength(){ return strength; }
bool Character::isDown() { return down; }

void Character::setHealth(int level){
    health = (level<0) ? 0 : level;
    if(health == 0){
        down = true;
    }
}

void Character::dragonAttack() { }
