
#ifndef GNOME_H
#define GNOME_H

#include "Moving.h"

class Gnome: public Moving {


public:

    Gnome();
    void initGnome(int,int,int **);
    void move(int,int, int **);

};


#endif