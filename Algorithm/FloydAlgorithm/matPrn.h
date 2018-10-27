#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>

void matPrn(vector<vector<int>> A, char* matName) { // 행렬을 출력해주는 함수

	int startIndex = 0; // 0번인덱스부터 사용
	int matSize = A.size() -1; // N-1 인덱스까지 사용
	int colSize = matSize - startIndex + 1; // 칼럼개수
	int fontWidth = 10;   // 10 이상의 짝수로 해야 출력 모양이 정상적으로 나옴.
	int blockWidth = fontWidth / 2;

	//--------------------------------------------------------------------------------
	// 상단 
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "l" << setw(fontWidth - 8) << right << matName << "[i][j] l";
	for (int i = 0; i < colSize; i++) {				// 상단 칼럼 
		cout << setw(fontWidth) << i + 1;
	}
	cout << setw(blockWidth) << right << "l" << endl;
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	//-----------------------------------------------------------------------------------
	// 엘리먼트 부분
	// 1번 인덱스부터 행렬 크기만큼 출력
	int row = 1;
	for (int i = startIndex; i <= matSize; i++) {
		cout << "l" << setw(blockWidth) << row++ << setw(blockWidth) << "l";

		for (int j = startIndex; j <= matSize; j++) {
			cout << setw(fontWidth) << A[i][j];
		}

		cout << setw(blockWidth) << right << "l" << endl;
	}


	//-----------------------------------------------------------------------------------
	// 하단 
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}