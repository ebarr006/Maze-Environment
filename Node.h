#ifndef NODE_H
#define NODE_H

struct Node {
	int i;
	int j;
	int dis;
	bool branch;
	Node() {
		i = 999;
		j = 999;
		dis = 999;
		branch = false;
	}
	Node(int ii, int jj, int d) {
		i = ii;
		j = jj;
		dis = d;
	}
	bool operator==(const Node rhs) {
		return (this->dis == rhs.dis);
		// return ((this->y_i == rhs.y_i) && (this->x_j == rhs.x_j) && (this->dis == rhs.dis));
	}
	
	bool operator!=(const Node rhs) {
		return (this->dis != rhs.dis);
	}
};

#endif