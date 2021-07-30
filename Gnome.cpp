
#include "Gnome.h"

Gnome::Gnome() {

    this->id = 71;
}

void Gnome::initGnome(int rows, int columns, int **map) {

    srand(time(NULL));

    int newx = 0, newy = 0;
    bool check = false;

    do {
        newx = rand() % columns;
        newy = rand() % rows;

        if (map[newy][newx] != (int) '*' && map[newy][newx] != (int) 'D' && map[newy][newx] != (int) 'B') {
            check = true;
            this->posx = newx;
            this->posy = newy;
            map[posy][posx] = id;

        }
    } while (!check);
}

void Gnome::move(int y, int x, int **map) {


    float up = distance(x, y, posx, posy - 1);
    float min = up;
    float down = distance(x, y, posx, posy + 1);
    if (down < min) min = down;
    float left = distance(x, y, posx - 1, posy);
    if (left < min) min = left;
    float right = distance(x, y, posx + 1, posy);
    if (right < min) min = right;

    if (min == up && checkConflict(posy - 1, posx, map) != 1) {

        this->moveUp();


    } else if (min == down && checkConflict(posy + 1, posx, map) != 1) {

        this->moveDown();
    } else if (min == left && checkConflict(posy, posx - 1, map) != 1) {

        this->moveLeft();
    } else if (checkConflict(posy, posx + 1, map) != 1) {

        this->moveRight();
    }


}


