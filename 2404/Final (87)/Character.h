#ifndef CHARACTER_H
#define CHARACTER_H

#include "Position.h"

/*

CHARACTER CLASS
PURPOSE: Base class for all the different types of quest players
COMPLEX OR CRITICAL MEMBERS:
    - Function setPosition(int, int): Pure virtual function that sets the Position
    and by adjusting to fit DragonHallow boundaries
    - Function setHealth(int): Virtual function that sets health of character
    - Function updatePosition(): Pure virtual function that updates character's
    position
    - Function dragonAttack(): Handles attack launched by dragon

*/

class Character{

    public:
        Character();
        ~Character();
        Position getPosition();
        char getAvatar();
        int getHealth();
        int getStrength();
        bool isDown();
        virtual void setPosition(int, int) = 0;
        virtual void setHealth(int);
        virtual Position updatePosition() = 0;
        virtual void dragonAttack();

    protected:
        Position currentPosition;
        char avatar;
        int health;
        int strength;
        bool down;

};

#endif
