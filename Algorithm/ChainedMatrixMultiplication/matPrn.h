#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>


void matPrn(vector<vector<int>> A, char* matName) {

	int matSize = A.size() - 1; // 1�� �ε��� ���� ����ؼ� N*N����� (N-1)*(N-1)�� ������ ����
	int fontWidth = 10;   // 10 �̻��� ¦���� �ؾ� ��� ����� ���������� ����.
	int blockWidth = fontWidth / 2;

//--------------------------------------------------------------------------------
// ��� 
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "l" << setw(fontWidth - 8) << right << matName << "[i][j] l";
	for (int i = 0; i < matSize; i++) {				// ��� Į�� 
		cout << setw(fontWidth) << i + 1;
	}
	cout << setw(blockWidth) << right << "l" << endl;
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
//-----------------------------------------------------------------------------------
// ������Ʈ �κ�
// 1�� �ε������� ��� ũ�⸸ŭ ���
	for (int i = 1; i <= matSize; i++) { 
		cout << "l" << setw(blockWidth) << i << setw(blockWidth) << "l";

		for (int j = 1; j <= matSize; j++) {
			cout << setw(fontWidth) << A[i][j];
		}

		cout << setw(blockWidth) << right << "l" << endl;
	}


//-----------------------------------------------------------------------------------
// �ϴ� 
	for (int i = 0; i <= matSize*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}