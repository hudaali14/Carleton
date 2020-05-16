#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "Chicken.h"
#include "Cow.h"
#include "Pig.h"


void Control::launch()
{
  int    choice, age, lf, ec, fid, pen;
  string name, milk;

  initAnimals();


  while (1) {
    view.showMenu(choice);
    if (choice == 0){
      ag.print();
      break;
    }

    view.printStr("Farm ID: ");
    view.readInt(fid);
    view.printStr("Name: ");
    view.readStr(name);
    view.printStr("Age: ");
    view.readInt(age);
    view.printStr("Lifespan: ");
    view.readInt(lf);
    float lifespan = (float) lf;
    Animal* animal = NULL;
    if (choice == 1) {
      view.printStr("Egg Count: ");
      view.readInt(ec);
      animal = new Chicken(name, age, lifespan, ec);
    }else if (choice == 2) {
      view.printStr("Milk time: ");
      view.readStr(milk);
      animal = new Cow(name, age, lifespan, milk);

    }else if (choice == 3) {
      view.printStr("Pen number: ");
      view.readInt(pen);
      animal = new Pig(name, age, lifespan, pen);
    }
    if(animal != NULL){
      ag.add(fid, animal);
    }

  }

}

void Control::initAnimals(){
  Farm* f1 = new Farm();
  Farm* f2 = new Farm();
  Farm* f3 = new Farm();
  Farm* f4 = new Farm();
  Farm* f5 = new Farm();

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



  ag.add(f1);
  ag.add(f2);
  ag.add(f3);
  ag.add(f4);
  ag.add(f5);

}
