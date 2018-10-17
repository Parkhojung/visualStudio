#include <iostream>
using namespace std;

#define ROW 4
#define COL 4
#define THRESHOLD 1

void strassen(int n, const int A[][n], const int B[][n], int C[][n]);
void matrixmult(int n, const int A[][n], const int B[][n], int C[][n]);
void matrixPrint(int n, const int *A);
int main() {

	int A[ROW][COL] = { { 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 } };
	int B[ROW][COL] = { { 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 },{ 1,1,1,1 } };
	int C[ROW][COL] = { { 0, } };

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}

	cout << " result >>" << endl;
	strassen(ROW, A, B, C);

	//for (int i = 0; i < ROW; i++) {
	//	for (int j = 0; j < COL; j++) {
	//		cout << C[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	

	return 0;
}

void strassen(int n, const int A[ROW][COL], const int B[ROW][COL], int C[ROW][COL]) {
	int i, j;

	if (n <= THRESHOLD) {
		matrixmult(ROW, A, B, C);
	}
	else {
		int **A11 = (int**)malloc(sizeof(int*) * n / 2);
		int **A12 = (int**)malloc(sizeof(int*) * n / 2);
		int **A21 = (int**)malloc(sizeof(int*) * n / 2);
		int **A22 = (int**)malloc(sizeof(int*) * n / 2);

		int **B11 = (int**)malloc(sizeof(int*) * n / 2);
		int **B12 = (int**)malloc(sizeof(int*) * n / 2);
		int **B21 = (int**)malloc(sizeof(int*) * n / 2);
		int **B22 = (int**)malloc(sizeof(int*) * n / 2);

		int **M1 = (int**)malloc(sizeof(int*) * n / 2);
		int **M2 = (int**)malloc(sizeof(int*) * n / 2);
		int **M3 = (int**)malloc(sizeof(int*) * n / 2);
		int **M4 = (int**)malloc(sizeof(int*) * n / 2);
		int **M5 = (int**)malloc(sizeof(int*) * n / 2);
		int **M6 = (int**)malloc(sizeof(int*) * n / 2);
		int **M7 = (int**)malloc(sizeof(int*) * n / 2);

		int **T1 = (int**)malloc(sizeof(int*) * n / 2);
		int **T2 = (int**)malloc(sizeof(int*) * n / 2);


		for (i = 0; i < n / 2; i++) {
			A11[i] = (int*)malloc(sizeof(int) * n / 2);
			A12[i] = (int*)malloc(sizeof(int) * n / 2);
			A21[i] = (int*)malloc(sizeof(int) * n / 2);
			A22[i] = (int*)malloc(sizeof(int) * n / 2);

			B11[i] = (int*)malloc(sizeof(int) * n / 2);
			B12[i] = (int*)malloc(sizeof(int) * n / 2);
			B21[i] = (int*)malloc(sizeof(int) * n / 2);
			B22[i] = (int*)malloc(sizeof(int) * n / 2);

			M1[i] = (int*)malloc(sizeof(int) * n / 2);
			M2[i] = (int*)malloc(sizeof(int) * n / 2);
			M3[i] = (int*)malloc(sizeof(int) * n / 2);
			M4[i] = (int*)malloc(sizeof(int) * n / 2);
			M5[i] = (int*)malloc(sizeof(int) * n / 2);
			M6[i] = (int*)malloc(sizeof(int) * n / 2);
			M7[i] = (int*)malloc(sizeof(int) * n / 2);

			T1[i] = (int*)malloc(sizeof(int) * n / 2);
			T2[i] = (int*)malloc(sizeof(int) * n / 2);

		}

		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				B11[i][j] = B[i][j];
			}
		}
		for (i = 0; i < n / 2; i++) {
			for (j = n / 2; j < n; j++) {
				A12[i][j % (n / 2)] = A[i][j];
				B12[i][j % (n / 2)] = B[i][j];
			}
		}
		for (i = n / 2; i < n; i++) {
			for (j = 0; j < n / 2; j++) {
				A21[i % (n / 2)][j] = A[i][j];
				B21[i % (n / 2)][j] = B[i][j];
			}
		}
		for (i = n / 2; i < n; i++) {
			for (j = n / 2; j < n; j++) {
				A22[i % (n / 2)][j % (n / 2)] = A[i][j];
				B22[i % (n / 2)][j % (n / 2)] = B[i][j];
			}
		}

	/*	cout << " A22>>" << endl;
		for (i = 0; i < n / 2; i++) {
			matrixPrint(n / 2, A22[i]);
			cout << endl;
		}*/

		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				T1[i][j] = A11[i][j] + A22[i][j];
				T2[i][j] = B11[i][j] + B22[i][j];
			}
		}
		strassen(2/n,T1,T2,)
	}
}

void matrixmult(int n, const int A[][n], const int B[][n], int C[ROW][COL]) {
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

void matrixPrint(int n, const int *A) {
	int len= sizeof(A) / sizeof(A[0]);
	for (int i = 0; i <= len; i++) {
		cout << A[i] << " ";
	}
}