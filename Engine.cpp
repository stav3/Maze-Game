

#include "Engine.h"


Engine::Engine(const string &inputFile, const string &binInput) : diamond(10) {

    ifstream mapInput;
    mapInput.open(inputFile);                       //"/home/stav/Mpampis/map.txt"
    int countx = 0, county = 0, i = 0, j = 0;
    string test;

    try {
        if (!mapInput) throw -1;

        while (!mapInput.eof()) {

            getline(mapInput, test);
            if (county == 0)
                countx = test.size();

            county++;

        }


        mapInput.clear();
        mapInput.seekg(0);
        countx++;

        //cout << "I have counted " << countx << " columns and " << county << " rows\n";

        rows = county - 1;
        columns = countx;

        map = new int *[county];
        for (i = 0; i < county; ++i)
            map[i] = new int[countx];

        for (i = 0; i < county; i++) {
            for (j = 0; j < countx; j++) {
                map[i][j] = 0;

            }
        }

        i = j = 0;

        while (!mapInput.eof()) {
            map[i][j] = mapInput.get();
            if (map[i][j] == int('\n')) {
                i++;
                j = 0;
            }
            j++;

        }
        mapInput.close();

        getHighScores(binInput);
    }
    catch (int x) {
        cout << "FILE ERROR, COULD NOT READ OR FIND... EXITING !\n";
        exit(x);
    }
}


void Engine::prepareUI() {


    int i = 0, j = 0, cury = 0, curx = 0;
    char ch = ' ';

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    cbreak();

    placeDiamonds();

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            mvaddch(i, j, map[i][j]);
        }
    }

    placeComponents();

    curx = babis.getPosX();
    cury = babis.getPosY();

    mvaddch(mon1.getPosY(), mon1.getPosX(), (char) mon1.getID());
    mvaddch(mon2.getPosY(), mon2.getPosX(), (char) mon2.getID());
    mvaddch(cury, curx, (char) babis.getID());

    refresh();

    mainGame(cury, curx);

}

void Engine::mainGame(int cury, int curx) {

    char ch = ' ';
    int score = 0;

    do {
        ch = getch ();


        switch (ch) {
            case (char) KEY_UP :

                if (checkConflict(cury - 1, curx) == 1) {
                    break;
                }

                if (checkConflict(cury - 1, curx) == 2) {
                    diamond++;
                    score = score + 10;
                    map[cury - 1][curx] = 0;
                }

                if (checkConflict(cury - 1, curx) == -1) {
                    ch = 27;
                    break;
                }

                if (checkConflict(cury - 1, curx) == 3) {
                    ch = 27;
                    score = score + 100;
                    break;
                }

                mvaddch(babis.getPosY(), babis.getPosX(), ' ');
                babis.moveUp();
                cury--;
                break;

            case (char) KEY_DOWN :

                if (checkConflict(cury + 1, curx) == 1) {
                    break;
                }
                if (checkConflict(cury + 1, curx) == 2) {
                    diamond++;
                    score = score + 10;
                    map[cury + 1][curx] = 0;
                }

                if (checkConflict(cury + 1, curx) == -1 || checkConflict(cury + 1, curx) == 3) {
                    ch = 27;
                    break;
                }

                if (checkConflict(cury + 1, curx) == 3) {
                    ch = 27;
                    score = score + 100;
                    break;
                }


                mvaddch(babis.getPosY(), babis.getPosX(), ' ');
                babis.moveDown();

                cury++;
                break;

            case (char) KEY_LEFT:
                if (checkConflict(cury, curx - 1) == 1) {
                    break;
                }
                if (checkConflict(cury, curx - 1) == 2) {
                    diamond++;
                    score = score + 10;
                    map[cury][curx - 1] = 0;
                }
                if (checkConflict(cury, curx - 1) == -1 || checkConflict(cury, curx - 1) == 3) {
                    ch = 27;
                    break;
                }

                if (checkConflict(cury, curx - 1) == 3) {
                    score = score + 100;
                    ch = 27;
                    break;
                }

                mvaddch(babis.getPosY(), babis.getPosX(), ' ');

                curx--;
                babis.moveLeft();
                break;

            case (char) KEY_RIGHT:
                if (checkConflict(cury, curx + 1) == 1) {
                    break;
                }
                if (checkConflict(cury, curx + 1) == 2) {
                    diamond++;
                    score = score + 10;
                    map[cury][curx + 1] = 0;
                }

                if (checkConflict(cury, curx + 1) == -1 || checkConflict(cury, curx + 1) == 3) {
                    ch = 27;
                    break;
                }
                if (checkConflict(cury, curx + 1) == 3) {
                    score = score + 100;
                    ch = 27;
                    break;
                }


                mvaddch(babis.getPosY(), babis.getPosX(), ' ');

                babis.moveRight();
                curx++;
                map[cury][curx] = (int) 'B';
                break;

            case ' ':
                break;

        }

        mvaddch(mon1.getPosY(), mon1.getPosX(), ' ');
        mvaddch(mon2.getPosY(), mon2.getPosX(), ' ');
        mon1.move(babis.getPosY(), babis.getPosX(), map);
        mon2.move(babis.getPosY(), babis.getPosX(), map);
        mvaddch(mon1.getPosY(), mon1.getPosX(), (char) mon1.getID());
        mvaddch(mon2.getPosY(), mon2.getPosX(), (char) mon2.getID());
        mvaddch(babis.getPosY(), babis.getPosX(), (char) babis.getID());

        if ((mon1.getPosY() == babis.getPosY() && mon1.getPosX() == babis.getPosX()) ||
            mon2.getPosY() == babis.getPosY() && mon2.getPosX() == babis.getPosX())
            break;

        if (diamond == 10) {

            //Η τελική περγαμηνή

            summonGoldenKey();
            diamond = -1;
        }

    } while (ch != 27);

    endGame(score);
}


