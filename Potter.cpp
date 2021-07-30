

#include "Potter.h"


Potter::Potter()  {

    this->id=66;
}


//Initializing position for character


void Potter::initPosition(int rows, int columns, int **map) {

    srand(time(NULL));

    int newx = 0, newy = 0;
    bool check = false;

    do {
        newx = rand() % columns;
        newy = rand() % rows;

        if (map[newy][newx] != (int) '*') check = true;

    } while (!check);

    map[newy][newx] = (int) 'B';

    this->posx = newx;
    this->posy = newy;

}








