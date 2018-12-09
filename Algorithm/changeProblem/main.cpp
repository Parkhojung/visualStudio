#include <iostream>
using namespace std;
#include <vector>
#include "main.h"
int main() {

	int N;
	vector<int> solutionSet;
	vector<int> coinSet({ 10,50,100,500 });
	
	cout << "N>>";	cin >> N;

	bool solveFlag = change(N, coinSet, solutionSet);
	if (solveFlag) {
		cout << " solutionSet : ";
		for (auto item : solutionSet) {
			cout << item << " ";
		}
	}
	else {
		cout << "not solved";
	}

	return 0;
}

bool change(int N, vector<int> coinSet, vector<int> &solutonSet) {
	int bigCoin;
	int curAmt;
	int sum;
	bool solveFlag;

	solveFlag = false;
	curAmt = N;
	while (!solveFlag && coinSet.size() >= 1) {
		bigCoin = coinSet.back();

		if (curAmt >= bigCoin) {
			solutonSet.push_back(bigCoin);
			curAmt -= bigCoin;
		}
		else {
			coinSet.pop_back();
		}

		sum = sumVector(solutonSet);
		if (sum == N) {
			solveFlag = true;
		}
	}

	return solveFlag;
}
int sumVector(vector<int> v) {
	int sum = 0;
	for (auto item : v) {
		sum += item;
	}
	return sum;
}