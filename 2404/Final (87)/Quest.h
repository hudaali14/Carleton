#ifndef QUEST_H
#define QUEST_H

#include "DragonHallow.h"
#include "Hero.h"
#include "Fighter.h"

/*

QUEST CLASS
PURPOSE: Implements the control flow for the entire program
COMPLEX OR CRITICAL MEMBERS:
    - DragonHallow path
    - Dragon dragon
    - Hero Timmy
    - Hero Harold
    - Function update():  Implements the program control flow
    - Function collsion(Hero*, Character*): Handle collsion between hero and fighter
    - Function timmyOrHarold(Character*): Return true if Character is Timmy or Harold
    - Function timmyorHarold(Character*): Return character that in the same position
    as either Timmy or Harold

*/

class Quest{

    public:
        Quest();
        ~Quest();
        bool isOver();
        void update();
        bool timmyOrHarold(Character*);
        Hero* timmyorHarold(Character*);
        void collsion(Hero*, Character*);
        void print();

    private:
        DragonHallow path;
        Dragon* dragon;
        Hero* timmy;
        Hero* harold;
        bool over;

};

#endif
