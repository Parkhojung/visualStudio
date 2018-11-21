#include <iostream>
using namespace std;
#include <fstream>
#include <vector>

int fun(int max, int n);
int main() {
	int max, n;
	cout << "max>>";
	cin >> max;
	cout << "n>>";
	cin >> n;

	int res = fun(max, n);
	cout << res << endl;

	return 0;
}

int fun(int max, int n) {
	int cnt = 0;
	vector<int> arr;
	arr.assign(max + 1, 0);

	int rByTen,qByTen, num;

	arr[n] = 1;
	cnt = 1;
	for (int i = 10; i <= max; i++) {
		num = i;
		rByTen = num % 10;
		qByTen = num / 10;
		arr[i] = arr[qByTen]+arr[rByTen];
		cnt += arr[i];
	}


	return cnt;
}