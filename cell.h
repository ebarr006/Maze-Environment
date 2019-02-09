#ifndef CELL_H
#define CELL_H

struct Cell {
	bool t;
	bool d;
	bool l;
	bool r;
	bool found;
	int dist;
	Cell() {
		t = d = l = r = found = false;
		dist = 0;
	};
};

#endif