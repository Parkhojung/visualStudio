#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <iomanip>
int n;
int W;
vector<int> vArr;
vector<int> wArr;
vector<vector<int>> P;

void knapsack();
int max(int a, int b);
int main() {


	fstream fin("input.txt");

	fin >> n >> W;
	vArr.assign(n + 1,0);
	wArr.assign(n + 1, 0);
	P.assign(n + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= n; i++) {
		fin >> vArr[i];
	}
	for (int i = 1; i <= n; i++) {
		fin >> wArr[i];
	}

	knapsack();

	for (auto row : P) {
		for (auto col : row) {
			cout <<  setw(3) <<col << " ";
		}
		cout << endl;
	}

	return 0;
}

void knapsack() {
	
	for (int i = 1; i <= W; i++) {
		if (wArr[1] > i)
			P[1][i] = 0;
		else
			P[1][i] = vArr[1];;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= W; j++) {
			if( (wArr[i] <= j) ) {
				P[i][j] = max(P[i - 1][j], vArr[i] + P[i - 1][j - wArr[i]]);
			}
			else
				P[i][j] = P[i - 1][j];
		}
	}

}
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}