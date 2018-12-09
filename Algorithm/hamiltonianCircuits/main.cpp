#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
int n;
vector<vector<int>> W;
vector<int> col;

void tour(int level);
bool promising(int level);
void prnCol();

int main() {

	fstream fin("input.txt");
	fin >> n;
	W.assign(n + 1, vector<int>(n + 1, 0));
	col.assign(n + 1, 0);
	col[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fin >> W[i][j];
		}
	}

	tour(0);

	return 0;
}

void tour(int level) {

	if (promising(level)) {
		if (level == n - 1) {
			prnCol();
		}
		else {
			for (int j = 2; j <= n; j++) {
				col[level + 1] = j;
				tour(level+1);
			}
		}
	}

}
bool promising(int level) {
	bool resFlag;

	if (level == n - 1 && !W[col[0]][col[n-1]]) {
		return false;
	}
	else if (level > 0 && !W[col[level]][col[level - 1]]) {
		return false;
	}
	else {
		resFlag = true;
		int k = 1;
		while (k < level && resFlag) {
			if (col[k] == col[level])
				resFlag = false;
			k++;
		}
		
	}
	return resFlag;
}
void prnCol() {
	for (int i = 1; i <= n - 1; i++) {
		cout << col[i] << " ";
	}
	cout << endl;

}