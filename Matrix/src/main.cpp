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
	Matrix<char> game = Matrix<char>(4 ,6, 'E');
	game.Display();
	return 0;
}

