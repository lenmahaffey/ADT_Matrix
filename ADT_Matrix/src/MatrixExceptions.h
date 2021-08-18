#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace std
{
	class MatrixException : std::exception
	{
	public:
		MatrixException()
		{
			message = "Undefined Matrix Exception";
		}

		MatrixException(std::string s)
		{
			message = s;
		}

		std::string what()
		{
			return message;
		}

	protected:
		std::string message;
	};

	class ColumnOutOfBounds : public MatrixException
	{
	public:
		ColumnOutOfBounds()
		{
			message = "Column Error: out of bounds (probably)";
		}
		ColumnOutOfBounds(std::string s)
		{
			message = s;
		}
	};

	class RowOutOfBounds : public MatrixException
	{
	public:
		RowOutOfBounds()
		{
			message = "Row Error: out of bounds (probably)";;
		}
		RowOutOfBounds(std::string s)
		{
			message = s;
		}
	};

	class BadAddressString : public MatrixException
	{
	public:
		BadAddressString()
		{
			message = "The address string entered is invalid";
		}
		BadAddressString(std::string s)
		{
			message = s;
		}
	};

	class CellAddressOutOfRange : public MatrixException
	{
	public:
		CellAddressOutOfRange()
		{
			message = "The address entered is out of range";
		}
		CellAddressOutOfRange(std::string s)
		{
			message = s;
		}
	};

	class CellContentsFull : public MatrixException
	{
	public:
		CellContentsFull()
		{
			message = "The cell contents are full or unwritable";
		}
		CellContentsFull(std::string s)
		{
			message = s;
		}
	};
}
#endif // !EXCEPTIONS_H
