#include <iostream>
#include "maze.h"
#include "cell.h"

using namespace std;

Maze::Maze() {
  // Do not .setRight(int) on any cells that are not the right hand wall.
  xPos = 0;
  yPos = 2;

  maze[0][2].setTop(1);
  maze[0][3].setLeft(1);
  maze[0][4].setLeft(1);
  maze[7][7].setTop(1);
  maze[15][5].setBot(1);
  maze[15][0].setBot(1);



  // READ ME EXAMPLE 1.1
  // will set left wall at [0][6] as well as right wall of [0][5]
  maze[0][6].setLeft(1);
}


void Maze::displayMaze() {
  for (unsigned i = 0 ; i < 16; ++i)
  {
    for (unsigned k = 0; k < 2; ++k)
    {
      for (unsigned j = 0; j < 16; ++j)
      {
        if (k == 0) {
          maze[i][j].printTop();
          if (j == 15) {
            cout << "+";
          }
        }
        else if (k == 1) {
          maze[i][j].printLeft();
          if (j == 15 && (maze[i][j].isRight())) {
            maze[i][j].printRight();
          }
        }
      }
      cout << endl;
    }
    if (i == 15) {
      for (unsigned n = 0; n < 16; ++n)
      {
        maze[i][n].printBot();
      }
      cout << "+";    // last corner, bottom right
    }
  }
  cout << endl;
}



// void Maze::displayMaze() {
//   for (unsigned i = 0; i < 16; ++i)
//   {
//     for (unsigned k = 0; k < 2; ++k)
//     {
//       for (unsigned j = 0; j < 16; ++j)
//       {
//         if (k == 0) {
//           if (i == 0) {     // edge case TOP ROW
//             if (maze[i][j].isTop() && !(maze[i][j].isMarked())) {
//               maze[i][j].printTop();
//               maze[i][j].mark();
//             }
//           }
//           else if ((maze[i][j].isTop() || maze[i-1][j].isBot()) && !(maze[i-1][j].isMarked())) {
//             maze[i][j].printTop();
//             maze[i][j].mark();
//             //cout << "X";
//           }
//         }
//         if (k == 1)
//         {
//           if (i == 15) {    // edge case BOT ROW
//             if (maze[i][j].isBot() && !(maze[i][j].isMarked())) {
//               maze[i][j].printBot();
//               maze[i][j].mark();
//             }
//           }
//           if (j == 0) {   // edge case LEFT SIDE COLUMN
//             if (maze[i][j].isLeft() && !(maze[i][j].isMarked())) {
//               maze[i][j].printLeft();
//               maze[i][j].mark();
//             }
//           }
//           else if (j == 15) {   // edge case RIGHT SIDE COLUMN
//             if (maze[i][j].isRight() && !(maze[i][j].isMarked())) {
//               maze[i][j].printRight();
//               maze[i][j].mark();
//             }
//           }
//           else if ((maze[i][j].isLeft() || maze[i][j-1].isRight()) && !(maze[i][j-1].isMarked())) {
//             maze[i][j].printLeft();
//             maze[i][j].printLeft();
//           }
//         }
//         cout << j;
//       }
//       cout << endl;
//     }
//     cout << endl;
//   }
// }
