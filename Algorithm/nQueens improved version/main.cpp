#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <cmath>
vector<int> col;
int n = 4;
int cnt = 0;

bool promising(int row);
void preOrder(int row);
void prnCol(int);
int main() {

	col.assign(n + 2, 0);
	preOrder(0);


	cout << "노드 방문횟수: "<< cnt << endl;
	return 0;
}

void preOrder(int row) {
	cnt++;

	if(row ==n)
		prnCol(row );
	else {
		for (int j = 1; j <= n; j++) {
			col[row + 1] = j;
			if (promising(row + 1)) {
				preOrder(row + 1);

			}
		}
	}
}
bool promising(int row) {
	int k = 1;
	bool resFlag = true;

	while (k < row && resFlag) {
		if (col[k] == col[row] || abs(col[k] - col[row]) == abs(k - row)) {
			resFlag = false;
		}
		k++;
	}
	return resFlag;
}
void prnCol(int row) {

	for (int i = 1; i <= row; i++) {
		cout << col[i] << " ";
	}
	cout << endl;
}