#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <cmath>
vector<int> col;
int n = 10;
int cnt=0;

bool promising(int row);
void preOrder(int row);
void prnCol();
int main() {

	col.assign(n + 1, 0);
	preOrder(0);


	cout << cnt;
	return 0;
}

void preOrder(int row) {
	cnt++;


	if (promising(row)) {
		
		if (row == n) {
//			prnCol();
		}
		else {
			for (int j = 1; j <= n; j++) {
				col[row + 1] = j;
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
void prnCol() {

	for (auto item : col) {
		cout << item <<" ";
	}
	cout << endl;
}