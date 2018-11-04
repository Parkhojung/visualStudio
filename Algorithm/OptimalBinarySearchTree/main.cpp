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

	vector<float> p; // 확률을 저장할 벡터배열 선언
	vector<vector<float>> A;	//평균 탐색 시간을 저장할 2차원 배열 A선언
	vector<vector<int>> R;		//트리 구조를 위한 2차원 배열 R선언

	p.assign(N+1, 0);  // 1~n의 인덱스 사용을 위해 N+1 크기 선언
	A.assign(N + 2, vector<float>(N + 2, 0)); // 행은 1~N+1 열은 0~N을 사용하므로 (N+2) x (N+2) 행렬 선언
	R.assign(N + 2, vector<int>(N + 2, 0));

	for (int i = 1; i <= N; i++) {	//확률값 입력받기
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

	int minIndex;	 // R에 저장에 사용할 변수 선언
	double min,pSum;	 // 알고리즘 계산시 사용
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {
			j = i + d;
			min = 100000; pSum=0;	 //초기화
			for (k = i; k <= j; k++) {

				pSum += p[k];	// pi부터 pk까지 더하기 위해 누적
				if (min > A[i][k - 1] + A[k + 1][j]) {  // 더 좋은 경우에 min 값 업데이트
					min = A[i][k - 1] + A[k + 1][j];
					minIndex = k;	// 가장 작았을 때 인덱스 기록
				}
			}

			A[i][j] = min + pSum; // 제일 좋은 A[i][k-1]+A[k+1][j]와 [i<=k<=j]Sum(pi) 저장 
			R[i][j] = minIndex;		// 최솟값일 때 루트가 되는 k 저장
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