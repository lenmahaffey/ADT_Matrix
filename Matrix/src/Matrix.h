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
		Matrix<T>(int columns, int rows, T defaultValue);
		Matrix<T>(const Matrix<T>& other);
		void Display();
		int GetLength() const;
		int GetHeight() const;
		Cell<T> GetCell(const std::string& cell) const;
		Cell<T> GetCell(const int& column, const int& row) const;
		T GetCellContents(const std::string& cell) const;
		T GetCellContents(const int& column, const int& row) const;
		void SetCell(const std::string& cell, const Cell<T>& T);
		void SetCell(const int& col, const int& row, const Cell<T>& T);
		void SetCellContents(const std::string& cell, const T& contents);
		void SetCellContents(const int& col, const int& row, const T& contents);
		static CellAddress GetCellAddressFromAddressString(const std::string& a);
		~Matrix();

		Matrix<T> operator=(const Matrix<T>& other);
		bool operator==(const Matrix<T>& other);
		bool operator!=(const Matrix<T>& other);

	private:
		int length;
		int height;
		Cell<T>** matrix;
	};

	template <class T>
	Matrix<T>::Matrix() :
		height(0), length(0)
	{
		matrix = new Cell<T>*[length];
		for (int column = 0; column <= length - 1; column++)
		{
			matrix[column] = new Cell<T>[height];
			for (int row = 0; row <= height - 1; row++)
			{
				Cell<T> current;
				CellAddress currentAddress{ column, row };
				current.SetContents(T);
				current.SetAddress(currentAddress);
				matrix[column][row] = current;
			}
		}
	}

	template <class T>
	Matrix<T>::Matrix(int columns, int rows, T defaultValue) :
		height(rows), length(columns)
	{
		if (rows <= 0 || rows > 700)
		{
			throw Exceptions::RowOutOfBounds();
		}

		if (columns <= 0 || columns > 700)
		{
			throw Exceptions::ColumnOutOfBounds();
		}

		matrix = new Cell<T>*[rows];
		for (int r = 0; r < rows; r++)
		{
			matrix[r] = new Cell<T>[columns];
			for (int c = 0; c < columns; c++)
			{
				CellAddress currentAddress(c, r);
				Cell<T> current{c, r, defaultValue};
				matrix[r][c] = current;
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
			for (int c = 0; c <= height - 1; c++)
			{
				matrix[c] = new Cell<T>[length];
				for (int r = 0; r <= length - 1; r++)
				{
					matrix[r][c] = other[r][c];
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
		for (int r = 0; r < height; r++)
		{
			std::cout << "  " << r + 1 << "  |";
			for (int c = 0; c < length; c++)
			{
				std::cout << "  " << matrix[r][c] << "  |";
			}
			std::cout << std::endl;
			std::cout << std::string((6 * (length + 1)), '-') << std::endl;
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
	ADT::Cell<T> Matrix<T>::GetCell(const int& c, const int& r) const
	{
		if (c < 0 || c > length)
		{
			throw Exceptions::ColumnOutOfBounds();
		}
		if (r < 0 || r > height)
		{
			throw Exceptions::RowOutOfBounds();
		}
		Cell<T> returnCell{ matrix[r][c] };
		return returnCell;
	}

	template <class T>
	Cell<T> Matrix<T>::GetCell(const std::string& cellAddress) const
	{
		CellAddress test{ cellAddress };
		if (test.GetColumn() < 0 || test.GetColumn() > length)
		{
			throw Exceptions::ColumnOutOfBounds();
		}
		if (test.GetRow() < 0 || test.GetRow() > height)
		{
			throw Exceptions::RowOutOfBounds();
		}
		int testC = test.GetColumn();
		int testR = test.GetRow();
		Cell<T> returnCell{ matrix[test.GetRow()][test.GetColumn()] };
		return returnCell;
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
		Cell<T> c = matrix[test.GetRow()][test.GetColumn()];
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

		Cell<T> c = matrix[r][c];
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
		matrix[test.GetRow()][test.GetColumn()] = newCell;
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
		matrix[r][c] = newCell;
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
		Cell<T>* current = &matrix[test.GetRow()][test.GetColumn()];
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
		Cell<T>* current = &matrix[r][c];
		current->SetContents(newContents);
	}

	template <class T>
	Matrix<T>::~Matrix()
	{
		for (int row = 0; row < height; row++)
		{
			delete[] matrix[row];
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
	template <class T>
	bool Matrix<T>::operator==(const Matrix<T>& other)
	{
		if (length != other.length || height != other.height)
		{
			return false;
		}


		for (int c = 0; c < height; c++)
		{
			for (int r = 0; r < length; r++)
			{
				Cell<T> thisCell{matrix[c][r]};
				Cell<T> otherCell{ other.matrix[c][r] };
				if ( thisCell.GetContents() != otherCell.GetContents())
				{
					return false;
				}
			}
		}
		return true;
	}

	template <class T>
	bool Matrix<T>::operator!=(const Matrix<T>& other)
	{
		if (length != other.length || height != other.height )
		{
			return true;
		}

		for (int r = 0; r < height; r++)
		{
			for (int c = 0; c < length; c++)
			{
				Cell<T> temp1{ matrix[r][c] };
				Cell<T> temp2{ other.matrix[r][c] };
				if (temp1.GetContents() != temp2.GetContents())
				{
					return true;
				}
			}
		}
		return false;
	}
}

#endif //MATRIX_H