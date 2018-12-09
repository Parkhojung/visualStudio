#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
typedef int index;
int n;
int m ;
vector<int> vcolor;
vector<vector<int>> W;

void m_coloring(index level);
bool promising(index level);
int main() {
	
	fstream fin("input2.txt");
	
	fin >> n >> m;
	vcolor.assign(n + 1, 0);
	W.assign(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			fin >> W[i][j];
		}
	}

	m_coloring(0);

	return 0;
}
void m_coloring(index level) {

	if (promising(level)) {
		if (level == n) {
			for (int k = 1; k <= level; k++) {
				cout << vcolor[k] << " ";
			}
			cout << endl;
		}
		else {
			for (int color = 1; color <= m; color++) {
				vcolor[level + 1] = color;
				m_coloring(level + 1);
			}
		}
	}
}
bool promising(index level) {
	int j;		bool trueFlag;
	trueFlag = true;
	j = 1;
	while (j < level && trueFlag) {
		if (W[level][j] && vcolor[level] == vcolor[j])
			trueFlag = false;
		j++;
	}
	return trueFlag;
}