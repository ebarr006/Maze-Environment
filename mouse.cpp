#include "mouse.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

Mouse::Mouse() {
	i = 15;
	j = 0;
	direction = '^';
}

void Mouse::rotate(int dir) {
	if (dir == 0) { direction = UP; }
	if (dir == 1) { direction = RIGHT; }
	if (dir == 2) { direction = DOWN; }
	if (dir == 3) { direction = LEFT; }
}

void Mouse::move(int dir) {
	if (dir == 0) { i--; }
	if (dir == 1) { j++; }
	if (dir == 2) { i++; }
	if (dir == 3) { j--; }
}