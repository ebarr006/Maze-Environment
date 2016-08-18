Written by Emilio Barreiro
Contact:   ebarr006@ucr.edu
IEEE-UCR
Github URL: https://github.com/ebarr006/Maze-Environment

SETTING WALLS
  - when building vertical walls, each cell references to the left; can't set a
    right wall. Instead reference left wall of the adjacent and succeeding cell.
    Unless j == 15, if you setRight(1) on a cell it will not appear on the
    printed terminal maze.
      ex 1.1: If I want to set a "right" wall at maze[0][5], I would set a left wall
          at maze[0][6].
