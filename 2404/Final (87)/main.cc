#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "Quest.h"

/*

PURPOSE: Creates Quest object and loops through until either Timmy or Harold claims
the Emerald or both heroes are dead
AUTHOR: Huda Ali

*/

int main(){

    Quest quest;
    srand((unsigned)time(NULL));
    while(!quest.isOver()){
        quest.update();
    }
    return 0;

}
