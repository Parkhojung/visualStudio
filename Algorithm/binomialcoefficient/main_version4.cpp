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

// 반만쓰는 버전 + 1차원 어레이 쓰는 버전 
// 1차원 어레이 쓸 떄 로직에 행렬만 반쓰는 것 추가
// k = min(k, n-k)를 통해 인덱스 접근을 중간을 기준으로 왼쪽만 가능하도록함
int bin(int n, int k) {


	vector<int> arr((n + 1)/2+1, 0);
	vector<int> temp((n + 1)/2+1, 0);

	arr[0] = 1;
	temp[0] = 1;
	int i,j;

	k = min(k, n - k);

	for (i = 0; i <= n; i++) {
		temp = arr;

		for (j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i) {
				arr[j] = 1;
			}
			else {
				arr[j] = temp[j - 1] + temp[j];
			}
		}
	}
	return arr[k];
}

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}