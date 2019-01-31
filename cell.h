#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		bool t, d, l, r;
		bool found;
		int weight;
		Cell();
		Cell(bool, bool, bool, bool, int);
};

#endif