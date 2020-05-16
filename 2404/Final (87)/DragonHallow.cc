#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "DragonHallow.h"

DragonHallow::DragonHallow() : field(7, 27){

    const char fieldOfPlay[7][27] = {
    {'|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|', ' '},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', ' '},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', '*'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '=', ' '},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' '},
    {'|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|', ' '}};

    for (int i=0; i<7; ++i){
        for (int j=0; j<27; ++j){
            field.getElements()[i][j] = fieldOfPlay[i][j];
        }
    } }

DragonHallow::~DragonHallow(){
    list<Character*>::iterator itr;
    for(itr = characters.begin(); itr != characters.end(); ++itr){
        delete (*itr);
    }
}

list<Character*> DragonHallow::getCharacters() { return characters; }

void DragonHallow::addAvatar(Character* character){
    field.getElements()[character->getPosition().getX()][character->getPosition().getY()] = character->getAvatar();
}

void DragonHallow::addCharacter(Character* character){
    characters.push_back(character);
    addAvatar(character);
}

void DragonHallow::removeCharacter(Character* character){
    characters.remove(character);
    delete character;
}

void DragonHallow::moveCharacter(char avatar, Position oldpos, Position newpos){
    if(field[oldpos.getX()][oldpos.getY()] == avatar){
        field[oldpos.getX()][oldpos.getY()] = ' ';
    }
    field[newpos.getX()][newpos.getY()] = avatar;
}

void DragonHallow::changeAvatar(char avatar, Position pos){
    field[pos.getX()][pos.getY()] = avatar;
}

void DragonHallow::print(){
    cout << field << endl;
}
