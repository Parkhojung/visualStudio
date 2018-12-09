#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <algorithm>

struct edge {
	int vertex1;
	int vertex2;
	int weight;
};
struct node {
	int parent;
	int depth;
};


int n, m;
vector<struct edge> edge_set;
vector<struct edge> F;
vector<struct node> U;

void prnEdge(edge item);
void kruskal();
bool compareEdgeSet(const edge& a, const edge& b);
void merge(int p, int q);
int find(int);
int main() {

	fstream fin("input.txt");
	fin >> n >> m;
	for (int i = 0; i < m; i++) {
		edge e;
		fin >> e.vertex1 >> e.vertex2 >> e.weight;
		edge_set.push_back(e);
	}
	
	kruskal();
	for (auto e : F) {
		prnEdge(e);

	}

	return 0;
}

void kruskal() {
	edge curEdge;

	sort(edge_set.begin(), edge_set.end(), compareEdgeSet);

	
	for (int i = 0; i <= n; i++) {
		node n = { i,0 };
		U.push_back(n);
	}

	int ord = 0;
	int p, q;
	
	while (F.size() < n - 1) {
		curEdge = edge_set[ord++];
		p = find(curEdge.vertex1);
		q = find(curEdge.vertex2);
		if ( p != q ) {
			merge(p, q);
			F.push_back(curEdge);
		}

	}

}

bool compareEdgeSet(const edge& a,const edge& b) {
	return a.weight < b.weight;
}

void merge(int p, int q) {
	if (U[p].depth == U[q].depth) {
		U[p].parent = q;
		U[q].depth++;
	}
	else if (U[p].depth < U[q].depth) {
		U[p].parent = q;
	}
	else {
		U[q].parent = p;
	}
}
int find(int p) {
	int j = p;
	while (U[j].parent != j) {
		j = U[j].parent;
	}
	return j;
}
void prnEdge(edge item) {
	cout << "(" << item.vertex1<< "," << item.vertex2<< ") " << item.weight << endl;
}