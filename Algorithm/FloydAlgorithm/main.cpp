#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <iomanip>
#include"matPrn.h"
#define INFINITE 10000

void floyd(vector<vector<int>> W, vector<vector<int>>& D, vector<vector<int>>& P,int N);
void path(vector<vector<int>> P, int q, int r);
int main() {

	fstream fin("input.txt");
	vector<vector<int>> D;
	vector<vector<int>> P;
	vector<vector<int>> W;
	int N , i , j , k;

	fin >> N;

	W.assign(N, vector<int>(N, 0));// 행렬 크기에 맞는 W,D,P 선언
	D.assign(N, vector<int>(N, 0)); 
	P.assign(N, vector<int>(N, 0)); // 보기 좋게 하도록 0번 인덱스 미사용, 1-N 의 인덱스 사용
	

	for (i = 0; i < N; i++) {		// 초기 입력값 저장
		for (j = 0; j < N; j++) {
			fin >> W[i][j];
		}
	}

	floyd(W, D, P,N);
	
	matPrn(D,"D");
	matPrn(P,"P");
	
	cout << "path :";
	path(P, 5-1, 3-1); // 실제 행렬 인덱스는 0부터 시작하므로. P에는 [1,n]의 값이 들어있다.
	cout << endl;
	return 0;
}
void floyd(vector<vector<int>> W, vector<vector<int>>& D, vector<vector<int>>& P, int N) {
	int i, j, k;
	
	D = W;					// 입력 배열을 D에 저장
	for (k = 0; k < N; k++) { // floyd 알고리즘 
		
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k + 1;				// P 행렬에는 1부터 N으로 저장하여 보기 좋도록 함.
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}
void path(vector<vector<int>> P, int q, int r) {
	q = q ;
	r = r ;
	if (P[q][r] != 0) {
		path(P,q, P[q][r]-1); // 값참조시 -1  이유: [1,n]을 [0,n-1]로 바꿔 행렬 인덱스 접근
		cout << "v" << (P[q][r]) << " "; 
		path(P, P[q][r]-1, r);
	}
}