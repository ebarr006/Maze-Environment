#include "cell.h"

Cell::Cell() {
	t = d = l = r = false;
	sym = '^';
	dist = 99;
}

Cell::Cell(bool tp, bool dwn, bool lft, bool rht) : t(tp), d(dwn), l(lft), r(rht) {}

bool Cell::top() {
	return t;
}

bool Cell::down() {
	return d;
}

bool Cell::left() {
	return l;
}

bool Cell::right() {
	return r;
}

int Cell::getDist() {
	return dist;
}

void Cell::setFacing(char x) {
	sym = x;
}