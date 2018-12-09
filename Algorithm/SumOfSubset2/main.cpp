#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
typedef int index;
vector<string> include;
vector<int> w;
int W;

void sum_of_subsets(index i, int weight, int total);
bool promising(index i, int weight, int total);
int main() {

	int N;
	fstream fin("input2.txt");
	fin >> N >> W;
	w.assign(N + 1, 0);
	include.assign(N + 1, "");
	int total = 0 ;
	for (int i = 1; i <= N; i++) {
		fin >> w[i];
		total += w[i];
	}
	sum_of_subsets(0,0,total);
	return 0;
}

void sum_of_subsets(index level, int weight, int total) {
	if (promising(level, weight, total)) {
		if (weight == W) {
			for (int k = 1; k <= level; k++) {
				cout << include[k] << " ";
			}
			cout << endl;
		}
		else {
			include[level + 1] = "yes";
			sum_of_subsets(level + 1, weight + w[level + 1], total - w[level + 1]);
			include[level + 1] = "no";
			sum_of_subsets(level + 1, weight, total - w[level + 1]);
		}
	}
}

bool promising(index level, int weight, int total) {
	return (weight + total >= W) && (weight == W || weight + w[level + 1] <= W);
}