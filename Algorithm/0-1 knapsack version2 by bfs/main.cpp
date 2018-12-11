#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <fstream>


int n;
int best;
int bestLevel;
int W;

vector<int> pArr;
vector<int> wArr;
vector<string> include;
vector<string> bestInclude;
struct node {
	int level;
	int profit;
	int weight;
};
queue<node> Q;
queue<int> IQ;
int bound(node u);

void fun();
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
	fun();

	return 0;
}
void fun() {

	node v = { 0,0 };
	
	Q.push(v);
	
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		node u;
		u.level = v.level + 1;
		u.profit = v.profit + pArr[u.level + 1];
		u.weight = v.weight + wArr[u.level + 1];
		if (u.weight <= W && u.profit > best) {
			best = u.profit;
			bestLevel = u.level;
		}
		if (bound(u) > best) {
			Q.push(u);
		}
		u.profit = v.profit;
		u.weight = v.weight;
		if (bound(u) > best) {
			Q.push(u);
		}

	}

}
int bound(node u) {
	if (u.weight >= W) {
		return 0;
	}
	else {
		int j = u.level + 1;
		float bound = u.profit;
		int weight = u.weight;
		int nextChildWeight = u.weight + wArr[j + 1];

		while (j <= n && weight+wArr[j] <= W) {
			weight += wArr[j];
			bound += pArr[j];
			j++;
		}

		if (j <= n) {
			bound += (W - weight)*pArr[j] / wArr[j];
		}

		return bound;
	}
}