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

int main()
{
	try
	{
		CellAddress test(7087, 0);
	}
	catch (Exceptions::MatrixException e)
	{
		cout << e.what() << endl;
	}

	try
	{
		CellAddress test(0, 780);
	}
	catch (Exceptions::MatrixException e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Matrix<char> testMatrix = Matrix<char>(701,10,'E');
	}
	catch (Exceptions::MatrixException e)
	{
		cout << e.what() << endl;
	}
	Matrix<char> game = Matrix<char>(10, 10, 'E');
	game.Display();
	return 0;
}

