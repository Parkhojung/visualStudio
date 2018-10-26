#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>


void matPrn(vector<vector<int>> A, char* matName) {

	int matSize = A.size() - 1; // 1번 인덱스 부터 사용해서 N*N행렬을 (N-1)*(N-1)로 사이즈 변경
	int fontWidth = 10;   // 10 이상의 짝수로 해야 출력 모양이 정상적으로 나옴.
	int blockWidth = fontWidth / 2;

//--------------------------------------------------------------------------------
// 상단 
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "l" << setw(fontWidth - 8) << right << matName << "[i][j] l";
	for (int i = 0; i < matSize; i++) {				// 상단 칼럼 
		cout << setw(fontWidth) << i + 1;
	}
	cout << setw(blockWidth) << right << "l" << endl;
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
//-----------------------------------------------------------------------------------
// 엘리먼트 부분
// 1번 인덱스부터 행렬 크기만큼 출력
	for (int i = 1; i <= matSize; i++) { 
		cout << "l" << setw(blockWidth) << i << setw(blockWidth) << "l";

		for (int j = 1; j <= matSize; j++) {
			cout << setw(fontWidth) << A[i][j];
		}

		cout << setw(blockWidth) << right << "l" << endl;
	}


//-----------------------------------------------------------------------------------
// 하단 
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}