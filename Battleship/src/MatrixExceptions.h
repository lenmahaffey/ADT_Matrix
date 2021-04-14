#include <exception>
#include <string>

#pragma once
namespace Battleship
{
	class MatrixLengthOutOfBounds : public std::exception
	{
	public:
		MatrixLengthOutOfBounds()
		{
			message = "The length is out of bounds";
		}
		MatrixLengthOutOfBounds(std::string s)
		{
			message = s;
		}
		std::string what()
		{
			return message;
		}
	private:
		std::string message;
	};

	class MatrixHeightOutOfBounds : public std::exception
	{
	public:
		MatrixHeightOutOfBounds()
		{
			message = "The length is out of bounds";
		}
		MatrixHeightOutOfBounds(std::string s)
		{
			message = s;
		}
		std::string what()
		{
			return message;
		}
	private:
		std::string message;
	};
}


