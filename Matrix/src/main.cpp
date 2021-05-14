/*
	CSC160 8N0 Computer Science 1
	File: main.cpp
	By: Len Mahaffey
	Project:
	Last Edited:
	Description:
*/

#include <iostream>
#include "Matrix.h"
#include "CellAddress.h"
using namespace std;
using namespace ADT;

int main()
{
	int test{ CellAddress::CalculateIntForAddressString("AA") };

	Matrix<char> game = Matrix<char>(10 , 5, 'E');
	game.Display();

	Matrix<char> game1 = Matrix<char>(5, 10, 'E');
	game1.Display();
	return 0;
}

