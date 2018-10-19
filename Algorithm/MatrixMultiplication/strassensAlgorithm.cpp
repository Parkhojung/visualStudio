#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void strassen(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &C); // strassen 함수
void matPrn(vector<vector<int>> A); // 행렬 출력 함수
int max(int a, int b); // 비교하여 큰 값 리턴하는 함수

vector<vector<int>> operator+(vector<vector<int>> A, vector<vector<int>> B) { // 행렬 덧셈 연산자 
	int i, j;
	vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < A.size(); j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}
vector<vector<int>> operator-(vector<vector<int>> A, vector<vector<int>> B) { // 행렬 뺄셈 연산자
	int i, j;
	vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
	for (i = 0; i < A.size(); i++) {
		for (j = 0; j < A.size(); j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}
vector<vector<int>> operator*(vector<vector<int>> A, vector<vector<int>> B) { //행렬 곱셈 연산자
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

	vector<vector<int>> A,B,C;

	int i, j, N;
	int Arow,Acol,Brow,Bcol;
	fstream fin("input2.txt"); // 파일 입력
	fin >> Arow; 
	fin >> Acol;
	fin >> Brow;
	fin >> Bcol;

	N = max(Arow, Acol);

	A.assign(N, vector<int>(N, 0));
	B.assign(N, vector<int>(N, 0));
	C.assign(N, vector<int>(N, 0));

	
	for (i = 0; i < Arow; i++) {
		for (j = 0; j < Acol; j++) {
			fin >> A[i][j];
		}
	}
	for (i = 0; i < Brow; i++) {
		for (j = 0; j < Bcol; j++) {
			fin >> B[i][j];
		}
	}
	
	strassen(N, A, B, C); // 함수 호출
	matPrn(C); // 프로그램 수행 결과 출력

	return 0;
}

void strassen(int n, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &C) {
	int i, j;

	if (n <= 2) 
	{
		C = A*B;
		return;
	}
	else
	{
		vector<vector<int>> A11, A12, A21, A22, B11,B12,B21,B22 ; // 알고리즘 수행을 위한 행렬 선언
		vector<vector<int>> M1,M2,M3,M4,M5,M6,M7,T1,T2,T3,T4;

		A11.assign(n / 2, vector<int>(n / 2, 0)); // n/2사이즈 행렬로 설정
		A12.assign(n / 2, vector<int>(n / 2, 0));
		A21.assign(n / 2, vector<int>(n / 2, 0));
		A22.assign(n / 2, vector<int>(n / 2, 0));
		B11.assign(n / 2, vector<int>(n / 2, 0));
		B12.assign(n / 2, vector<int>(n / 2, 0));
		B21.assign(n / 2, vector<int>(n / 2, 0));
		B22.assign(n / 2, vector<int>(n / 2, 0));

		M1.assign(n / 2, vector<int>(n / 2, 0));
		M2.assign(n / 2, vector<int>(n / 2, 0));
		M3.assign(n / 2, vector<int>(n / 2, 0));
		M4.assign(n / 2, vector<int>(n / 2, 0));
		M5.assign(n / 2, vector<int>(n / 2, 0));
		M6.assign(n / 2, vector<int>(n / 2, 0));
		M7.assign(n / 2, vector<int>(n / 2, 0));

		T1.assign(n / 2, vector<int>(n / 2, 0));
		T2.assign(n / 2, vector<int>(n / 2, 0));
		T3.assign(n / 2, vector<int>(n / 2, 0));
		T4.assign(n / 2, vector<int>(n / 2, 0));

		for (i = 0; i < n / 2; i++) { //A11,B11 값 설정
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
	
		T1 = M1 + M4 - M5 + M7; // C의 네 부분 계산 
		T2=  M3 + M5;
		T3=  M2 + M4;
		T4=  M1 - M2 + M3+ M6;

		for (i = 0; i < n/2; i++) { // C 계산
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
	}
}
void matPrn(vector<vector<int>> A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			cout << setw(5) << A[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl;
}
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}