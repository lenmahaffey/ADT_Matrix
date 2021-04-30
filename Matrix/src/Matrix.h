#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
#include "Cell.h"
namespace ADT
{
	template <class T>
	class Matrix
	{
	public:
		Matrix<T>();
		Matrix<T>(int height, int length, T defaultValue);
		Matrix<T>(const Matrix<T>& other);
		void Display();
		int GetLength() const;
		int GetHeight() const;
		Cell::Cell<T> GetCell(const std::string& cell) const;
		Cell::Cell<T> GetCell(const int& column, const int& row) const;
		T GetCellContents(const std::string& cell) const;
		T GetCellContents(const int& column, const int& row) const;
		void SetCell(const std::string& cell, const Cell<T>& T);
		void SetCell(const int& col, const int& row, const Cell<T>& T);
		void SetCellContents(const std::string& cell, const T& contents);
		void SetCellContents(const int& col, const int& row, const T& contents);
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
		if (height <= 0 || height > 700)
		{
			throw Exceptions::ColumnOutOfBounds();
		}

		if (length <= 0 || length > 700)
		{
			throw Exceptions::RowOutOfBounds();
		}

		matrix = new Cell<T>*[length];
		for (int column = 0; column <= length - 1; column++)
		{
			matrix[column] = new Cell<T>[height];
			for (int row = 0; row <= height - 1; row++)
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
		std::cout << std::string((6 * (height + 1)), '-') << std::endl;
		std::cout << "   ";
		for (int i = 0; i < height; i++)
		{
			std::cout << "  |  " << (char)(i + 65);
		}
		std::cout << "  |" << std::endl;

		std::cout << std::string((6 * (height + 1)), '-') << std::endl;
		for (int row = 0; row < length; row++)
		{
			std::cout << "  " << row + 1 << "  |";
			for (int column = 0; column < height; column++)
			{
				std::cout << "  " << matrix[row][column] << "  |";
			}
			std::cout << std::endl;
			std::cout << std::string((6 * (height + 1)), '-') << std::endl;
		}
	}

	template <class T>
	int Matrix<T>::GetLength() const
	{
		return length;
	}

	template <class T>
	int Matrix<T>::GetHeight() const
	{
		return height;
	}

	template <class T>
	Cell<T> Matrix<T>::GetCell(const int& c, const int& r) const
	{
		if (c < 0 || c > height)
		{
			throw Exceptions::ColumnOutOfBounds();
		}
		if (r < 0 || r > length)
		{
			throw Exceptions::RowOutOfBounds();
		}
		return matrix[c][r];
	}

	template <class T>
	Cell<T> Matrix<T>::GetCell(const std::string& cellAddress) const
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
	T Matrix<T>::GetCellContents(const std::string& cellAddress) const
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
	T Matrix<T>::GetCellContents(const int& c, const int& r) const
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
	void Matrix<T>::SetCell(const std::string& cellAddress, const Cell<T>& newCell)
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
		matrix[test.GetColumn()][test.GetRow()] = newCell;
	}

	template <class T>
	void Matrix<T>::SetCell(const int& c, const int& r, const Cell<T>& newCell)
	{
		if (c < 0 || c > height)
		{
			throw Exceptions::ColumnOutOfBounds();
		}
		if (r < 0 || r > length)
		{
			throw Exceptions::RowOutOfBounds();
		}
		matrix[c][r] = newCell;
	}

	template <class T>
	void Matrix<T>::SetCellContents(const std::string& cellAddress, const T& newContents)
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
		Cell<T>* current = &matrix[test.GetColumn()][test.GetRow()];
		current->SetContents(newContents);
	}

	template <class T>
	void Matrix<T>::SetCellContents(const int& c, const int& r, const T& newContents)
	{
		if (c < 0 || c > height)
		{
			throw Exceptions::ColumnOutOfBounds();
		}
		if (r < 0 || r > length)
		{
			throw Exceptions::RowOutOfBounds();
		}
		Cell<T>* current = &matrix[c][r];
		current->SetContents(newContents);
	}

	template <class T>
	Matrix<T>::~Matrix()
	{
		for (int column = 0; column < length; column++)
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

		for (int i = 0; i < (int)a.length(); i++)
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
}
#endif //MATRIX_H