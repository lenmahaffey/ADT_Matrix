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
	T GetCellContents(std::string cell) const;
	T GetCellContents(int column, int row) const;
	void SetCell(std::string& cell, Cell<T> T);
	void SetCell(int col, int row, Cell<T> T);
	void SetCellContents(std::string& cell, T contents);
	void SetCellContents(int col, int row, T contents);
	static CellAddress GetCellAddressFromAddressString(const std::string& a);
	~Matrix();

	Matrix<T> operator=(const Matrix<T>& other);

private:
	int length;
	int height;
	Cell<T>** matrix;
};

template <class T>
Matrix<T>::Matrix() :
	height(0), length(0)
{
	matrix = new Cell<T>*[height];
	for (int column = 0; column <= height - 1; column++)
	{
		matrix[column] = new Cell<T>[length];
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
			matrix[column][row] = current;
		}
	}
}
template <class T>
Matrix<T>::Matrix(int columnheight, int rowLength, T defaultValue) :
	height(columnheight), length(rowLength)
{
	if (columnheight <= 0 || columnheight > 700)
	{
		throw Exceptions::RowOutOfBounds();
	}

	if (rowLength <= 0 || rowLength > 700)
	{
		throw Exceptions::ColumnOutOfBounds();
	}

	matrix = new Cell<T>*[height];
	for (int column = 0; column <= columnheight - 1; column++)
	{
		matrix[column] = new Cell<T>[rowLength];
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
			matrix[column][row] = current;
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
		matrix = new Cell<T>*[height];
		for (int column = 0; column <= height - 1; column++)
		{
			matrix[column] = new Cell<T>[length];
			for (int row = 0; row <= length - 1; row++)
			{
				matrix[column][row] = other[column][row];
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
			std::cout << "  " << matrix[row][column] << "  |";
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
Cell<T> Matrix<T>::GetCell(int c, int r) const
{
	if (c < 0 || c > height)
	{
		throw Exceptions::ColumnOutOfBounds;
	}
	if (r < 0 || r > length)
	{
		throw Exceptions::RowOutOfBounds;
	}
	return matrix[c][r];
}

template <class T>
Cell<T> Matrix<T>::GetCell(std::string cellAddress) const
{
	CellAddress test{ cellAddress };
	if (test.GetColumn() < 0 || test.GetColumn() > height)
	{
		throw Exceptions::ColumnOutOfBounds();
	}
	if (test.GetRow() < 0 || test.GetRow() > length)
	{
		throw Exceptions::RowOutOfBounds();
	}
	return matrix[test.GetColumn()][test.GetRow()];
}

template <class T>
T Matrix<T>::GetCellContents(std::string cellAddress) const
{
	CellAddress test{ cellAddress };
	if (test.GetColumn() < 0 || test.GetColumn() > height)
	{
		throw Exceptions::ColumnOutOfBounds();
	}
	if (test.GetRow() < 0 || test.GetRow() > length)
	{
		throw Exceptions::RowOutOfBounds();
	}
	Cell<T> c = matrix[test.GetColumn()][test.GetRow()];
	return c.GetContents();
}

template <class T>
T Matrix<T>::GetCellContents(int c, int r) const
{
	if (c < 0 || c > height)
	{
		throw Exceptions::ColumnOutOfBounds;
	}
	if (r < 0 || r > length)
	{
		throw Exceptions::RowOutOfBounds;
	}

	Cell<T> c = matrix[c][r];
	return c.GetContents();
}

template <class T>
void Matrix<T>::SetCell(std::string& cellAddress, Cell<T> c)
{

}

template <class T>
void Matrix<T>::SetCell(int c, int r, Cell<T> newContents)
{
	if (c < 0 || c > height)
	{
		throw Exceptions::ColumnOutOfBounds;
	}
	if (r < 0 || r > length)
	{
		throw Exceptions::RowOutOfBounds;
	}
	matrix[c][r] = newContents;
}

template <class T>
void Matrix<T>::SetCellContents(std::string& cell, T newContents)
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
		delete[] matrix[column];
	}
	delete[] matrix;
}

template <class T>
CellAddress Matrix<T>::GetCellAddressFromAddressString(const std::string& a)
{
	std::string c{};
	std::string r{};

	for (int i = 0; i < (int)a.length() ; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			c.push_back(a[i]);
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			r.push_back(a[i]);
		}
		else
		{
			throw Exceptions::BadAddressString();
		}
	}
	int column = CellAddress::CalculateIntForAddressString(c);
	int row = stoi(r) - 1;
	CellAddress temp(column, row);
	return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& other)
{
	if (*this != other)
	{
		int height = other.GetHeight();
		int lenght = other.GetLength();
		matrix = new Cell<T>*[height];
		for (int column = 0; column <= height - 1; column++)
		{
			matrix[column] = new Cell<T>[length];
			for (int row = 0; row <= length - 1; row++)
			{
				matrix[column][row] = other[column][row];
			}
		}
	}
}