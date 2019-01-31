#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		int weight;
		bool t, d, l, r;
		bool found;
		Cell();
		Cell(bool, bool, bool, bool);
};

#endif