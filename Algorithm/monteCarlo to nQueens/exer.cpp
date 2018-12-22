#include <iostream>
using namespace std;
#include <vector>
vector<int> col;
#include <algorithm>
int main() {


}

int monte(int level) {

	int mprod = 1;
	int m = 1;
	int numnodes = 1;
	int n = 4;

	while (promising(level)  && m != 0) {
		mprod *= m;
		numnodes += n*mprod;
		
		m = 0;
		for (int j = 1; j <= n; j++) {
			col[level + 1] = j;
			if (promising(level + 1))
				m += 1;
		}

		
	}

}

bool promising(int level) {

	int j = 1;
	while (j < level) {
		if (col[level] == col[j])
			return false;
		if (abs(col[level] - col[j]) == abs(level - j))
			return false;
		j++;
	}
	return true;
}