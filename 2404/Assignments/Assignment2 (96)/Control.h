#ifndef CONTROL_H
#define CONTROL_H

#include "AgCoop.h"
#include "View.h"
#include "Chicken.h"
#include "Cow.h"
#include "Pig.h"

/*

CONTROL CLASS
PURPOSE: Implements the control flow for the entire program
COMPLEX OR CRITICAL MEMBERS:
  - Agricultural group: Manages a collection of farms
  - View: Display the main menu and read the user’s selection
  - Function launch():  Implements the program control flow
  - Function initAnimals(): Initializes the farms and animals contained in the
agricultural cooperative

*/

class Control
{
  public:
    void launch();

  private:
    void initAnimals();
    AgCoop ag;
    View view;
};

#endif
