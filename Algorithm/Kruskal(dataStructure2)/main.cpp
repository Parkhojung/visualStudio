#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <algorithm>

typedef int index;
typedef index set_pointer;
struct nodetype {
	index parent;
	int depth;
};
vector<nodetype> U;
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
	int N, M;
	vector<edge> edgeSet;
	vector<edge> resultEdgeSet;
	fstream fin("input.txt");

	fin >> N >> M;

	for (int i = 0; i < M; i++) {
		edge e;
		fin >> e.node1;
		fin >> e.node2;
		fin >> e.weight;
		edgeSet.push_back(e);
	}

	cout <<  "#입력데이터" << endl;
	for (auto e : edgeSet) {
		prnEdge(e);
	}
	kruskal(N, M, edgeSet, resultEdgeSet);
	
	cout << endl <<"#프로그램 수행결과" << endl;
	for (auto e : resultEdgeSet) {
		prnEdge(e);

	}
	return 0;
}
void prnEdge(edge item) {
	cout << "(" << item.node1 << "," << item.node2 << ") " << item.weight << endl;
}
bool compareWeight(const edge& x, const edge& y) {
	return x.node1 < y.node1;
}
void kruskal(int N, int M, vector<edge> E, vector<edge>& F) {
	index i, j;
	set_pointer p, q;
	edge e;

	sort(E.begin(), E.end(), compareWeight);
	initial(N);

	cout << "전처리 후 데이터" << endl;
	for (auto e : E) {
		prnEdge(e);

	}

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
	return;
}
void makeset(index i) {
	U.push_back({ i, 0}) ;
}
set_pointer find(index i) {
	index j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;
}
void merge(set_pointer p, set_pointer q) {
	if (U[p].depth == U[q].depth) {
		U[p].depth += 1;
		U[q].parent = p;
	}else if(U[p].depth < U[q].depth)
		U[p].parent = q;
	else
		U[q].parent = p;
}
bool equal(set_pointer p, set_pointer q) {
	if (p == q)
		return true;
	else
		return false;
}
void initial(int n) {
	index i;
	makeset(-1);
	for (i = 1; i <= n; i++) {
		makeset(i);
	}
}