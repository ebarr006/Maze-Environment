#ifndef MOUSE_H
#define MOUSE_H

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

class Mouse {

	public:
		char direction;
		int i;
		int j;
		
		Mouse();
		void rotate(int dir);
		void move(int dir);
};

#endif