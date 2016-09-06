#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "maze.h"
#include "cell.h"

using namespace std;

unsigned int t = 0;

Maze::Maze() {
  for (unsigned i = 0; i < 16; ++i) {
    for (unsigned j = 0; j < 16; ++j) {
      if (i == 0) {
        pmaze[0][j].setTop(1);        // top border
        rmaze[0][j].setTop(1);
      }
      if (j == 15) {
        pmaze[i][15].setRight(1);      // right border
        rmaze[i][15].setRight(1);
      }
      if (i == 15) {
        pmaze[15][j].setBot(1);        // bottom border
        rmaze[15][j].setBot(1);
      }
      if (j == 0) {
        pmaze[i][0].setLeft(1);         // left border
        rmaze[i][0].setLeft(1);
      }
    }
  }
  iPos = 15;
  jPos = 0;
  a = -1; b = -1; c = -1;
  d = -1; e = -1; f = -1;
  face = 0;

  displayMaze();
}


void Maze::displayMaze() {
  for (unsigned i = 0 ; i < 16; ++i)
  {
    for (unsigned k = 0; k < 2; ++k)
    {
      for (unsigned j = 0; j < 16; ++j)
      {
        if (k == 0) {
          pmaze[i][j].printTop();
          if (j == 15) {
            cout << "+";
          }
        }
        else if (k == 1) {
          if ((i == iPos) && (j == jPos)) {
            pmaze[i][j].printWithChar();
            if (face == 0) {
              cout << " ^ ";
            }
            else if (face == 1) {
              cout << " > ";
            }
            else if (face == 2) {
              cout << " v ";
            }
            else if (face == 3) {
              cout << " < ";
            }
          }
          else {
            pmaze[i][j].printLeft();
          }
          if (j == 15 && (pmaze[i][j].isRight())) {
            pmaze[i][j].printRight();
          }

          // OLD in case above doesnt work
          // pmaze[i][j].printLeft();
          // if (j == 15 && (pmaze[i][j].isRight())) {
          //   pmaze[i][j].printRight();
          // }
        }
      }
      cout << endl;
    }
    if (i == 15) {
      for (unsigned n = 0; n < 16; ++n)
      {
        pmaze[i][n].printBot();
      }
      cout << "+";    // last corner, bottom right
    }
  }
  cout << endl << endl;
}

