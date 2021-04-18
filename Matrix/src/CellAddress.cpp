#include "CellAddress.h"
CellAddress::CellAddress()
{
	row = -1;
	column = -1;
	address = "";
}

CellAddress::CellAddress(int r, int c)
{
	row = r;
	column = c;
}

CellAddress::CellAddress(CellAddress& other)
{
	row = other.row;
	column = other.column;
	address = other.address;
}

int CellAddress::GetRow()
{
	return row;
}
int CellAddress::GetColumn()
{
	return column;
}

std::string CellAddress::GetAddress()
{
	if (row == -1 || column == -1)
	{
		return "";
	}
	else
	{
		std::string a = "";
		a += std::to_string(row);
		a += std::to_string(column);
		return a;
	}
}

void CellAddress::SetRow(int newRow)
{
	if (newRow >= 0)
	{
		row = newRow;
	}
}

void CellAddress::SetColumn(int newColumn)
{
	if (newColumn >= 0)
	{
		column = newColumn;
	}
}

int CellAddress::calculateAddressValue(std::string value)
{
	return -1;
}

std::string CellAddress::calculateAddressValue(int value)
{
	std::string s = "";
	//value += 65; //A=65 in ANSI and we want to start at the beginning of the alphabet
	if (value <= 25 && value >= 0)
	{
		char c = (value + 65);
		s.push_back(c);
		return s;
	}
	//if value is greater than 27 then the address will be multiple letters AA, BA, GF, etc.
	else if (value <= 51 && value >= 26)
	{
		while (value > 25)
		{
			value -= 26;
			s.push_back('A');
		}
		char c = (value + 65);
		s.push_back(c);
		return s;
	}
	else
	{
		char f = ((value / 26) - 1) + 65;
		char s = ((value % 26)) + 65;
		std::string str;
		str.push_back(f);
		str.push_back(s);
		return str;
	}
}