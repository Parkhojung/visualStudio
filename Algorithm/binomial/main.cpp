#include <iostream>
using namespace std;
#include <iomanip>
#include <vector>
int bin(int n, int k);
int min(int, int);

int main() {

	int n, k;
	cout << "n : "; cin >> n;
	cout << "k : "; cin >> k;
	int res = bin(n, k);

	cout << n << "C" << k << ":" << res;
	return 0;
}

// 행렬을 반만 쓰는 버전 n+1 x (n+1/2 +1) 
// 5c3 일 경우 6 x 4
// 8c4 일 경우 9 x 5 
// k = min(k, n-k)를 통해 인덱스 접근을 중간을 기준으로 왼쪽만 가능하도록함
int bin(int n, int k) {


	vector<vector<int>> arr(n + 1, vector<int>((n + 1) / 2 + 1, 0));
	k = min(k, n - k);

	arr[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}



	//-------------------------------------------------------------
	//	출력
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << setw(5) << arr[i][j] << "  ";
		}
		cout << endl;
	}

	return arr[n][k];
}

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}