#include <iostream>
#include "cell.h"

using namespace std;
//       0
//    +----+
//  3 | 10 | 1
//    +----+
//       2

Cell::Cell() {
  top = false;
  right = false;
  bot = false;
  left = false;
  // face = 0;
}

bool Cell::isTop() {
  return top;
}

bool Cell::isRight() {
  return right;
}

bool Cell::isBot() {
  return bot;
}

bool Cell::isLeft() {
  return left;
}

void Cell::setTop(int z) {
  if (z == 1) {
    top = true;
  }
  else
    top = false;
}

void Cell::setRight(int z) {
  if (z == 1) {
    right = true;
  }
  else
    right = false;
}
void Cell::setBot(int z) {
  if (z == 1) {
    bot = true;
  }
  else
    bot = false;
}

void Cell::setLeft(int z) {
  if (z == 1) {
    left = true;
  }
  else
    left = false;
}

void Cell::printTop() {
  cout << "+";
  if (top) {
    cout << "---";
  }
  else {
    cout << "   ";
  }
}

void Cell::printBot() {
  cout << "+";
  if (bot) {
    cout << "---";
  }
  else {
    cout << "   ";
  }
}

void Cell::printLeft() {
  if (left) {
    cout << "|   ";
  }
  else {
    cout << "    ";
  }
}   // 4 spaces total

void Cell::printWithChar() {
  if (left) {
    cout << "|";
  }
  else {                          // with/without a wall. if there print it, if not its a space
    cout << " ";
  }
  // if (face == 0) {
  //   cout << " ^ ";
  // }
  // else if (face == 1) {
  //   cout << " > ";
  // }
  // else if (face == 2) {
  //   cout << " v ";
  // }
  // else if (face == 3) {
  //   cout << " < ";
  // }
}     // 4 spaces total

void Cell::printRight() {
  //cout << "here\n";
  if (right) {
    cout << "|";
  }
}

// void Cell::setFace(int m) {
//   face = m;
// }
//
// int Cell::returnFace() {
//   return face;
// }
