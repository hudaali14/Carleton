#ifndef CONTROL_H
#define CONTROL_H

#include "AgCoop.h"
#include "View.h"

/*

CONTROL CLASS
PURPOSE: Implements the control flow for the entire program
COMPLEX OR CRITICAL MEMBERS:
  - Agricultural group
  - View
  - Function launch():  Implements the program control flow
  - Function initAnimals(): Initializes the farms and animals contained in the
agricultural cooperative

*/

class Control
{
  public:
    void launch();
    void initAnimals();

  private:
    AgCoop ag;
    View view;
};

#endif
