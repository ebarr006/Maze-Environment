#ifndef CELL_H
#define CELL_H

class Cell {
	private:
		char sym;
		int dist;

	public:
		bool t, d, l, r;
		
		Cell();
		Cell(bool, bool, bool, bool);
		bool top();
		bool down();
		bool left();
		bool right();
		int getDist();
		void setFacing(char);
};

#endif