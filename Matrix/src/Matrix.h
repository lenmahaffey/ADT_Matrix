#pragma once
#include <string>
#include <iostream>
#include "Cell.h"

template <class T>
class Matrix
{
public:
	Matrix<T>();
	Matrix<T>(int height, int lenght, T defaultValue);
	Matrix<T>(const Matrix<T>& other);
	void Display();
	int GetLength();
	int GetHeight();
	Cell<T> GetCell(std::string cell) const;
	Cell<T> GetCell(int column, int row) const;
	void SetCell(std::string& cell, Cell<T> T);
	void SetCell(int col, int row, Cell<T> T);
	void SetCellContents(std::string& cell, T contents);
	void SetCellContents(int col, int row, T contents);
	~Matrix();

	Matrix<T> operator=(const Matrix<T>& other);

private:
	int length;
	int height;
	Cell<T>** arr;
};

template <class T>
Matrix<T>::Matrix() :
	height(0), length(0)
{
	arr = new Cell<T>*[height];
	for (int column = 0; column <= height - 1; column++)
	{
		arr[column] = new Cell<T>[length];
		for (int row = 0; row <= length - 1; row++)
		{
			Cell<T> current;
			CellAddress currentAddress(column, row);
			current.SetContents(' ');
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
	if (rowLength == 0 || columnheight == 0)
	{
		throw Exceptions::MatrixException("Length and height must be greater than zero");
	}
	arr = new Cell<T>*[height];
	for (int column = 0; column <= columnheight - 1; column++)
	{
		arr[column] = new Cell<T>[rowLength];
		for (int row = 0; row <= rowLength - 1; row++)
		{
			Cell<T> current;
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
Matrix<T>::Matrix(const Matrix<T>& other)
{
	if (*this != other)
	{
		int height = other.GetHeight();
		int lenght = other.GetLength();
		arr = new Cell<T>*[height];
		for (int column = 0; column <= height - 1; column++)
		{
			arr[column] = new Cell<T>[length];
			for (int row = 0; row <= length - 1; row++)
			{
				arr[column][row] = other[column][row];
			}
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
Cell<T> Matrix<T>::GetCell(int column, int row) const
{
	return arr[column][row];
}

template <class T>
Cell<T> Matrix<T>::GetCell(std::string cell) const
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
void Matrix<T>::SetCell(std::string& cell, Cell<T> c)
{

}

template <class T>
void Matrix<T>::SetCell(int col, int row, Cell<T> T)
{

}

template <class T>
void Matrix<T>::SetCellContents(std::string& cell, T contents)
{

}

template <class T>
void Matrix<T>::SetCellContents(int col, int row, T contents)
{

}

template <class T>
Matrix<T>::~Matrix()
{
	for (int column = 0; column < height; column++)
	{
		delete[] arr[column];
	}
	delete[] arr;
}

template <class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& other)
{
	if (*this != other)
	{
		int height = other.GetHeight();
		int lenght = other.GetLength();
		arr = new Cell<T>*[height];
		for (int column = 0; column <= height - 1; column++)
		{
			arr[column] = new Cell<T>[length];
			for (int row = 0; row <= length - 1; row++)
			{
				arr[column][row] = other[column][row];
			}
		}
	}
}