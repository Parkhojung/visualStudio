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

vector<int> monteCarlo();
bool promising(int row, vector<int> );

int myRandom(vector<int> &v);
int main() {

	srand((unsigned)time(NULL));

	col.assign(n + 1, 0);
	int monteCnt = 100;
	vector<int> res;
	vector<int> sumArr;
	sumArr.assign(n + 1, 0);
	for (int i = 1; i <= monteCnt; i++) {
		res = monteCarlo();
		for (int j = 0; j <= n; j++) {
			sumArr[j] += res[j];
		}
	}

	cout << cnt << endl;
	for (int i = 0; i <= n; i++) {
		cout << sumArr[i]/monteCnt  << " ";
	}
	int sum = 0;
	for (auto item : sumArr) {
		sum += item;
	}
	cout << "sum:" << sum/monteCnt;
	return 0;
}
vector<int> monteCarlo() {

	int m = 1;
	int mprod = 1;
	int numNodes = 1;
	int level = 0;
	int v;
	vector<int> numNodesArr;
	numNodesArr.assign(n + 1, 0);


	while (m != 0 && level != n) {
		mprod = mprod*m;
		numNodes += mprod*n;
		numNodesArr[level] = mprod*n;

		m = 0;	level++; promChildSet.clear();

		for (int j = 1; j <= n; j++) {
			col[level] = j;
			if (promising(level , col)) {
				m++;
				promChildSet.push_back(j);
			}
		}
		if (m != 0) {
			v = rand() % m;
			col[level] = v;
		}
	}

	return numNodesArr;
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
	return v[v.size() - 1];
}

bool promising(int row , vector<int> col) {
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
