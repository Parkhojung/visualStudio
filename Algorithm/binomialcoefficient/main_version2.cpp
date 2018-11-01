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

int bin(int n, int k) {

	
	vector<int> arr(n + 1, 0);
	vector<int> temp(n+1 , 0);

	arr[0] = 1;
	temp[0] = 1;
	int j;
	int i;
	int row, col;

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