#ifndef CELL_H
#define CELL_H

using namespace std;

class Cell {
  protected:
    bool top;
    bool right;
    bool bot;
    bool left;
    bool found;
    // int face;

  public:
    Cell();
    bool isTop();
    bool isRight();
    bool isBot();
    bool isLeft();

    void setTop(int);
    void setRight(int);
    void setBot(int);
    void setLeft(int);

    void printTop();
    void printBot();
    void printLeft();
    void printWithChar();
    void printRight();

    void setFace(int);
    int returnFace();

    void setDiscovered();
    bool isDiscovered();
};

#endif
