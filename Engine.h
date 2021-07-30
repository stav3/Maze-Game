
#ifndef Engine_h
#define Engine_h

#include <ncurses.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Potter.h"
#include <cstdlib>
#include <unistd.h>
#include "Gnome.h"
#include "Traal.h"
#include "HighScore.h"
#include <cstring>

using namespace std;

class Engine {

private:

    int **map;
    int rows;
    int columns;
    Potter babis;
    Gnome mon1;
    Traal mon2;
    int diamond;
    HighScore scoreList[5];

public:

    Engine(const string &, const string &);

    ~Engine();

    void prepareUI();

    void placeComponents();

    void placeDiamonds();

    void mainGame(int, int);

    int checkConflict(int, int);

    void endGame(int score);

    void summonGoldenKey();

    void getHighScores(const string &);
};


#endif
