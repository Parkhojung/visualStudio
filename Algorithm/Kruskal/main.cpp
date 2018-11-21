#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <algorithm>

typedef int index;
typedef index set_pointer;
vector<index> U;
typedef struct edge {
	int node1;
	int node2;
	int weight;
}edge;

void kruskal(int N, int M, vector<edge> E, vector<edge>& F);
void makeset(index i);
set_pointer find(index i);
void merge(set_pointer p, set_pointer q);
bool equal(set_pointer p, set_pointer q);
void initial(int n);
void prnEdge(edge item);
bool compareWeight(const edge& x, const edge& y);
int main() {
	int N,M;
	index i, j;
	int n1;
	int n2;
	int w;
	set_pointer p, q;
	vector<edge> edgeSet;
	vector<edge> resultEdgeSet;
	fstream fin("input.txt");
	
	fin >> N >> M;

	U.assign(N + 1, 0);
	for (int i = 0; i < M; i++) {
		edge e;
		fin >> e.node1;
		fin >> e.node2;
		fin >> e.weight;
		edgeSet.push_back(e);
	}

	
	kruskal(N, M, edgeSet, resultEdgeSet);

	for (auto item : resultEdgeSet) {
		prnEdge(item);

	}
	

	return 0;
}
void prnEdge(edge item) {
	cout << "(" << item.node1 << "," << item.node2 << ") = " << item.weight << endl;
}

bool compareWeight(const edge& x, const edge& y) {
	return x.weight < y.weight;
}

void kruskal(int N, int M, vector<edge> E, vector<edge>& F) {
	index i, j;
	set_pointer p, q;
	edge e;

	sort(E.begin(), E.end(), compareWeight);

	for (auto iter : E) {
		cout << iter.node1 << " ";
		cout << iter.node2 << " ";
		cout << iter.weight;
		cout << endl;
	}

	initial(N);

	int order = 0;
	while (F.size() < N - 1) {
		e = E[order];
		i = e.node1;
		j = e.node2;
		p = find(i);
		q = find(j);
		if (!equal(p, q)) {
			merge(p, q);
			F.push_back(e);
		}
		order++;
	}
}

void makeset(index i) {
	U[i] = i;
}
set_pointer find(index i) {
	index j = i;
	while (U[j] != j)
		j = U[j];
	return j;
}
void merge(set_pointer p, set_pointer q) {
	if (p < q)
		U[q] = p;
	else
		U[p] = q;
}
bool equal(set_pointer p, set_pointer q) {
	if (p == q)
		return true;
	else
		return false;
}
void initial(int n) {
	index i;
	for (i = 1; i <= n; i++) {
		makeset(i);
	}
}