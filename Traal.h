

#ifndef TRAAL_H
#define TRAAL_H

#include "Moving.h"

class Traal: public Moving {

public:

    Traal();
    void initTrall(int,int, int **);
    void move(int,int,int **);
};


#endif