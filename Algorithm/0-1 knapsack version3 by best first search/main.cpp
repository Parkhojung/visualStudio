#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <fstream>

int W;
int n;
int bestLevel;
int best;

vector<int> pArr;
vector<int> wArr;
vector<string> include;
vector<string> bestInclude;

struct node {
	int level;
	int profit;
	int weight;
	float bound;
	node() :level(0), profit(0), weight(0), bound(0) {}
};
queue<int> IQ;

struct cmp {
	bool operator()(node a, node b) {
		return a.bound < b.bound;
	}
};
void fun();
int bound(node u);
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
	priority_queue<node, vector<node>, cmp> PQ;
	node v;
	node u;
	v.level=0; v.profit=0; v.weight=0; v.bound=bound(v);
	PQ.push(v);
	while (!PQ.empty()) {
		v = PQ.top(); PQ.pop();

		if (v.bound > best) {
			u.level = v.level + 1;
			u.profit = v.profit + pArr[v.level + 1];
			u.weight = v.weight + wArr[v.level + 1];
			if(u.weight <= W && u.profit > best){
				best = u.profit;
			}

			u.bound = bound(u);
			if (u.bound > best) {
				PQ.push(u);
			}
			
			u.profit = v.profit;
			u.weight = v.weight;
			u.bound = bound(u);
			if (u.bound > best) {
				PQ.push(u);
			}
		}
	}
}
int bound(node u) {

	if (u.weight >= W) {
		return 0;
	}
	else {
		int j = u.level + 1;
		int totweight = u.weight;
		float bound = u.profit;
		while (j <= n && totweight + wArr[j] <= W) {
			totweight = totweight + wArr[j];
			bound = bound + pArr[j];
			j++;
		}

		if (j <= n)
			bound = bound + (W - totweight)*pArr[j] / wArr[j];

		return bound;
	}
	

}