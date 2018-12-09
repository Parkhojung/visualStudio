#include <iostream>

void fun(int level, int weight, int total) {

	if (promising(weight, total)) {
		if (weight == W) {
			cout col;
		}
		else {
			col[level + 1] = "yes";
			fun(level + 1, weight + w[level + 1], total - w[level + 1]);
			col[level + 1] = "no";
			fun(level + 1, weight, total - w[level + 1]);
		}
	}
}

bool promising(int level, int weight, int total) {
	if (w[level] + weight <= W && (weight == W || weight + total > W) {
		return true;
	}
	else {
		return false;
	}
}