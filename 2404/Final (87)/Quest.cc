#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;

#include "Quest.h"

int random(int);

Quest::Quest(){
    over = false;
    srand((unsigned)time(NULL));

    //Creates Timmy, Harold, and Dragon and adds to path
    timmy = new Hero('T', 3, 3);
    harold = new Hero('H', 5, 1);
    dragon = new Dragon();
    path.addCharacter(dragon);
    path.addCharacter(timmy);
    path.addCharacter(harold);
    print();
}

Quest::~Quest(){ }

bool Quest::isOver(){
    return over;
}

void Quest::update(){

    //Adds fighter 60% of the time
    int r = random(5) + 1;
    if(r <= 3){
        r = random(3) + 1;

        if(r == 1){
            Fighter* dorc = new Fighter('d', 6, 8);
            path.addCharacter(dorc);
        }else if(r == 2){
            Fighter* borc = new Fighter('b', 8, 11);
            path.addCharacter(borc);
        }else{
            Fighter* porc = new Fighter('p', 4, 5);
            path.addCharacter(porc);
        }
    }

    list<Character*> characters = path.getCharacters();
    list<Character*>::iterator itr;

    //For each character
    for ( itr = characters.begin(); itr != characters.end(); ++itr){

        //Update position
        Position pos = (*itr)->getPosition();
        path.moveCharacter((*itr)->getAvatar(), pos, (*itr)->updatePosition());

        pos = (*itr)->getPosition();

        //If character is dragon then sets dragon attack
        if((*itr)->getAvatar() == dragon->getAvatar()){
            dragon->setAttack();
        }

        //If character is at the same position as the dragon attack then fighter
        //is rewarded and hero is inflicted with damage
        Position dragonAttackpos = dragon->attackPosition();
        if(pos == dragonAttackpos){
            (*itr)->dragonAttack();
        }

        //Handles collsions
        //If current character is not Timmy, Harold, or Dragon
        if(!timmyOrHarold(*itr) && (*itr)->getAvatar() != dragon->getAvatar()){
            Hero* character= timmyorHarold(*itr);  //Character is either Timmy, Harold, or NULL
            //If fighter is at the same position as either Timmt or Harold
            if(character != NULL){
                //Inflict damage to both parties
                collsion(character, *itr);
                //If Timmy and Harold collide with the same fighter at the same
                //time then inflict damage then too
                if(timmy->getPosition().getX() == harold->getPosition().getX()){
                    harold->setHealth(harold->getHealth() - ((*itr)->getStrength() - harold->getArmour()));
                }
            }
        }

        //If fighter is dead the remove it's avatar from display
        if(!timmyOrHarold(*itr) && (*itr)->isDown()){
            path.removeCharacter((*itr));
            path.changeAvatar(' ', pos);
        }
    }

    //If Timmy and Harold are on the same position as the dragon then they
    //instantly die
    Position timpos = timmy->getPosition();
    Position harpos = harold->getPosition();
    Position dragonpos = dragon->getPosition();
    if(timpos == dragonpos){
        timmy->setHealth(0);
        timmy->setDown();
    }
    if(harpos == dragonpos){
        harold->setHealth(0);
        harold->setDown();
    }

    //If Timmy or Harold's health reaches zero then change avatar to '+'
    if(timmy->getHealth() <= 0 || harold->getHealth() <= 0){
        path.changeAvatar(timmy->getAvatar(), timmy->getPosition());
        path.changeAvatar(harold->getAvatar(), harold->getPosition());
    }

    print();

    if(timmy->isDown() && harold->isDown()){
        cout << "Both heros have died" << endl;
        over = true;
    }else if(timmy->getEmerald() && !timmy->isDown()){
        cout << "Timmy has obtained the Emerald" << endl;
        over = true;
    }else if(harold->getEmerald() && !harold->isDown()){
        cout << "Harold has obtained the Emerald" << endl;
        over = true;
    }

}

void Quest::collsion(Hero* hero, Character* fighter){
    int healthHero = hero->getHealth() - (fighter->getStrength() - hero->getArmour());
    int healthFighter = fighter->getHealth() - hero->getStrength();
    hero->setHealth(healthHero);
    fighter->setHealth(healthFighter);
}

bool Quest::timmyOrHarold(Character* character){
    if(character->getAvatar() == timmy->getAvatar() || character->getAvatar() == harold->getAvatar()){
        return true;
    }else{
        return false;
    }
}

Hero* Quest::timmyorHarold(Character* character){
    Position timpos = timmy->getPosition();
    Position harpos = harold->getPosition();
    Position chapos = character->getPosition();

    if(timpos == chapos){
        return timmy;
    }else if(harpos == chapos){
        return harold;
    }else{
        return NULL;
    }
}

//Prints display
void Quest::print(){
    cout << "Timmy: " << timmy->getPosition().getX() << "," <<  timmy->getPosition().getY() << "  |Health: " << timmy->getHealth() << endl;
    cout << "Harold: " << harold->getPosition().getX() << "," <<  harold->getPosition().getY() << " |Health: " << harold->getHealth() << endl;
    cout << "Dragon: " << dragon->getPosition().getX() << "," <<  dragon->getPosition().getY() << endl;
    path.print();
}
