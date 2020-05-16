#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Control.h"
#include "Logger.h"

Control::Control()
{
    CheckInLogger* checkin = new CheckInLogger();
    library.subscribe(checkin);
    CheckOutLogger* checkout = new CheckOutLogger();
    library.subscribe(checkout);

}

void Control::launch()
{
    int bookId;
    int choice;

    initBooks();

    while (1) {
        view.showMenu(choice);

        if (choice == 0){
            library.print();
            break;
        }

        view.printStr("Book id: ");
        view.readInt(bookId);

        Book* b = library.find(bookId);

        if (choice == 1){
            if(b != NULL){
                library.checkout(b);
            }else{
                cout<< "Sorry book with that ID could not be found" << endl;
            }
        }else if (choice == 2){
            if(b != NULL){
                library.checkin(b);
            }else{
                cout<< "Sorry book with that ID could not be found" << endl;
            }
        } 

    }

}

void Control::initBooks()
{
    Book* b;

    b = new Book("Ender's Game", "Card, Orson Scott");
    library.add(b);
    b = new Book("Dune", "Herbert, Frank");
    library.add(b);
    b = new Book("Foundation", "Asimov, Isaac");
    library.add(b);
    b = new Book("Hitch Hiker's Guide to the Galaxy", "Adams, Douglas");
    library.add(b);
    b = new Book("1984", "Orwell, George");
    library.add(b);
    b = new Book("Stranger in a Strange Land", "Heinlein, Robert A.");
    library.add(b);
    b = new Book("Farenheit 451", "Bradbury, Ray");
    library.add(b);
    b = new Book("2001:  A Space Odyssey", "Clarke, Arthur C.");
    library.add(b);
    b = new Book("I, Robot", "Asimov, Isaac");
    library.add(b);
    b = new Book("Starship Troopers", "Heinlein, Robert A.");
    library.add(b);
    b = new Book("Do Androids Dream of Electric Sheep?", "Dick, Philip K.");
    library.add(b);
    b = new Book("Neuromancer", "Gibson, William");
    library.add(b);
    b = new Book("Ringworld", "Niven, Larry");
    library.add(b);
    b = new Book("Rendezvous with Rama", "Clarke, Arthur C.");
    library.add(b);
    b = new Book("Hyperion", "Simmons, Dan");
    library.add(b);
}

