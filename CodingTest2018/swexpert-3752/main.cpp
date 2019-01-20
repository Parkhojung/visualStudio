#include <iostream>
#include <set>
#include <vector>
using namespace std;
//#include <fstream>
#include <algorithm>
//#include <time.h>
#include <stdio.h>

int cnt = 0;
vector<int> w;
set<int> solutionSet;
int m; // amount of test case
void fun(int level, int weight, bool leftChildFlag);
bool promising(int level, int weight, bool leftChildFlag);
bool desc(int a, int b) {
	return a < b;
}
int main() {
//	time_t start, end;
	double result;
//	start = time(NULL); // 시간 측정 시작


	//fstream fin("input.txt");
	int n;	//# of test case 
	 	
	//fin >> n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		//fin >> m;
		 cin >> m;
		w.clear();
		w.assign(m+1, 0);
		solutionSet.clear();
		for (int j = 1; j <= m; j++) {
			//fin >> w[j];
			cin >> w[j];
		}

		sort(w.begin()+1,w.end(), desc);
		fun(0, 0, true);

		cout << "#" << i <<" " <<solutionSet.size() <<endl;
		for (auto item : solutionSet) {
			cout << item << " ";
		}
		cout << endl;
	}
	
//	end = time(NULL); // 시간 측정 끝
//	result = (double)(end - start);
//	printf("%f", result); //결과 출력

	return 0;
}

void fun(int level, int weight, bool leftChildFlag) {
	
	if (level == m) {		//leaf에서 확인
		solutionSet.insert(weight);
	}
	else {
		if (promising(level, weight, leftChildFlag)) {
			fun(level + 1, weight + w[level + 1], true);
			fun(level + 1, weight, false);
		}
	}

}

bool promising(int level, int weight, bool leftChildFlag) {
	if (solutionSet.count(weight) !=0 && leftChildFlag == true) {
		return false;
	}
	else
		return true;
}