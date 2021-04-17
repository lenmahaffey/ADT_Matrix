#pragma once
#include <string>
#include <iostream>
#include "MatrixCell.h"

template <class T>
class Matrix
{
private:
	const int length;
	const int height;
	MatrixCell<T>** arr;

public:
	Matrix<T>(const int& length, const int& height, const T& defaultValue);
	void Display();
	MatrixCell<T> GetCell(std::string cell) const;
	void SetCell(const std::string& cell, MatrixCell<T> T);
	void SetCellContents(const std::string& cell, T& contents);
	~Matrix();
};

template <class T>
Matrix<T>::Matrix(const int& rowLength, const int& columnheight, const T& defaultValue) :
	height(columnheight), length(rowLength)
{
	arr = new MatrixCell<T>*[height];
	for (int row = 0; row <= columnheight - 1; row++)
	{
		arr[row] = new MatrixCell<T>[rowLength];
		for (int column = 0; column <= rowLength - 1; column++)
		{
			MatrixCell<T> current = MatrixCell<T>();
			current.SetContents(defaultValue);
			std::string n;
			char col = column + 65;
			std::string r = std::to_string(row + 1);
			n += col;
			n += r;
			current.SetName(n);
			arr[row][column] = current;
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
MatrixCell<T> Matrix<T>::GetCell(std::string cell) const
{
	return arr[0][0];
}

template <class T>
void Matrix<T>::SetCell(const std::string& cell, MatrixCell<T> c)
{

}

template <class T>
void Matrix<T>::SetCellContents(const std::string& cell, T& contents)
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
