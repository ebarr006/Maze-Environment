#ifndef CELL_H
#define CELL_H

struct Cell {
	bool t;
	bool d;
	bool l;
	bool r;
	bool found;
	int weight;
	Cell() {
		t = d = l = r = found = false;
		weight = 2;
	};
};

#endif