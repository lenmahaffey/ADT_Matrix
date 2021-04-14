#pragma once
#include <string>
#include <iostream>

namespace Battleship
{
	template <class T>
	class Matrix
	{
	private:
		const int length;
		const int height;
		T** matrix;

	public:
		bool validateCellName(std::string cell, char* letters, int* numbers);
		Matrix<T>(const int& length, const int& height, T defaultValue);
		void Display();
		T GetContents(std::string cell);
		void SetContents(std::string cell, T contents);
		~Matrix();
	};

	template <class T>
	Matrix<T>::Matrix(const int& rowLength, const int& columnheight, T defaultValue) :
		height(columnheight), length(rowLength)
	{
		for (int row = 0; row <= columnheight - 1; row++)
		{
			matrix[row] = new char[rowLength];
			for (int column = 0; column <= rowLength - 1; column++)
			{
				matrix[row][column] = defaultValue;
			}
		}
	}

	template <class T>
	void Matrix<T>::Display()
	{
		std::cout << std::string((6 * (length + 1)), '-') << std::endl;
		std::cout << "   ";
		for (int i = 0; i < length; i++)
		{
			std::cout << "  |  " << (char)(i + 65);
		}
		std::cout << "  |" << std::endl;

		std::cout << std::string((6 * (length + 1)), '-') << std::endl;
		for (int row = 0; row < height; row++)
		{
			std::cout << "  " << row + 1 << "  |  ";
			for (int column = 0; column < length; column++)
			{
				std::cout << matrix[row][column] << "  |  ";
			}
			std::cout << std::endl;
			std::cout << std::string((6 * (length + 1)), '-') << std::endl;
		}
	}

	template <class T>
	T  Matrix<T>::GetContents(std::string cell)
	{
		validateCellName(cell);
		return matrix[0][0];
	}

	template <class T>
	void SetContents(std::string cell, T contents)
	{

	}

	template <class T>
	bool Matrix<T>::validateCellName(std::string cell, char* letters, int* numbers)
	{
		if (cell.length() >= 0)
		{
			return false;
		}
		int charCount = 0;
		int intCount = 0;

		for (int i = 0; i < cell.length(); i++)
		{
			if ((int)cell[i] <= 65 && (int)cell[i] <= 90)
			{
				std::cout << "Found a letter" << std::endl;
			}
		}
		char* cellChars = new char[2];
		int* cellInts = new int[2];
		return false;
	}

	template <class T>
	Matrix<T>::~Matrix()
	{

	}

}
