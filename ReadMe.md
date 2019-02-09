# Maze-Environment
Written by Emilio Barreiro, IEEE-UCR

### Overview
A terminal maze simulator for displaying Micromouse maze solving algorithms. Sample mazes are imported to the program from maze[#].txt files.
There are currently 4 implemented search strategies: Flood Fill, Left Wall Follow, Right Wall Follow, and Random Search. For the Flood Fill strategy, the initial solving is completed, but the returning to start step is in development. Stay tuned for updates.

### Setup and Run
Clone, compile, and run:
<pre>git clone https://github.com/ebarr006/Maze-Environment.git
make
./start
</pre>

## Run Settings
You can change some of the program's settings using command line arguments. Just add the flag and argument after <pre>start</pre>. To change the delay interval between mouse steps, use <pre>-t</pre> and the time interval (1 = 1 second, 0.5 = half a second). To see all command line argument settings, type <pre>-h</pre>.


### Importing Sample Mazes
maze.txt depicts a sample maze by representing each cell with a binary combination. Find a sample maze you would like to import. Starting with the top left cell, translate the sample maze into maze.txt by writing a 1, wall is present, or 0, wall is not present, for the left wall and then the top wall. Each cell should be represented by 2 digits in the text file.

**NOTE:** The left digit **MUST** represent the left wall and the right digit **MUST** represent the top wall.
To accomodate for the far bottom walls and far right column walls, the Maze default constructor sets them for you.

### Example


<pre>+---+---+---+
|       |   |
+   +---+   +
|   |   |   |
+   +   +   +
|       |   |
+---+---+---+</pre>




Starting with the top left cell, there is a left wall and top wall present. So in maze.txt my first cell would be written 11.
The next cell to the right has no left wall (0) but it *does* have a top wall(1). So it would be written as 01. Following this pattern for each cell, the following sample maze would be translated to:

<pre>11 01 11
10 11 10
10 00 10</pre>

----------------------------------------
### Important Notes

- Your sample maze must be 16 x 16 cells
- Remember to have maze.txt in the same directory as the other files ;)
- For each 2 digit combination in maze.txt, the left digit is for the left wall; right digit, top wall

