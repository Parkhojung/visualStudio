#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

typedef int index;
typedef int number;
typedef struct edge {
	number vertex1;
	number vertex2;
	number weight;
};
typedef vector<edge> set_of_edges;

void prim(int n, const vector<vector<number>> W, set_of_edges& F);
void prnEdge(edge item);
int main() {
	int N;
	vector<vector<number>> W;
	set_of_edges F;
	fstream fin("input.txt");
	
	fin >> N;
	W.assign(N + 1, vector<number>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			fin >> W[i][j];
		}
	}
	
	prim(N, W, F);

	for (auto e : F) {
		prnEdge(e);
	}

	return 0;
}

void prim(int n, const vector<vector<number>> W, set_of_edges& F) {
	index i, vnear; number min ; edge e;
	vector<index> nearest(n+1, 0); vector<number> distance(n+1, 0);

	for (i = 2; i <= n; i++) {
		nearest[i] = 1;
		distance[i] = W[1][i];
	}

	for (int cnt = 1; cnt < n; cnt++) { // n-1¹ø ¹Ýº¹
		min = 10000;
		for (i = 2; i <= n; i++) {
			if ( (0 <= distance[i]) && (distance[i] <= min)) {
				min = distance[i];
				vnear = i;
			}
		}
		//e = edge connecting vnear and nearest[vnear];
		e.vertex1 = nearest[vnear];
		e.vertex2 = vnear;
		e.weight = min;

		F.push_back(e);
		distance[vnear] = -1;
		for (i = 2; i <= n; i++) {
			if (W[i][vnear] < distance[i]) {
				distance[i] = W[i][vnear];
				nearest[i] = vnear;
			}
		}
	}

}
void prnEdge(edge item) {
	cout << "(" << item.vertex1 << "," << item.vertex2 << ") " << item.weight << endl;
}