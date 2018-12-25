#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <algorithm>
int fun(vector<int> arr);
int main() {
	vector<int> arr;
	arr.assign(1000, 0);

	fstream fin("input.txt");
	int n;
	int m;
	int res;

	fin >> n;
	for (int i = 1; i <= n; i++) {
		fin >> m; 
		for (int j = 0; j < 1000; j++) {
			fin >> arr[j];
		}

		res = fun(arr);
		cout << "#" << i << " " << res << endl;
	}

}

int fun(vector<int> arr) {
	vector<int> cnt;
	cnt.assign(101, 0);
	int j;
	for (int i = 0; i < 1000; i++) {
		j = arr[i];
		cnt[j] += 1;
	}

	int max = 0;
	int maxValue = 0;
	for (int i = 0; i <= 100; i++) {
		if (maxValue <= cnt[i]) {
			maxValue = cnt[i];
			max = i;
		}
	}
	return max;
}