void Maze::peripherals() {
  switch (face) {
    case 0:
      if (rmaze[iPos][jPos].isLeft()) {
        pmaze[iPos][jPos].setLeft(1);
        if (jPos != 0) {   // not along left side column, where next line of code would cause a seg fault
          pmaze[iPos][jPos-1].setRight(1);
        }
        a = -1;
      }
      else if (!(rmaze[iPos][jPos].isLeft())) {
        a = 3;    // option 3 is submitted to temp holder
      }
      if (!rmaze[iPos][jPos].isLeft() && !rmaze[iPos][jPos-1].isDiscovered()) {
        d = 3;
      }

      if (rmaze[iPos][jPos].isTop()) {
        pmaze[iPos][jPos].setTop(1);
        if (iPos != 0) {
          pmaze[iPos-1][jPos].setBot(1);
        }
        b = -1;
      }
      else if (!(rmaze[iPos][jPos].isTop())) {
        b = 0;    // option 0 is submitted to temp holder
      }
      if (!rmaze[iPos][jPos].isTop() && !rmaze[iPos-1][jPos].isDiscovered()) {
        e = 0;
      }

      if (rmaze[iPos][jPos].isRight()) {
        pmaze[iPos][jPos].setRight(1);
        if (jPos != 15) {
          pmaze[iPos][jPos+1].setLeft(1);
        }
        c = -1;
      }
      else if (!(rmaze[iPos][jPos].isRight())) {
        c = 1;
      }
      if ((!(rmaze[iPos][jPos].isRight())) && (!(rmaze[iPos][jPos+1].isDiscovered()))) {
        f = 1;
      }
      break;

    case 1:
      if (rmaze[iPos][jPos].isTop()) {
        pmaze[iPos][jPos].setTop(1);
        if (iPos != 0) {
          pmaze[iPos-1][jPos].setBot(1);
        }
        a = -1;
      }
      else if (!(rmaze[iPos][jPos].isTop())) {
        a = 0;
      }
      if ((!(rmaze[iPos][jPos].isTop())) && (!(rmaze[iPos-1][jPos].isDiscovered()))) {
        d = 0;
      }

      if (rmaze[iPos][jPos].isRight()) {
        pmaze[iPos][jPos].setRight(1);
        if (jPos != 15) {
          pmaze[iPos][jPos+1].setLeft(1);
        }
        b = -1;
      }
      else if (!(rmaze[iPos][jPos].isRight())) {
        b = 1;
      }
      if ((!(rmaze[iPos][jPos].isRight())) && (!(rmaze[iPos][jPos+1].isDiscovered()))) {
        e = 1;
      }

      if (rmaze[iPos][jPos].isBot()) {
        pmaze[iPos][jPos].setBot(1);
        if (iPos != 15) {
          pmaze[iPos+1][jPos].setTop(1);
        }
        c = -1;
      }
      else if (!(rmaze[iPos][jPos].isBot())) {
        c = 2;
      }
      if ((!(rmaze[iPos][jPos].isBot())) && (!(rmaze[iPos+1][jPos].isDiscovered()))) {
        f = 2;
      }
      break;

    case 2:
      if (rmaze[iPos][jPos].isRight()) {
        pmaze[iPos][jPos].setRight(1);
        if (jPos != 15) {
          pmaze[iPos][jPos+1].setLeft(1);
        }
        a = -1;
      }
      else if (!(rmaze[iPos][jPos].isRight())) {
        a = 1;
      }
      if ((!(rmaze[iPos][jPos].isRight())) && (!(rmaze[iPos][jPos+1].isDiscovered()))) {
        d = 1;
      }

      if (rmaze[iPos][jPos].isBot()) {
        pmaze[iPos][jPos].setBot(1);
        if (iPos != 15) {
          pmaze[iPos+1][jPos].setTop(1);
        }
        b = -1;
      }
      else if (!(rmaze[iPos][jPos].isBot())) {
        b = 2;
      }
      if ((!(rmaze[iPos][jPos].isBot())) && (!(rmaze[iPos+1][jPos].isDiscovered()))) {
        e = 2;
      }

      if (rmaze[iPos][jPos].isLeft()) {
        pmaze[iPos][jPos].setLeft(1);
        if (jPos != 0) {
          pmaze[iPos][jPos-1].setRight(1);
        }
        c = -1;
      }
      else if (!(rmaze[iPos][jPos].isLeft())) {
        c = 3;
      }
      if ((!(rmaze[iPos][jPos].isLeft())) && (!(rmaze[iPos][jPos-1].isDiscovered()))) {
        f = 3;
      }
      break;

    case 3:
      if (rmaze[iPos][jPos].isBot()) {
        pmaze[iPos][jPos].setBot(1);
        if (iPos != 15) {
          pmaze[iPos+1][jPos].setTop(1);
        }
        a = -1;
      }
      else if (!(rmaze[iPos][jPos].isBot())) {
        a = 2;
      }
      if ((!(rmaze[iPos][jPos].isBot())) && (!(rmaze[iPos+1][jPos].isDiscovered()))) {
        d = 2;
      }

      if (rmaze[iPos][jPos].isLeft()) {
        pmaze[iPos][jPos].setLeft(1);
        if (jPos != 0) {
          pmaze[iPos][jPos-1].setRight(1);
        }
        b = -1;
      }
      else if (!(rmaze[iPos][jPos].isLeft())) {
        b = 3;
      }
      if ((!(rmaze[iPos][jPos].isLeft())) && (!(rmaze[iPos][jPos-1].isDiscovered()))) {
        e = 3;
      }

      if (rmaze[iPos][jPos].isTop()) {
        pmaze[iPos][jPos].setTop(1);
        if (iPos != 0) {
          pmaze[iPos-1][jPos].setBot(1);
        }
        c = -1;
      }
      else if (!(rmaze[iPos][jPos].isTop())) {
        c = 0;
      }
      if ((!(rmaze[iPos][jPos].isTop())) && (!(rmaze[iPos-1][jPos].isDiscovered()))) {
        f = 0;
      }
      break;
  }
  cout << "a: " << a << "   b: " << b << "   c: " << c << endl;
}

