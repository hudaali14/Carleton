#ifndef DRAGONHALLOW_H
#define DRAGONHALLOW_H

#include <iostream>
#include <list>

#include "Array.h"
#include "Character.h"
#include "Dragon.h"

using namespace std;

/*

DRAGONHALLOW CLASS
PURPOSE: Keeps track of all characters currently in DragonHallow, prints path, makes changes path, etc.
COMPLEX OR CRITICAL MEMBERS:
    - Array<char> field: 2d array of chars representing the field of play (DragonHallow)
    - list<Character*> characters: Holds list of all characters on the path
    - Function addCharacter(Character*): Adds character to list
    - Function removeCharacter(Character*): Remove character from list
    - Function moveCharacter(char, Position, Position): Moves character's avatar from one position
    to another
    - Function addAvatar(Character*): Adds avatar to character current position on path
    - Function changeAvatar(char, Position): Chnages avatar at position specified in parameter

*/

class DragonHallow{

    public:
        DragonHallow();
        ~DragonHallow();
        void print();
        list<Character*> getCharacters();
        void addAvatar(Character*);
        void addCharacter(Character*);
        void removeCharacter(Character*);
        void moveCharacter(char, Position, Position);
        void changeAvatar(char, Position);

    private:
        Array<char> field;
        list<Character*> characters;
};

#endif
