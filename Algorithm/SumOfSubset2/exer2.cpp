#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
int W = 21;
int n = 5;
vector<int> w{ 5,6,10,11,16 };
vector<string> s;
int main() {


	return 0;
}

void preorder(int level, int weight, int total) {

	
	if (promising(level, weight, total)) {
		if (weight == W) {
			cout << s;
		}
		else {
			s[level + 1] = "yes";
			preorder(level + 1, weight + w[level + 1], total - w[level+1]);
			s[level + 1] = "no";
			preorder(level + 1, weight, total);
		}
	}
}
bool promising(int level, int weight, int total) {
	if (weight > W) {
		return false;
	}
	else {
		if ((weight + total >=  W) && (weight == W || weight + w[level]<= W))
			return true;

	}

}
