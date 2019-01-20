#include <iostream>
using namespace std;
#include <queue>
#include <functional>
#include <queue>
void findBestVideo(int, int);
int main() {

	int testcase;
	int N, M;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		
		cin >> N >> M;
		cout << "#" << i + 1 <<" ";
		findBestVideo(N, M);
	}

	return 0;
}

void findBestVideo(int N, int M) {
	int i, j;
	
	priority_queue<float> pq;
	priority_queue<float, vector<float>, greater<float>> pqNumberOfM;
	int k;
	for (i = 0; i < N; i++) {
		cin >> k;
		pq.push(k);
	}

	float curGrade = 0;
	float nextGrade = 0;



	// 가장 큰 수를 M개 만큼 저장하기
	for (i = 0; i < M; i++) {
		nextGrade = pq.top();
		pq.pop();
		pqNumberOfM.push(nextGrade);
	}

	for (i = 0; i < M; i++) {
		nextGrade = pqNumberOfM.top();
		pqNumberOfM.pop();
		curGrade = (curGrade + nextGrade) / 2;
	}

	cout << curGrade << endl;
}