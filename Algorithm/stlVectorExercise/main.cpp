#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct person {
	int num1;
	int num2;
};
bool comparePerson(int num1, int num2) {
	return num1 > num2;
}

int main() {

	vector<int> a;
	a.assign(10, 1);


	a[0] = 3; 
	a[1] = 2;
	a[2] = 1;
	a[3] = 0; 

	for (auto item : a) {
		cout << item << " ";
	}

	cout << endl;
	sort(a.begin(),a.end());

	for (auto item : a) {
		cout << item << " ";
	}

//	vector<vector<int>> b;
//	b.assign(10, vector<int>(10, 1));
//
//	b[0][0] ~ b[9][9]
//
//	cout << a.size() << endl;
//
//	a.push_back(1);
//	cout << a[0] << " " <<a.size() << endl;
//
	
	return 0;
}