

#include "HighScore.h"

HighScore::HighScore() {

    name = " ";
    score = -1;

}

HighScore &HighScore::operator<<(string newName) {
    this->name = newName;
    return *this;
}

void HighScore::operator<<(int newScore) {
    this->score = newScore;

}

string HighScore::getName() {
    return name;
}

int HighScore::getScore() {
    return score;
}

void HighScore::setName(string newName) {
    this->name = newName;
}

void HighScore::setScore(int newScore) {
    this->score = newScore;

}
