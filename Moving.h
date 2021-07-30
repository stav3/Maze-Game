

#ifndef MOVING_H
#define MOVING_H
#include <math.h>
#include <cstdlib>
#include <time.h>


using namespace std;

class Moving {

protected:
    int id;
    int posx;
    int posy;

public:

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    int getPosX();
    int getPosY();
    int getID();

    int checkConflict(int , int ,int **);
    float distance(int x1,int y1,int x2,int y2);
};


#endif
