#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
#include "MatrixCell.h"
	template <class T>
	class Matrix
	{
	public:
		Matrix<T>(int height, int lenght, T defaultValue);
		void Display();
		int GetLength();
		int GetHeight();
		MatrixCell<T> GetCell(std::string cell) const;
		MatrixCell<T> GetCell(int column, int row) const;
		void SetCell(std::string& cell, MatrixCell<T> T);
		void SetCell(int col, int row, MatrixCell<T> T);
		void SetCellContents(std::string& cell, T& contents);
		void SetCellContents(int col, int row, T& contents);
		~Matrix();

	private:
		const int length;
		const int height;
		MatrixCell<T>** arr;
	};

	template <class T>
	Matrix<T>::Matrix(int columnheight, int rowLength, T defaultValue) :
		height(columnheight), length(rowLength)
	{
		if (columnheight > 700)
		{
			throw Exceptions::HeightOutOfBounds();
		}
		if (rowLength > 700)
		{
			throw Exceptions::LengthOutOfBounds();
		}

		arr = new MatrixCell<T>*[height];
		for (int column = 0; column <= columnheight - 1; column++)
		{
			arr[column] = new MatrixCell<T>[rowLength];
			for (int row = 0; row <= rowLength - 1; row++)
			{
				MatrixCell<T> current;
				CellAddress currentAddress(column, row);
				current.SetContents(defaultValue);
				current.SetAddress(currentAddress);
				std::string n;
				char col = column + 65;
				std::string r = std::to_string(row + 1);
				n += col;
				n += r;
				current.SetName(n);
				arr[column][row] = current;
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
			std::cout << "  " << row + 1 << "  |";
			for (int column = 0; column < length; column++)
			{
				std::cout << "  " << arr[row][column] << "  |";
			}
			std::cout << std::endl;
			std::cout << std::string((6 * (length + 1)), '-') << std::endl;
		}
	}
	template <class T>
	int Matrix<T>::GetLength()
	{
		return length;
	}

	template <class T>
	int Matrix<T>::GetHeight()
	{
		return height;
	}

	template <class T>
	MatrixCell<T> Matrix<T>::GetCell(int column, int row) const
	{
		return arr[column][row];
	}

	template <class T>
	MatrixCell<T> Matrix<T>::GetCell(std::string cell) const
	{
		std::string letters = "";
		std::string numbers = "";
		for (int i = 0; i < cell.length(); i++)
		{
			if (cell[i] >= 65 && cell[i] <= 90)
			{
				letters += cell[i];
			}
			else if (cell[i] >= 48 && cell[i] <= 57)
			{
				numbers += cell[i];
			}
			else
			{
				throw Exceptions::BadAddressString();
			}
		}
		int c = CellAddress::CalculateIntForAddressString(letters);
		int r = stoi(numbers);

		if (c > height)
		{
			throw Exceptions::BadAddressString("The address is out of range for this matrix");
		}
		if (r > length)
		{
			throw Exceptions::BadAddressString("The address is out of range for this matrix");
		}
		r -= 1;
		return arr[c][r];
	}

	template <class T>
	void Matrix<T>::SetCell(std::string& cell, MatrixCell<T> c)
	{

	}

	template <class T>
	void Matrix<T>::SetCell(int col, int row, MatrixCell<T> T)
	{

	}

	template <class T>
	void Matrix<T>::SetCellContents(std::string& cell, T& contents)
	{

	}

	template <class T>
	void Matrix<T>::SetCellContents(int col, int row, T& contents)
	{

	}

	template <class T>
	Matrix<T>::~Matrix()
	{
		for (int column = 0; column <= length - 1; column++)
		{
			delete[] arr[column];
		}
		delete[] arr;
	}
#endif //MATRIX_H