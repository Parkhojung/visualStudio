#include <iostream>
#include <set>
#include <vector>
using namespace std;
#include <fstream>
#include <algorithm>

int fun(vector<int> arr, set<int> s);
int main() {
	fstream fin("input.txt");
	int n;	//# of test case 
	int m; // amount of test case 
	vector<int> arr;
	set<int> s;
	fin >> n;
	//cin >> n;
	for (int i = 0; i < n; i++) {
		fin >> m;
		// cin >> m;
		arr.clear();
		arr.assign(m, 0);
		s.clear();
		for (int j = 0; j < m; j++) {
			fin >> arr[j];
		}
		cout << "#" << i+1 <<  " " <<fun(arr, s) << endl;
	}
	

	return 0;
}

int fun(vector<int> arr , set<int> s) {

}