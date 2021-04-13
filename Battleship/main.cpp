/*
	CSC160 8N0 Computer Science 1
	File: main.cpp
	By: Len Mahaffey
	Project:
	Last Edited:
	Description:
*/

#include <iostream>
#include "GameBoard.h"
using namespace std;
using namespace Battleship;

int main()
{
	GameBoard game = GameBoard(10, 10);
	game.DisplayBoard();
	return 0;
}

