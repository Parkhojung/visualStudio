#include<iostream>
#include <vector>
using namespace std;
vector<int> col;


int main() {
	return 0;
}

void preorder(int level) {
	if (promising(level)) {
		if (level == n-1) {
			//cout <<
		}
		else {

			for (int j = 2; j <= n; j++) {
				col[level + 1] = j;
				preorder(level + 1);
			}
		}
	}
}

bool promising(int level) {
	if (!W[col[level]][col[level - 1]])
		return false;
	if (level == n - 1 && W[level][1])
		return false;
	int j = 1;
	while (j < level) {
		if (col[level] == col[j])
			return false;
		j++;
	}
}