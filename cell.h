#ifndef CELL_H
#define CELL_H

using namespace std;

class Cell {
protected:
    bool top;
    bool right;
    bool bot;
    bool left;
    bool marked;

  public:
    Cell();
    bool isTop();
    bool isRight();
    bool isBot();
    bool isLeft();
    bool isMarked();    // refers to if it has been printed or not

    void setTop(int);
    void setRight(int);
    void setBot(int);
    void setLeft(int);
    void mark();

    void printTop();
    void printBot();
    void printLeft();
    void printRight();

    void printMid();
};

#endif
