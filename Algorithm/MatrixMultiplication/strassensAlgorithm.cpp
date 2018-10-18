#include <iostream>
#include <vector>
using namespace std;
#define ROW 4
#define COL 4
#define THRESHOLD 1
void strassen(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &C);
void matrixmult(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C);
void matrixPrint(vector<vector<int>>);

vector<vector<int>> operator+(vector<vector<int>> A, vector<vector<int>> B) {
	int i, j;
	vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < A.size(); j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
vector<vector<int>> operator-(vector<vector<int>> A, vector<vector<int>> B) {
	int i, j;
	vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < A.size(); j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}
vector<vector<int>> operator*(vector<vector<int>> A, vector<vector<int>> B) {
	int i, j, k;
	vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < A.size(); j++) {
			C[i][j] = 0;
			for (k = 0; k < A.size(); k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return C;
}

int main() {

	vector<vector<int>> A(4,vector<int>(4,1));
	vector<vector<int>> B(4, vector<int>(4, 1));
	vector<vector<int>> C(4,vector<int>(4,1));
	
	/*matrixPrint(A);
	matrixPrint(A);
	matrixPrint(A);
*/
	cout << "A";
	matrixPrint(A);
	cout << " result >>" << endl;
	
	strassen(4, A, B, C);

	matrixPrint(C);
	int	i = 3;

	cin.get();
	return 0;
}

void strassen(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &C) {
	int i, j;
	//cout << "A";
	//matrixPrint(A);

	//cout << "C";
	//matrixPrint(C);

	if (n <= THRESHOLD) {
		if (n < 1)
			return;
		matrixmult(n, A, B, C);
		return;
	}
	else {
		vector<vector<int>> A11(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> A12(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> A21(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> A22(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> B11(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> B12(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> B21(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> B22(n / 2, vector<int>(n / 2, 0));

		vector<vector<int>> M1(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M2(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M3(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M4(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M5(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M6(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> M7(n / 2, vector<int>(n / 2, 0));

		vector<vector<int>> T1(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> T2(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> T3(n / 2, vector<int>(n / 2, 0));
		vector<vector<int>> T4(n / 2, vector<int>(n / 2, 0));

		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				B11[i][j] = B[i][j];
			}
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
			for (j = n / 2; j < n; j++) {
				A22[i % (n / 2)][j % (n / 2)] = A[i][j];
				B22[i % (n / 2)][j % (n / 2)] = B[i][j];
			}
		}


		strassen(n / 2, A11 + A22, B11 + B22, M1);
		strassen(n / 2 ,A21 + A22, B11, M2);
		strassen(n / 2, A11 , B12 -  B22, M3);
		strassen(n / 2, A22 , B21 - B11, M4);
		strassen(n / 2, A11 + A12, B22, M5);
		strassen(n / 2, A21 - A11, B11+ B12, M6);
		strassen(n / 2, A12 - A22, B21 + B22, M7);
	
		cout << "M1";
		matrixPrint(M1);
		T1 = M1 + M4 - M5 + M7;
		T2=  M3 + M5;
		T3=  M2 + M4;
		T4=  M1 - M2 + M3+ M6;
		//cout << "T";
		//matrixPrint(T1);


		for (i = 0; i < n/2; i++) {
			for (j = 0; j < n / 2; j++) {
				C[i][j] = T1[i][j];
			}
			for (j = n / 2; j < n; j++) {
				C[i][j] = T2[i][j%(n/2)];
			}
		}
		for (i = n/2; i < n; i++) {
			for (j = 0; j < n / 2; j++) {
				C[i][j] = T3[i%(n/2)][j];
			}
			for (j = n / 2; j < n; j++) {
				C[i][j] = T4[i%(n/2)][j % (n / 2)];
			}
		}

	//	matrixPrint(C);
	}
}

void matrixmult(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C) {
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

void matrixPrint(vector<vector<int>> A) {
	cout << "Matrix >>" << endl;
	//vector<int>::iterator itor;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl;
}