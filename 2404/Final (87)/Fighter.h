#ifndef FIGHTER_H
#define FIGHTER_H

#include "Character.h"
#include "Position.h"

/*

FIGHTER CLASS
PURPOSE: Guard the dragon's cave and protect it from the heros Timmy and Harold
COMPLEX OR CRITICAL MEMBERS:
    - Function setPosition(int, int): Pure virtual function that sets the Position
    and by adjusting to fit DragonHallow boundaries
    - Function updatePosition(): Pure virtual function that updates character's
    position
    - Function dragonAttack(): Handles attack launched by dragon

*/

class Fighter : public Character {

    public:
        Fighter(char, int, int);
        ~Fighter();
        virtual Position updatePosition();
        virtual void setPosition(int, int);
        virtual void dragonAttack();
};

#endif
