#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
vector<int> col;
int n;
int main() {


}

void preorder(int level) {

	if (promising(level)) {
		if (level == n )
			cout << col[0];
		else {
			for (int j = 1; j <= n; j++) {
				col[level + 1] = j;
				preorder(level + 1);
			}
		}
	}
}

bool promising(int level) {
	int i = 1;
	while (i < level) {
		if (col[i] == col[level])  
			return false;
		
		if (abs(col[i] - col[level]) == abs(i - level))
			return false;
		i++;
	}
	return true;
}