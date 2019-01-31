#include "cell.h"

Cell::Cell() {
	t = d = l = r = found = false;
	weight = 0;
}

Cell::Cell(bool tp, bool dwn, bool lft, bool rht) : t(tp), d(dwn), l(lft), r(rht) {}
