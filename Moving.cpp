

#include "Moving.h"

void Moving::moveLeft() {

    this->posx--;
}

void Moving::moveRight() {

    this->posx++;
}

void Moving::moveUp() {

    this->posy--;
}

void Moving::moveDown() {

    this->posy++;


}

int Moving::getPosX() {
    return this->posx;
}

int Moving::getPosY() {
    return this->posy;
}

int Moving::getID() {
    return this->id;
}

int Moving::checkConflict(int y, int x, int **map) {

    if (map[y][x] == (int) 'B') return -1;
    else if (map[y][x] == (int) '*') return 1;
    else if (map[y][x] == (int) 'D') return 2;

    return 0;
}

float Moving::distance(int x1, int y1, int x2, int y2) {

    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}