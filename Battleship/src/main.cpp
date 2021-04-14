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
using namespace Battleship;

int main()
{
	Matrix<char> game = Matrix<char>(9, 9);
	game.Display();
	//cout << game.GetContents("B4");
	return 0;
}

