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
		int GetColumnCount() const;
		int GetRowCount() const;
		Cell<T> GetCell(const std::string& cell) const;
		Cell<T> GetCell(const int& column, const int& row) const;
		T GetCellContents(const std::string& cell) const;
		T GetCellContents(const int& column, const int& row) const;
		void SetCell(const std::string& cell, const Cell<T>& T);
		void SetCell(const int& col, const int& row, const Cell<T>& T);
		void SetCellIsEmpty(const std::string& cell, const bool& b);
		void SetCellIsEmpty(const int& col, const int& row, const bool& b);
		void SetCellContents(const std::string& cell, const T& contents);
		void SetCellContents(const int& col, const int& row, const T& contents);
		static CellAddress GetCellAddressFromAddressString(const std::string& a);
		~Matrix();

		Matrix<T> operator=(const Matrix<T>& other);
		Matrix<T> operator=(const Cell<T>& other);
		bool operator==(const Matrix<T>& other);
		bool operator!=(const Matrix<T>& other);

	private:
		int rowCount;
		int columnCount;
		Cell<T>** matrix;

		void deleteMatrix();
	};

	template <class T>
	Matrix<T>::Matrix() :
		columnCount(0), rowCount(0)
	{
		matrix = new Cell<T>*[columnCount];
		for (int column = 0; column <= rowCount - 1; column++)
		{
			matrix[column] = new Cell<T>[rowCount];
			for (int row = 0; row <= columnCount - 1; row++)
			{
				Cell<T> current;
				CellAddress currentAddress{ column, row };
				current.SetContents(T{});
				current.SetAddress(currentAddress);
				matrix[column][row] = current;
			}
		}
	}

	template <class T>
	Matrix<T>::Matrix(int columns, int rows, T defaultValue) :
		columnCount(columns), rowCount(rows)
	{
		if (columns <= 0 || columns > 700)
		{
			throw std::ColumnOutOfBounds("Class: Matrix<T> is limited to 700 columns");
		}

		if (rows <= 0 || rows > 700)
		{
			throw std::RowOutOfBounds("Class: Matrix<T> is limited to 700 rows");
		}

		matrix = new Cell<T>*[columns];
		for (int c = 0; c < columns; c++)
		{
			matrix[c] = new Cell<T>[rows];
			for (int r = 0; r < rows; r++)
			{
				CellAddress currentAddress(c, r);
				Cell<T> current{ c, r, defaultValue };
				matrix[c][r] = current;
			}
		}
	}

	template <class T>
	Matrix<T>::Matrix(const Matrix<T>& other)
	{
		if (*this != other)
		{
			columnCount = other.GetColumnCount();
			rowCount = other.GetRowCount();
			matrix = new Cell<T>*[columnCount];
			for (int c = 0; c < columnCount; c++)
			{
				matrix[c] = new Cell<T>[rowCount];
				for (int r = 0; r < rowCount; r++)
				{
					matrix[c][r] = other.GetCell(c,r);
				}
			}
		}
	}

	template <class T>
	void Matrix<T>::Display()
	{
		int columns{ columnCount };
		columns += 1;
		columns *= 6;
		std::cout << std::string(columns, '-') << std::endl;
		std::cout << "   ";
		for (int i = 0; i < columnCount; i++)
		{
			std::cout << "  |  " << (char)(i + 65);
		}
		std::cout << "  |" << std::endl;

		std::cout << std::string(columns, '-') << std::endl;
		for (int r = 0; r < rowCount; r++)
		{
			std::cout << "  " << r + 1 << "  |";
			for (int c = 0; c < columnCount; c++)
			{
				std::cout << "  " << GetCell(c, r) << "  |";
			}
			std::cout << std::endl;
			std::cout << std::string(columns, '-') << std::endl;
		}
	}

	template <class T>
	int Matrix<T>::GetColumnCount() const
	{
		return columnCount;
	}

	template <class T>
	int Matrix<T>::GetRowCount() const
	{
		return rowCount;
	}

	template <class T>
	Cell<T> Matrix<T>::GetCell(const int& c, const int& r) const
	{
		if (c < 0 || c > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max row is " + std::to_string(columnCount));
		}

		if (r < 0 || r > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max column is " + std::to_string(rowCount));
		}

		Cell<T> returnCell{ matrix[c][r] };
		return returnCell;
	}

	template <class T>
	Cell<T> Matrix<T>::GetCell(const std::string& cellAddress) const
	{
		CellAddress test{ cellAddress };
		if (test.GetColumn() < 0 || (test.GetColumn() + 1) > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (test.GetRow() < 0 || (test.GetRow() + 1) > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		int testC = test.GetColumn();
		int testR = test.GetRow();
		Cell<T> returnCell{ matrix[test.GetColumn()][test.GetRow()] };
		return returnCell;
	}

	template <class T>
	T Matrix<T>::GetCellContents(const std::string& cellAddress) const
	{
		CellAddress test{ cellAddress };
		if (test.GetColumn() < 0 || test.GetColumn() > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (test.GetRow() < 0 || test.GetRow() > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		Cell<T> c = matrix[test.GetColumn()][test.GetRow()];
		T contents = c.GetContents();
		return contents;
	}

	template <class T>
	T Matrix<T>::GetCellContents(const int& c, const int& r) const
	{
		if (c < 0 || c > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (r < 0 || r > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}

		Cell<T> c = matrix[c][r];
		T contents = c.GetContents();
		return contents;
	}

	template <class T>
	void Matrix<T>::SetCell(const std::string& cellAddress, const Cell<T>& newCell)
	{
		try
		{
			CellAddress test{ cellAddress };
			if (test.GetColumn() < 0 || test.GetColumn() > columnCount)
			{
				throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
			}
			if (test.GetRow() < 0 || test.GetRow() > rowCount)
			{
				throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
			}
			matrix[test.GetColumn()][test.GetRow()] = newCell;
		}
		catch (std::exception e)
		{
			throw;
		}
	}

	template <class T>
	void Matrix<T>::SetCell(const int& c, const int& r, const Cell<T>& newCell)
	{
		if (c < 0 || c > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (r < 0 || r > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		Cell<T> currentCell{ matrix[c][r] };
		matrix[c][r] = newCell;
	}

	template <class T>
	void Matrix<T>::SetCellIsEmpty(const std::string& cellAddress, const bool& b)
	{
		CellAddress test{ cellAddress };
		if (test.GetColumn() < 0 || test.GetColumn() > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (test.GetRow() < 0 || test.GetRow() > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		ADT::Cell<T>* current = matrix[test.GetColumn()][test.GetRow()];
		current->SetEmpty(b);
	}

	template <class T>
	void Matrix<T>::SetCellIsEmpty(const int& c, const int& r, const bool& b)
	{
		if (c < 0 || c > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (r < 0 || r > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		ADT::Cell<T>* current = &(matrix[c][r]);
		current->SetEmpty(b);
	}

	template <class T>
	void Matrix<T>::SetCellContents(const std::string& cellAddress, const T& newContents)
	{
		CellAddress test{ cellAddress };
		if (test.GetColumn() < 0 || test.GetColumn() > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (test.GetRow() < 0 || test.GetRow() > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		Cell<T>* current = &(matrix[test.GetColumn()][test.GetRow()]);
		current->SetContents(newContents);
	}

	template <class T>
	void Matrix<T>::SetCellContents(const int& c, const int& r, const T& newContents)
	{
		if (c < 0 || c > columnCount)
		{
			throw std::ColumnOutOfBounds("Column Error: The max column is " + std::to_string(columnCount));
		}
		if (r < 0 || r > rowCount)
		{
			throw std::RowOutOfBounds("Row Error: The max row is " + std::to_string(rowCount));
		}
		Cell<T>* current = &matrix[c][r];
		current->SetContents(newContents);
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
				throw std::BadAddressString();
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
			deleteMatrix();
			this->rowCount = other.GetRowCount();
			this->columnCount = other.GetColumnCount();
			matrix = new Cell<T>*[columnCount];
			for (int c = 0; c < columnCount; c++)
			{
				matrix[c] = new Cell<T>[rowCount];
				for (int r = 0; r < rowCount; r++)
				{
					matrix[c][r] = other.GetCell(c,r);
				}
			}
		}
		return *this;
	}

	template <class T>
	Matrix<T> Matrix<T>::operator=(const Cell<T>& other)
	{

	}
	template <class T>
	bool Matrix<T>::operator==(const Matrix<T>& other)
	{
		if (rowCount != other.rowCount || columnCount != other.columnCount)
		{
			return false;
		}

		for (int r = 0; r < rowCount; r++)
		{
			for (int c = 0; c < columnCount; c++)
			{
				try
				{
					Cell<T> thisCell{ matrix[c][r] };
					Cell<T> otherCell{ other.matrix[c][r] };
					if (thisCell.GetContents() != otherCell.GetContents())
					{
						return false;
					}
				}
				catch (const std::exception& e)
				{
					throw;
				}
			}
		}
		return true;
	}

	template <class T>
	bool Matrix<T>::operator!=(const Matrix<T>& other)
	{
		if (rowCount != other.rowCount || columnCount != other.columnCount)
		{
			return true;
		}

		for (int c = 0; c < columnCount; c++)
		{
			for (int r = 0; r < rowCount; r++)
			{
				try
				{
					Cell<T> temp1{ matrix[c][r] };
					Cell<T> temp2{ other.matrix[c][r] };
					if (temp1.GetContents() != temp2.GetContents())
					{
						return true;
					}
				}
				catch (const std::exception& e)
				{
					throw;
				}

			}
		}
		return false;
	}

	template <class T>
	void Matrix<T>::deleteMatrix()
	{
		for (int row = columnCount - 1; row >= 0; row--)
		{
			delete[] matrix[row];

		}
		delete[] matrix;
		columnCount = 0;
		rowCount = 0;
	}

	template <class T>
	Matrix<T>::~Matrix()
	{
		if (rowCount > 0)
		{
			deleteMatrix();
		}
	}
}


#endif //MATRIX_H