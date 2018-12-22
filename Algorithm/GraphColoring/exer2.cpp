#include <iostream>
using namespace std;
#include <vector>
vector<vector<int>>W;
vector<int> col;
int n;
int m;
int main() {


	return 0;
}

void preorder(int level) {
	
	if (promising(level)) {
		if (level == n) {
			//cout << col;
		}
		else {
			for (int i = 1; i <= m; i++) {
				col[level + 1] = m;
				preorder(level + 1);
			}
		}
	}

}

bool promising(int level) {

	int k = 1;

	while (k < level) {
		if (W[k][level] && col[k] == col[level])
			return false;
		k++;
	}

	return true;
}