int Maze::logic() {
  // for u-turns
  if ((a == -1) && (b == -1) && (c == -1)) {
    if (face == 0 || face == 1) {
      face += 2;
    }
    else if (face == 2 || face == 3) {
      face -= 2;
    }
    return face;
  }

  // priority held for undiscovered paths
  srand(time(0));
  int select = -1;
  int result = -1;
  while (result == -1) {
    if (d == -1 && e == -1 && f == -1) {
      break;
    }
    select = rand() % 4;      // later may have to change to 5 to include 4 (u-turns)
    cout << "here" << endl;
    if (d == select || e == select || f == select) {
      result = select;
      cout << "undiscovered select: " << select << endl;
      return select;
    }
  }

  // randomly chooses left, right, or straight
  // if an option is labeled -1, it won't be selected within the while loop
  // because of the range for rand()
  select = -1;
  result = -1;
  while (result == -1) {
    select = rand() % 4;      // later may have to change to 5 to include 4 (u-turns)
    cout << "select: " << select << endl;
    if (a == select || b == select || c == select) {
      result = select;
    }
  }
  // cout << "Path chosen: " << result << endl;
  if (result == -1) {
    cout << "ERROR: RESULT == -1. Refer to int Maze::logic()" << endl;
  }
  return result;
}

void Maze::moveMouse(int z) {
  // depending on orientation, move mouse to path provided by logic()
  // increment/decrement iPos/jPos accordingly, change face if needed
  cout << "before: " << iPos << ", " << jPos << endl;
  cout << "facing: " << z << endl;
  face = z;
  switch (z) {
    case 0:
      --iPos;
      break;
    case 1:
      ++jPos;
      break;
    case 2:
      ++iPos;
      break;
    case 3:
      --jPos;
      break;
  }
  cout << "after: " << iPos << ", " << jPos << endl;
  rmaze[iPos][jPos].setDiscovered();
  d = -1; e = -1; f = -1;     // reset the undiscovered placeholders
}

void Maze::rotate(int r) {
  face = r;
}

void Maze::inputMaze() {
  ifstream file;
  int status = 0; int i = 0; int j = 0;// char c;
  file.open("maze.txt");
  while ((i != 16) && (j != 16)) {
    file >> status;
    switch (status) {
      case 0:             // 00
        break;
      case 1:             // 01
        rmaze[i][j].setTop(1);
        if (i != 0) {
          rmaze[i-1][j].setBot(1);
        }
        break;
      case 10:            // 10
        rmaze[i][j].setLeft(1);
        if (j != 0) {
          rmaze[i][j-1].setRight(1);
        }
        break;
      case 11:
        rmaze[i][j].setLeft(1);
        rmaze[i][j].setTop(1);
        if (j != 0) {
          rmaze[i][j-1].setRight(1);
        }
        if (i != 0) {
          rmaze[i-1][j].setBot(1);
        }
        break;
    }
    ++j;
    if (j == 16) {
      j = 0;
      ++i;
    }
  }
}

bool Maze::isCenter() {
  if (iPos == 7 && jPos == 7) {
    return true;
  }
  if (iPos == 7 && jPos == 8) {
    return true;
  }
  if (iPos == 8 && jPos == 7) {
    return true;
  }
  if (iPos == 8 && jPos == 8) {
    return true;
  }
  else
    return false;
}

void Maze::printImport() {
  char c;
  cout << "Display imported sample? ";
  cin >> c;

  if (c == 'y') {
    for (unsigned i = 0 ; i < 16; ++i)
    {
      for (unsigned k = 0; k < 2; ++k)
      {
        for (unsigned j = 0; j < 16; ++j)
        {
          if (k == 0) {
            rmaze[i][j].printTop();
            if (j == 15) {
              cout << "+";
            }
          }
          else if (k == 1) {
            if ((i == iPos) && (j == jPos)) {
              rmaze[i][j].printWithChar();
              if (face == 0) {
                cout << " ^ ";
              }
              else if (face == 1) {
                cout << " > ";
              }
              else if (face == 2) {
                cout << " v ";
              }
              else if (face == 3) {
                cout << " < ";
              }
            }
            else {
              rmaze[i][j].printLeft();
            }
            if (j == 15 && (pmaze[i][j].isRight())) {
              rmaze[i][j].printRight();
            }
          }
        }
        cout << endl;
      }
      if (i == 15) {
        for (unsigned n = 0; n < 16; ++n)
        {
          rmaze[i][n].printBot();
        }
        cout << "+";    // last corner, bottom right
      }
    }
    cout << endl << endl;
  }
  else {
    cout << "Fin" << endl;
  }
}
