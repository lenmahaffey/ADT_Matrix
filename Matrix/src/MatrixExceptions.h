#include <exception>
#include <string>

#pragma once
namespace Exceptions
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

	class LengthOutOfBounds : public MatrixException
	{
	public:
		LengthOutOfBounds()
		{
			message = "The maximum length is 700";
		}
		LengthOutOfBounds(std::string s)
		{
			message = s;
		}
	};

	class HeightOutOfBounds : public MatrixException
	{
	public:
		HeightOutOfBounds()
		{
			message = "The maximum height is 700";
		}
		HeightOutOfBounds(std::string s)
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
}


