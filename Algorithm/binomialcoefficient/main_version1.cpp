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
	
	vector<vector<int>> arr(n + 1, vector<int>(n+1, 0));

	arr[0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= min(i, k); j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << setw(5) << arr[i][j] << "  ";
		}
		cout << endl;
	}
	vector<vector<int>> temp;
	temp = arr;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			temp[i][j] = 1;
			cout << setw(5) << temp[i][j] << "  ";
		}
		cout << endl;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << setw(5) << arr[i][j] << "  ";
		}
		cout << endl;
	}

	cout << &temp << endl << &arr;

	return arr[n][k];
}

int min(int a, int b) {
	if (a > b) return b;
	else return a;;
}
