#ifndef DRAGON_H
#define DRAGON_H

#include "Character.h"
#include "Position.h"

/*

DRAGON CLASS
PURPOSE: Dragon class to handle Dragon functionality. Dragon can launch attack
inflicting damage on heros and adding health to fighters
COMPLEX OR CRITICAL MEMBERS:
    - Position attack: Position of dragon attack
    - Function setPosition(int, int): Pure virtual function that sets the Position
    and by adjusting to fit DragonHallow boundaries
    - Function setAttack(): Sets attack position
    - Function updatePosition(): Pure virtual function that updates character's
    position

*/

class Dragon : public Character {

    public:
        Dragon();
        ~Dragon();
        virtual Position updatePosition();
        virtual void setPosition(int, int);
        void setAttack();
        Position attackPosition();

    private:
        Position attack;
        int direction; // 1 is up, 0 is down

};

#endif
