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
using namespace std;

int main()
{
	MatrixCell<char>* test = new MatrixCell<char>[25];
	Matrix<char> game = Matrix<char>(10, 10, 'E');
	game.Display();
	//cout << game.GetContents("B4");
	return 0;
}

