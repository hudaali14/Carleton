#ifndef CONTROL_H
#define CONTROL_H

#include "Library.h"
#include "View.h"


class Control
{
    public:
        void launch();
        void initBooks();

    private:
        Library library;
        View view;
};

#endif
