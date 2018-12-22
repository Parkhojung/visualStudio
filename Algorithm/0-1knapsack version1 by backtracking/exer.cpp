#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int W;
int n;
vector<int> pArr;
vector<int> wArr;
vector<string> include;

int best;
vector<string> bestInclude;
int bestLevel;
void fun(int level, int weight, int profit);
bool promising(int level, int weight, int profit);
int main() {
	fstream fin("input.txt");
	fin >> n >> W;
	pArr.assign(n + 1, 0);
	wArr.assign(n + 1, 0);
	include.assign(n + 1, " ");
	bestInclude.assign(n + 1, " ");

	for (int i = 1; i <= n; i++) {
		fin >> pArr[i];
	}
	for (int i = 1; i <= n; i++) {
		fin >> wArr[i];
	}

	fun(0, 0, 0);

	/*for (auto item : include) {
	cout << item;
	}*/
	return 0;
}

void fun(int level, int weight, int profit) {

	 
	if (profit > best && weight <=W) {
		best = profit;
		bestInclude = include;
	}

	if (promising(level, weight, profit))
		include[level + 1] = "yes";
		fun(level + 1, weight + wArr[level + 1], profit + pArr[level + 1]);
		include[level + 1] = "no";
		fun(level + 1, weight, profit);


}

bool promising(int level, int weight, int profit) {
	 
	if (weight >= W)
		return false;

	float bound = profit;
	int j = level + 1;
	while (j <= n && weight + wArr[j] <= W) {
		weight += wArr[j];
		bound += pArr[j];
		j++;
	}

	if (j <= n)
		bound += (W - weight)*pArr[j] / wArr[j];

	return bound > best;


}