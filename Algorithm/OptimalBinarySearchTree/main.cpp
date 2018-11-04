#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <iomanip>

struct nodetype {
	float key;
	nodetype* left;
	nodetype* right;
};

typedef nodetype* node_pointer;

node_pointer tree(int i, int j, vector<vector<int>> R);
void optimalBST(int n, vector<float> p, vector<vector<float>>& A, vector<vector<int>>& R); 
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
//	node_pointer p = tree(1, 4, R);

	cin.get();
	return 0;
}

void optimalBST(int n, vector<float> p, vector<vector<float>>& A, vector<vector<int>>& R) {
	int i, j, k;

	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
	}
	A[n + 1][n] = R[n + 1][n] = 0;

	int minIndex;	 // R�� ���忡 ����� ���� ����
	double min,pSum;	 // �˰��� ���� ���
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout <<  setw(7)<<A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << setw(7)<<R[i][j] << " ";
		}
		cout << endl;
	}
}

node_pointer tree(int i, int j , vector<vector<int>> R) {
	int k = R[i][j];
	node_pointer p;
	
	if (k == 0) {
		return NULL;
	}
	else {
		p = new nodetype();
		p->key = k;
		p->left = tree(i, k - 1, R);
		p->right = tree(k + 1, j,R);
		return p;
	}
}