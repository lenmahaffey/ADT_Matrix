#include "GameBoard.h"


Battleship::GameBoard::GameBoard(const int& rowLength, const int& columnheight) :
	boardHeight(columnheight), boardLength(rowLength)
{
	board = new char* [columnheight];

	for (int row = 0; row <= columnheight -1; row++)
	{
		board[row] = new char[rowLength];
		for (int column = 0; column <= rowLength - 1; column++)
		{
			board[row][column] = 'E';
		}
	}
}

void Battleship::GameBoard::DisplayBoard()
{
	std::cout << "   ";
	for (int i = 0; i < boardHeight; i++)
	{
		std::cout << " | " << i + 1;
	}
	std::cout << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	for (int row = 0; row < boardHeight; row++)
	{
		std::cout << "| " << (char)(row + 65) << " | ";
		for (int column = 0; column < boardLength; column++)
		{
			std::cout << board[row][column] << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}
Battleship::GameBoard::~GameBoard()
{

}