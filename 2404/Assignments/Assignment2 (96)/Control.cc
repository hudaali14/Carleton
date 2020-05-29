#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


void Control::launch()
{
  int    choice, age, lf, ec, fid, pen;
  string name, milk;

  initAnimals();


  while (1) {
    view.showMenu(choice);

    // If user choice is 0 then prints all farms and animals and breaks 
    if (choice == 0){
      ag.print();
      break;
    }

    // Prints and reads all user data
    view.printStr("Farm ID: ");
    view.readInt(fid);
    view.printStr("Name: ");
    view.readStr(name);
    view.printStr("Age: ");
    view.readInt(age);
    view.printStr("Lifespan: ");
    view.readInt(lf);

    // If user choice to add a chicken
    if (choice == 1) {
      //Reads egg count, creates chicken, then add chicken to farm
      view.printStr("Egg Count: ");
      view.readInt(ec);
      Chicken* chicken = new Chicken(name, age, lf, ec);
      ag.add(fid, chicken);

    // If user choice to add a cow
    }else if (choice == 2) {
      //Reads milk time, creates cow, then add cow to farm
      view.printStr("Milk time: ");
      view.readStr(milk);
      Cow* cow = new Cow(name, age, lf, milk);
      ag.add(fid, cow);

    // If user choice to add a pig
    }else if (choice == 3) {
      //Reads pen number, creates pig, then add pig to farm
      view.printStr("Pen number: ");
      view.readInt(pen);
      Pig* pig = new Pig(name, age, lf, pen);
      ag.add(fid, pig);
    }

  }

}

// Initializes farms and animals
void Control::initAnimals(){

  //Creates 5 farms
  Farm* f1 = new Farm();
  Farm* f2 = new Farm();
  Farm* f3 = new Farm();
  Farm* f4 = new Farm();
  Farm* f5 = new Farm();

  // Randomly adds 20 different animals to 5 farms
  f5->add(new Chicken("Chick1", 3, 8, 7));
  f1->add(new Cow("Cow2", 19, 20, "03:30"));
  f4->add(new Pig("Pig3", 3, 10, 2));
  f2->add(new Pig("Pig4", 9, 10, 2));
  f3->add(new Chicken("Chick5", 6, 8, 7));
  f2->add(new Cow("Cow6", 12, 20, "05:45"));
  f4->add(new Chicken("Chick7", 9, 10, 7));
  f5->add(new Pig("Pig8", 1, 10, 2));
  f2->add(new Cow("Cow9", 5, 20, "07:00"));
  f1->add(new Pig("Pig10", 3, 10, 2));
  f5->add(new Cow("Cow11", 9, 20, "08:00"));
  f1->add(new Chicken("Chick12", 4, 8, 7));
  f4->add(new Chicken("Chick13", 2, 8, 3));
  f3->add(new Pig("Pig14", 23, 10, 5));
  f2->add(new Chicken("Chick15", 6, 8, 4));
  f4->add(new Cow("Cow16", 1, 20, "06:30"));
  f5->add(new Cow("Cow17", 3, 20, "05:00"));
  f1->add(new Pig("Pig18", 1, 10, 1));
  f3->add(new Chicken("Chick19", 1, 8, 5));
  f3->add(new Pig("Pig20", 5, 10, 4));

  // Adds farms to ag
  ag.add(f1);
  ag.add(f2);
  ag.add(f3);
  ag.add(f4);
  ag.add(f5);

}
