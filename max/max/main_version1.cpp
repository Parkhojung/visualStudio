#include <iostream>
using namespace std;
#include <fstream>

int fun(int max, int n);
int main() {
	int max, n;


	fstream fin("input.txt");
	fin >> max >> n;

	int res = fun(max, n);
	cout << res << endl ;

	return 0;
}

int fun(int max, int n) {
	int cnt = 0;

	int one, num;
	for (int i = 1; i <= max; i++) {
		num = i;
		while (num > 0) {
			one = num % 10;
			if (one == n) {
				cnt++;
			}
			num = num / 10;
		}

	}


	return cnt;
}