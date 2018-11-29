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
	edge() {};
	edge(number vertex1, number vertex2, number weight) {
		this->vertex1 = vertex1;
		this->vertex2 = vertex2;
		this->weight = weight;
	}
};
typedef vector<edge> set_of_edges;

void dijkstra(int n, const vector<vector<number>> W, set_of_edges& F);
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

	dijkstra(N, W, F);
	for (auto e : F) {
		prnEdge(e);
	}
	return 0;
}
void dijkstra(int n, const vector<vector<number>> W, set_of_edges& F) {
	index i, vnear; number min;
	vector<index> touch(n + 1, 0); 
	vector<number> length(n + 1, 10000);
	number lengththorughVnear;
	edge *e;

	for (i = 2; i <= n; i++) {
		touch[i] = 1;
		length[i] = W[1][i];
	}

	for (int cnt = 1; cnt < n; cnt++) { // n-1번 반복
		min = 10000;
		for (i = 2; i <= n; i++) {
			if ((0 <= length[i]) && (length[i] <= min)) {
				min = length[i];
				vnear = i;
			}
		}
		//e = edge connecting vnear and touch[vnear];
		e = new edge(touch[vnear], vnear, min);
		F.push_back(*e);
		
		for (i = 2; i <= n; i++) {
			lengththorughVnear = length[vnear] + W[vnear][i];	// (1과 vnear사이의 거리) + (vnear과 i와의 거리)를 저장
			if (lengththorughVnear < length[i]) {
				length[i] = lengththorughVnear;
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;
	}

}
void prnEdge(edge item) {
	cout << "(" << item.vertex1 << "," << item.vertex2 << ") , length[" << item.vertex2 <<"]:" << item.weight << endl;
}