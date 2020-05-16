#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*

VIEW CLASS
PURPOSE: Display the main menu and read the user’s selection
COMPLEX OR CRITICAL MEMBERS:
  - Function showMenu(): Displays menu and reads user choice

*/

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readFloat(float&);
    void readStr(string&);
};

#endif
