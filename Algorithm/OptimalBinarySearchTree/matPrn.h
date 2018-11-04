#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <vector>

#define FONTWIDTH 10
#define BLOCKWIDTH 5 // FONTHWIDTH/2로 할것

void end();

template <typename T>
void printWide(T s, int wide,string endString="endl", string side="left");
template <typename T1>
void matPrn(vector<vector<T1>> A, char* matName, int firstRow,int lastRow, int firstCol,int lastCol) {
	// r1: 시작 로우 r2: 마지막 로우 c1 :시작 칼럼 c2:마지막 칼럼 

	int colSize = lastCol - firstCol+1;
	int rowSize = lastRow - firstRow + 1;

	//--------------------------------------------------------------------------------
	// 상단 
	for (int i = 0; i <= colSize*FONTWIDTH + BLOCKWIDTH * 3; i++) {
		cout << "-";
	}

	cout << endl <<"l" << setw(FONTWIDTH - 8) << right << matName << "[i][j] l";

	for (int i = firstCol; i <= lastCol; i++) {				// 상단 칼럼 
		printWide<int>(i,FONTWIDTH,"");
	}

	printWide<string>("l", BLOCKWIDTH, "endl");
	
	for (int i = 0; i <= colSize*FONTWIDTH + BLOCKWIDTH * 3; i++) {
		cout << "-";
	}
	end();

//-----------------------------------------------------------------------------------
//엘리먼트
	for (int i = firstRow; i <= lastRow; i++) {
		cout << "l" << setw(BLOCKWIDTH) << i << setw(BLOCKWIDTH) << "l";
		

		for (int j = firstCol; j <= lastCol; j++) {
			printWide<T1>(A[i][j], FONTWIDTH, "");
		}
		printWide<string>("l", BLOCKWIDTH, "endl","right");
	}


	//-----------------------------------------------------------------------------------
	// 하단 

	for (int i = 0; i <= colSize*FONTWIDTH + BLOCKWIDTH * 3; i++) {
		cout << "-";
	}
	end(); end();
}

template <typename T>
void printWide(T s, int wide, string endString, string side) {

	if (side == "left") {
		cout << setw(wide) << s;
	}
	else {
		cout << setw(wide) << right << s;
	}
	
	if (endString == "endl") {
		cout << endl;
	}
	else {
		cout << endString;
	}
}

void end() {
	cout << endl;
}