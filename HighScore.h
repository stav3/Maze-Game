

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>

using namespace std;

class HighScore {

private:
    string name;
    int score;

public:

    HighScore();

    HighScore &operator<<(string name);

    void operator<<(int newScore);

    string getName();

    int getScore();

    void setScore(int);

    void setName(string newName);

};


#endif
