#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <algorithm>
int W;
int n;
vector<vector<int>> P;
vector<int> w;
vector<int> p;

int fun(int i, int j);
int main() {

	fstream fin("input.txt");
	fin >> n >> W;
	w.assign(n + 1, 0);
	p.assign(n + 1, 0);
	P.assign(n + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= n; i++) {
		fin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		fin >> w[i];
	}

	
	fun(n, W);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			cout << P[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}

int fun(int i, int j) {

	if (i == 1) {
		if(w[i] <= j) {
			return p[i];
		}
		else {
			return 0;
		}
	}

	if (w[i] <= j) {
		return P[i][j] = max(fun(i-1,j), fun(i-1,j-w[i])+p[i]);
	}
	else {
		return P[i][j] = fun(i-1,j);
	}
}
