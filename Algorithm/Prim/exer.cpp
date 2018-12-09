#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

struct edge {
	int vertex1;
	int vertex2;
	int weight;
}edge;


vector<int> nearest;
vector<int> dis;
vector<struct edge> F;
vector<vector<int>> W;
int N = 5;

int main() {
	fstream fin("input.txt");
	W.assign(N+1, vector<int>(N+1, 0));
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++)
			fin >> W[i][j];
	}

	return 0;
}
void prim() {
	nearest.assign(N + 1, 0);
	dis.assign(N + 1, 0);

	for (int i = 2; i <= N; i++) {
		//nearest[i] = i;
		nearest[i] = 1;
		dis[i] = W[1][i];
	}

	int min;
	int minNode;
	for (int i = 2; i <= N; i++) {
		min = 100000;
		for (int j = 2; j <= N; j++) {
			if (0<= dis[j] < min) {
				min = dis[j];
				minNode = j;
			}
		}

		struct edge e = { minNode, nearest[minNode],min };
		F.push_back(e);

		// distance[minNode] = -1; »©¸ÔÀ½
		for (int j = 2; j <= N; j++) {
			if (dis[j] > W[j][minNode]) {
				dis[j] = W[j][minNode];
				nearest[j] = minNode;
			}
		}

	}
	

}