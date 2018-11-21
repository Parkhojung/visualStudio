#include <iostream>
#include <vector>
using namespace std;

int fun(int);
int min(int, int, int = 10000);
int main() {
	int n;
	cin >> n;
	int res = fun(n);
	cout << res;

	return 0;
}

int fun(int n) {

	if (n == 1) {
		return 0;
	}

	int cnt = 0;
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	int i = 4;
	while (i <= n){
		int n3 = i/3;
		int n2 = i /2;
		if ((i % 3 == 0) && (i % 2 == 0)) {
			arr.push_back(min(arr[n3], arr[n2], arr[i - 1]) + 1);
		}
		else if ((i % 3 == 0) && (i % 2 != 0)) {
			arr.push_back( min(arr[n3], arr[i - 1]) + 1);
		}

		else if ((i % 3) != 0 && i % 2 == 0) {

			arr.push_back( min(arr[n2], arr[i - 1]) + 1);
		}
		else {
			arr.push_back( arr[i - 1] + 1);
		}
		i ++;
	}
	return arr[n];

}
int min(int a, int b, int  c) {
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	else
		return c;
}