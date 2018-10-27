#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>

void matPrn(vector<vector<int>> A, char* matName) { // ����� ������ִ� �Լ�

	int startIndex = 0; // 0���ε������� ���
	int matSize = A.size() -1; // N-1 �ε������� ���
	int colSize = matSize - startIndex + 1; // Į������
	int fontWidth = 10;   // 10 �̻��� ¦���� �ؾ� ��� ����� ���������� ����.
	int blockWidth = fontWidth / 2;

	//--------------------------------------------------------------------------------
	// ��� 
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "l" << setw(fontWidth - 8) << right << matName << "[i][j] l";
	for (int i = 0; i < colSize; i++) {				// ��� Į�� 
		cout << setw(fontWidth) << i + 1;
	}
	cout << setw(blockWidth) << right << "l" << endl;
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	//-----------------------------------------------------------------------------------
	// ������Ʈ �κ�
	// 1�� �ε������� ��� ũ�⸸ŭ ���
	int row = 1;
	for (int i = startIndex; i <= matSize; i++) {
		cout << "l" << setw(blockWidth) << row++ << setw(blockWidth) << "l";

		for (int j = startIndex; j <= matSize; j++) {
			cout << setw(fontWidth) << A[i][j];
		}

		cout << setw(blockWidth) << right << "l" << endl;
	}


	//-----------------------------------------------------------------------------------
	// �ϴ� 
	for (int i = 0; i <= colSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}