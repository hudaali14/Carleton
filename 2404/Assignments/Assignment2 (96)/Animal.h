#ifndef ANIMAL_H
#define ANIMAL_H

/*

ANIMAL CLASS
PURPOSE: Animal class with a name, age, and lifespan

*/

class Animal
{
  public:
    Animal(string="Fluffy", int=0, float=0);
    ~Animal();
    string getName() const;
    int    getAge()  const;
    virtual void print() const;

  protected:
    float  lifespan;

  private:
    string name;
    int    age;
};

#endif
