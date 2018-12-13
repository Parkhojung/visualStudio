#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n;
struct edge {
	int vertex1;
	int vertex2;
	int weight;
};
vector<edge> edge_set;
vector<node> U;
struct node {
	int depth;
	int parent;
};
int main() {
	return 0;
}

void kruskal() {

	sort(edge_set);
	vector<edge> F;
	initial(n);

	while (F.size() < n - 1) {
		edge e = edge_set.front();
		int i = e.vertex1;
		int j = e.vertex2;

		int p = find(i);
		int q = find(j);
		if (p != q) {
			merge(p, q);
			F.push_back(e);
		}
	}
}

void initial(int n) {
	U.assign(n + 1,0);
	makeset(-1);
	for (int i = 1; i <= n; i++)
		makeset(i);
}
void makeset(int i) {
	node n = { 0, i };
	U[i] = n;
}
int find(int i) {
	while (U[i].parent != i) {
		i = U[i].parent;
	}
	return i;
}
void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth++;
		U[q].parent = p;
	}
	else if (U[p].depth > U[q].depth) {
		U[q].parent = p;
	}
	else {
		U[p].parent = q;
	}

}