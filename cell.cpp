#include <iostream>
#include "cell.h"

using namespace std;

unsigned int n = 0;
unsigned int z = 0;

Cell::Cell() {
  top = false;
  right = false;
  bot = false;
  left = false;
  marked = false;
}

bool Cell::isTop() {
  // cout << "oh \n";
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

bool Cell::isMarked() {
  return marked;
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

void Cell::mark() {
  marked = true;
}

void Cell::printTop() {
  ++n;
  cout << "+";
  if (top) {
    cout << "---";
    // cout << "-" << n << "-";
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
}

void Cell::printRight() {
  //cout << "here\n";
  if (right) {
    cout << "|";
  }
}

void Cell::printMid() {
  if (left) {
    cout << "|   ";
  }



  // if (!left && !right) {
  //   cout << "    ";
  // }
  // else if (left && !right) {
  //   cout << "|    ";
  // }
  // else if (!left && right) {
  //   cout << "    |";
  // }
  // else if (left && right) {
  //   cout << "|   |";
  // }
}

void Cell::printBot() {
  //++z;
  cout << "+";
  if (bot) {
    cout << "---"; // << z;
  }
  else {
    cout << "   ";
  }
}
