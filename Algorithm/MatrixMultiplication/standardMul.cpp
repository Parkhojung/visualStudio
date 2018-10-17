#include <iostream>
using namespace std;

#define ROW 4
#define COL 4

void matrixmult(int n, const int A[ROW][COL], const int B[ROW][COL], int C[ROW][COL]);
int main() {

	int A[ROW][COL] = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
	int B[ROW][COL] = { { 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 } };
	int C[ROW][COL] = { {0,} };

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << " result >>" << endl;
	matrixmult(ROW, A, B, C);
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void matrixmult(int n, const int A[ROW][COL], const int B[ROW][COL], int C[ROW][COL]) {
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			C[i][j] = 0;
			for (k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}