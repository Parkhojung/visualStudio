#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <cmath>
#include <time.h>
vector<int> col;
vector<int> promChildSet;
int n = 10;
int cnt = 0;

int monteCarlo();
bool promising(int row);
void preOrder(int row);
void prnCol();
int myRandom(vector<int> &v);
int main() {

	srand((unsigned)time(NULL));
	col.assign(n + 1, 0);
//	preOrder(0);

	int res = 0; int monteCnt = 1000;
	for (int i = 1; i <= monteCnt; i++) {
		res += monteCarlo();
	}
	cout << cnt << endl << res/monteCnt << endl;
	return 0;
}
int monteCarlo() {
	int m = 1;
	int mprod = 1;
	int numNodes = 1;
	int level = 1;
	int v;

	while (m != 0 && level != n) {
		mprod = mprod*m;
		numNodes += mprod*n;

		m = 0;	promChildSet.clear();
		
		for (int j = 1; j <= n; j++) {
			col[level] = j;
			if (promising(level)) {
				m++;
				promChildSet.push_back(j);
			}
		}
		if (m != 0) {
			v = rand()%m;
			col[level] = v;
		}

		level++;
	}

	return numNodes;
}
int myRandom(vector<int> &v) { // 0~n-1ÀÇ ÀÎµ¦½º ¾²´Â ¹è¿­ ¼¯±â
	int randomCnt = 100;
	int j, k, temp;
	for (int i = 1; i <= randomCnt; i++) {
		j = rand() % v.size();
		k = rand() % v.size();

		if (j != k) {
			temp = v[j];
			v[j] = v[k];
			v[k] = temp;
		}
	}
	return v[v.size()-1];
}

void preOrder(int row) {
	cnt++;


	if (promising(row)) {
		if (row == n) {
			prnCol();
		}
		else {
			for (int j = 1; j <= n; j++) {
				col[row + 1] = j;;
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
		cout << item << " ";
	}
	cout << endl;
}