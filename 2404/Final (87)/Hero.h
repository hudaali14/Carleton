#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Position.h"

/*

HERO CLASS
PURPOSE: Cross Dragon’s Hollow and rescue the Emerald without dying
COMPLEX OR CRITICAL MEMBERS:
    - Emerald: Boolean value to check whether Hero has reached cave to obtain emerald
    - Function setHealth(int): Virtual function that sets health of character
    - Function setPosition(int, int): Pure virtual function that sets the Position
    and by adjusting to fit DragonHallow boundaries
    - Function updatePosition(): Pure virtual function that updates character's
    position
    - Function dragonAttack(): Handles attack launched by dragon

*/

class Hero : public Character {

    public:
        Hero(char, int, int);
        ~Hero();
        int getArmour();
        bool getEmerald();
        void setDown();
        virtual void setHealth(int);
        virtual Position updatePosition();
        virtual void setPosition(int, int);
        virtual void dragonAttack();

    private:
        int armour;
        bool emerald;
};

#endif
