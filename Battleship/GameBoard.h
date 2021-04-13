#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace Battleship
{
	class GameBoard
	{
	private:
		const int boardLength;
		const int boardHeight;
		char** board;

	public:
		GameBoard(const int& rowLength, const int& columnheight);
		char GetCellContents(std::string guess);
		void PlaceGamePiece();
		void DisplayBoard();
		~GameBoard();
	};
}
