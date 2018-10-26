#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include "matPrn.h"

int main() {

	int i, j, k ,d;
	int N, min , minIndex;
	vector<vector<int>>M, P;
	vector<int> D;

	fstream fin("input.txt");

	fin >> N;
	D.assign(N+1,0);
	M.assign(N+1, vector<int>(N+1, 10000000));
	P.assign(N+1, vector<int>(N+1, 0));
	
	for (i = 0; i <= N; i++) {
		M[i][i] = 0;
	}
	for (i = 0; i <= N; i++) { // N+1개의 숫자 입력
		fin>> D[i];
	}


	minIndex = 0;
	for (d = 1; d <= N-1; d++) {
		for (i = 1; i <= N - d; i++) {
			j = i + d;		

			for (k = i; k <= j-1 ; k++) {
				if (M[i][j] > M[i][k] + M[k + 1][j] + D[i - 1] * D[k] * D[j]) {
					M[i][j] = M[i][k] + M[k + 1][j] + D[i - 1] * D[k] * D[j];
					minIndex = k;
				}
			}
			P[i][j] = minIndex;
		}
	}

	matPrn(M, "M");
	matPrn(P, "P");
	return 0;
}