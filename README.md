# Maze-Environment
Written by Emilio Barreiro, IEEE-UCR

### Overview
A terminal simulation for testing micromouse maze solving algorithms. Sample mazes are imported to the program from maze.txt.
The current version only uses a random search approach. I am currently working on a floodfill algorithm to implement. Once finished, the program will allow users to choose a random search, flood fill, or an algorithm of that they have added.

### Importing Sample Mazes
This text file depicts a sample maze by representing each cell with a binary combination. Find a sample maze you would like to import. Starting with the top left cell, translate the sample maze in maze.txt by writing a 1, wall is present, or 0, wall is not present, for the left wall and then the top wall. Each cell should be represented by 2 digits in the text file.
*NOTE: The left digit MUST represent the left wall and the right digit MUST represent the top wall.
To accomodate for the far bottom walls and far right column walls, the Maze default constructor sets them for you. 

### Example


`+---+---+---+`

`|       |   |`

`+   +---+   +`

`|   |   |   |`

`+   +   +   +`

`|       |   |`

`+---+---+---+`


Starting with the top left cell, there is a left wall and top wall present. So in maze.txt my first cell would be written 11.
The next cell to the right has no left wall (0) but it does have a top wall(1). So it would be written as 01. Following this pattern for each cell, the following sample maze would be translated to:

`11 01 11`

`10 11 10`

`10 00 10`

----------------------------------------
### Important Notes

- Your sample maze must be 16 x 16 cells
- Remember to have maze.txt in the same directory as the other files ;)
- For each 2 digit combination in maze.txt, the left digit is for the left wall; right digit, top wall





