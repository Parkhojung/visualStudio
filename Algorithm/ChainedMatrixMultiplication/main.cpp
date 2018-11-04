#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "matPrn.h"

void chainedMatrixMultiplication(int N, vector<int> &D, vector<vector<int>> &M, vector<vector<int>> &P);
void order(int i, int j, const vector<vector<int>> P);

int main() {

	int i, j, k ,d;
	int N, min , minIndex;
	vector<vector<int>>M, P;
	vector<int> D;

	fstream fin("input.txt");

	fin >> N;
	D.assign(N+1,0);
	M.assign(N+1, vector<int>(N+1, 0));
	P.assign(N+1, vector<int>(N+1, 0));
	
	for (i = 0; i <= N; i++) {
		M[i][i] = 0;
	}
	for (i = 0; i <= N; i++) { // N+1개의 숫자 입력
		fin>> D[i];
	}

	chainedMatrixMultiplication(N, D, M, P);
	

	matPrn(M, "M");
	matPrn(P, "P");
	
	order(1, N,P);

	cout << endl;
	return 0;
}

void chainedMatrixMultiplication(int N, vector<int> &D,vector<vector<int>> &M, vector<vector<int>> &P) {
	int minIndex = 0;
	int i, j, k, d;
	int minData;

	for (d = 1; d <= N - 1; d++) {
		for (i = 1; i <= N - d; i++) {
			j = i + d;
			minData = 10000000;
			for (k = i; k <= j - 1; k++) {
				if (minData > M[i][k] + M[k + 1][j] + D[i - 1] * D[k] * D[j]) {
					minData = M[i][k] + M[k + 1][j] + D[i - 1] * D[k] * D[j];
					minIndex = k;
				}
			}
			M[i][j] = minData;
			P[i][j] = minIndex;
		}
		cout << d << "번째" << endl;
		matPrn(M, "M");
	}

}

void order(int i, int j, const vector<vector<int>> P) {
	int k = P[i][j];
	if (k == 0) {
		cout << "A" << i;
	}
	else {
		cout << "(";
		order(i, k, P);
		order(k+ 1,j, P);
		cout << ")";
	}
}