#include <iostream>
#include <vector>
#include <vector>
using namespace std;

int main() {

	return 0;

}

void prim() {

	vector<int> distance;// [2..n]
	vector<int> nearest; // [2..n]

	for (int i = 2; i <= n; i++) { // 초기화
		distance[i] = W[1][i];
		nearest[i] = 1;
	}



	for (int = 1; i < n; i++) { //n-1번
		
		int min = 100000;
		int minNode;
		for (int j = 2; j <= n; j++) {
			if (0 <= distance[j] < min) {
				min = distance[j];
				minNode = j;
			}
		
			F.push_back(new node(nearest[minNode], j, min));
			distance[minNode] = -1;
			for (int k = 2; k <= n; k++) {
				if (distance[k] > W[minNode][k]) {
					distance[k] = W[minNode][k];
					nearest[k] = minNode;
				}
			}
			

		}


	}

}