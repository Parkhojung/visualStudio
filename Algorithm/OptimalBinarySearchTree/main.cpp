#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "matPrn.h"
using namespace std;

void optimalBST(int N, vector<float> p, vector<vector<float>>& A, vector<vector<int>>& R); 
int main() {
	int N;
	fstream fin("input2.txt");
	fin >> N;

	vector<float> p; // Ȯ���� ������ ���͹迭 ����
	vector<vector<float>> A;	//��� Ž�� �ð��� ������ 2���� �迭 A����
	vector<vector<int>> R;		//Ʈ�� ������ ���� 2���� �迭 R����

	p.assign(N+1, 0);  // 1~n�� �ε��� ����� ���� N+1 ũ�� ����
	A.assign(N + 2, vector<float>(N + 2, 0)); // ���� 1~N+1 ���� 0~N�� ����ϹǷ� (N+2) x (N+2) ��� ����
	R.assign(N + 2, vector<int>(N + 2, 0));

	for (int i = 1; i <= N; i++) {	//Ȯ���� �Է¹ޱ�
		fin >> p[i]; 
	}

	optimalBST(N, p, A, R);

	matPrn<float>(A, "A", 1, N + 1, 0, N);
	matPrn<int>(R, "R", 1, N + 1, 0, N);
	cin.get();
	return 0;
}

void optimalBST(int N, vector<float> p, vector<vector<float>>& A, vector<vector<int>>& R) {
	int d, i, j, k;
	int minIndex;	 // R�� ���忡 ����� ���� ����
	double min, pSum;	 // �˰��� ���� ���

	for (i = 1; i <= N; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
	}
	A[N + 1][N] = R[N + 1][N] = 0;

	for (d = 1; d <= N - 1; d++) {
		for ( i = 1; i <= N - d; i++) {
			j = i + d;
			min = 100000; pSum=0;	 //�ʱ�ȭ
			for (k = i; k <= j; k++) {
				pSum += p[k];	// pi���� pk���� ���ϱ� ���� ����
				if (min > A[i][k - 1] + A[k + 1][j]) {  // �� ���� ��쿡 min �� ������Ʈ
					min = A[i][k - 1] + A[k + 1][j];
					minIndex = k;	// ���� �۾��� �� �ε��� ���
				}
			}
			A[i][j] = min + pSum; // ���� ���� A[i][k-1]+A[k+1][j]�� [i<=k<=j]Sum(pi) ���� 
			R[i][j] = minIndex;		// �ּڰ��� �� ��Ʈ�� �Ǵ� k ����
		}
	}	
}