void Engine::placeComponents() {

    babis.initPosition(rows, columns, map);
    mon1.initGnome(rows, columns, map);
    mon2.initTrall(rows, columns, map);

}

void Engine::placeDiamonds() {

    srand(time(NULL));

    int posx = rand() % columns;
    int posy = rand() % rows;

    do {


        if (map[posy][posx] != (char) '*' && posy != babis.getPosY() && posx != babis.getPosX()) {

            map[posy][posx] = (int) 'D';
            diamond--;

        }

        posy = rand() % rows;
        posx = rand() % columns;

    } while (diamond > 0);

}

int Engine::checkConflict(int y, int x) {

    if (map[y][x] == (int) 'G') return -1;
    else if (map[y][x] == (int) '*') return 1;
    else if (map[y][x] == (int) 'D') return 2;
    else if (map[y][x] == (int) 'W') return 3;

    return 0;
}

void Engine::summonGoldenKey() {

    int randx = 0, randy = 0;
    bool check = false;

    srand(time(NULL));


    do {
        randx = rand() % columns;
        randy = rand() % rows;
        if (checkConflict(randy, randx) == 0) {
            map[randy][randx] = (int) 'W';
            check = true;
        }
    } while (check == false);

    mvaddch(randy, randx, 'W');
}


void Engine::endGame(int scr) {

    char s[10];
    int count = 0, x = 30, y = 20;
    string name;

    clear();
    mvprintw(20, 30, "END OF GAME:) \n Enter your name: ");
    refresh();
    getstr(s);

    mvprintw(20, 30, "Thank you %s", s);
    refresh();
    sleep(3);
    clear();

    for (int i = 0; i < 5; i++) {

        if (scoreList[i].getScore() < scr) {
            scoreList[i] << s << scr;
            break;
        }
    }
    mvprintw(y, 30, "Score List: \n");
    y++;
    for (int i = 0; i < 5; i++) {

        strcpy(s, scoreList[i].getName().c_str());
        mvprintw(y + i, 30, "%s: ", s);
        mvprintw(y + i, x + 5, " %d", scoreList[i].getScore());
        refresh();
    }
    sleep(3);

    ofstream output;
    output.open("data.bin", ios::binary);

    for (int i = 0; i < 5; i++) {
        output << scoreList[i].getName() << " " << scoreList[i].getScore() << "  \n";
    }
    output.close();

}

void Engine::getHighScores(const string &path) {

    ifstream input;
    input.open(path); //*/home/stav/Mpampis/data.bin*
    int i = 0, newScore;
    string newName, grb;

    if (input) {
        while (!input.eof() && i < 5) {
            input >> newName;
            input >> newScore;
            scoreList[i].setName(newName);
            scoreList[i].setScore(newScore);

            i++;
        }
    }

    input.close();

}

Engine::~Engine() {


    endwin();

    // this loop produces some kind of error, investigate

//    for (int i = 0; i < rows -1; i++) {
//        delete[] map[i];
//    }

    delete[] map;
}




