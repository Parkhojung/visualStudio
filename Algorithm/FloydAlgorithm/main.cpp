#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <iomanip>

#define INFINITE 10000

void floyd(vector<vector<int>> W, vector<vector<int>>& D, vector<vector<int>>& P, int N);
void matPrn(vector<vector<int>> A, char* matName);
int minimum(int a, int b);
void path(vector<vector<int>> P, int q, int r);
int main() {

	fstream fin("input.txt");
	vector<vector<int>> D;
	vector<vector<int>> P;
	vector<vector<int>> W;
	int N , i , j , k;

	fin >> N;

	W.assign(N, vector<int>(N, 0));// ��� ũ�⿡ �´� W,D,P ����
	D.assign(N, vector<int>(N, 0)); 
	P.assign(N, vector<int>(N, 0)); // ���� ���� �ϵ��� 0�� �ε��� �̻��, 1-N �� �ε��� ���
	

	for (i = 0; i < N; i++) {		// �ʱ� �Է°� ����
		for (j = 0; j < N; j++) {
			fin >> W[i][j];
		}
	}

	floyd(W, D, P, N);
	
	matPrn(D,"D");
	matPrn(P,"P");
	
	cout << "path :";
	path(P, 5-1, 3-1); // ���� ��� �ε����� 0���� �����ϹǷ�.
	cout << endl;
	return 0;
}
void floyd(vector<vector<int>> W, vector<vector<int>>& D, vector<vector<int>>& P, int N) {
	int i, j, k;
	
	D = W;					// �Է� �迭�� D�� ����
	for (k = 0; k < N; k++) { // floyd �˰��� 
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k + 1;				// P ��Ŀ��� 1���� N���� �����Ͽ� ���� ������ ��.
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}
void matPrn(vector<vector<int>> A, char* matName) {
	
	int fontWidth = 10;   // 10 �̻��� ¦���� �ؾ� ��� ����� ���������� ����.
	int blockWidth = fontWidth/2;

	for (int i = 0; i <= A.size()*fontWidth+blockWidth*3; i++) {
		cout <<  "-";
	}
	cout << endl;
	cout << "l" <<setw(fontWidth-8)<< right << matName <<"[i][j] l"  ;
	for (int i = 0; i < A.size() ; i++) {
		cout << setw(fontWidth) <<  i+1;
	}
	cout << setw(blockWidth)<<right<<"l"<< endl;
	for (int i = 0; i <= A.size()*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < A.size(); i++) {
		cout << "l"<<setw(blockWidth) << i << setw(blockWidth)<<"l";

		for (int j = 0; j < A.size(); j++) {
			cout << setw(fontWidth) << A[i][j] ;
		}

		cout << setw(blockWidth)<< right<<"l"<< endl;
	}


	for (int i = 0; i <= A.size()*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}
int minimum(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

void path(vector<vector<int>> P, int q, int r) {
	q = q ;
	r = r ;
	if (P[q][r] != 0) {
		path(P,q, P[q][r]-1); // �ε��� ������ -1
		cout << "v" << (P[q][r]) << " "; 
		path(P, P[q][r]-1, r);
	}
}