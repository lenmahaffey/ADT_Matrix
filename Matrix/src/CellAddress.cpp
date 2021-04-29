#include "CellAddress.h"
CellAddress::CellAddress()
{
	row = -1;
	column = -1;
	address = "";
}

CellAddress::CellAddress(std::string a)
{
	if (a.length() > 0 && a.length() < 3)
	{
		int c, r;

		std::string temp;
		temp.push_back(a[0]);
		c = CalculateIntForAddressString(temp);

		r = a[1] - '0';
		column = c;
		row = r - 1;
	}
	else
	{
		throw Exceptions::BadAddressString();
	}
}

CellAddress::CellAddress(int c, int r)
{
	if (c > 700 || c < 0)
	{
		throw Exceptions::HeightOutOfBounds();
	}
	if (r > 700 || c < 0)
	{
		throw Exceptions::LengthOutOfBounds();
	}
	row = r;
	column = c;
	address = GetAddressString();
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

std::string CellAddress::GetAddressString()
{
	if (row == -1 || column == -1)
	{
		return "";
	}
	else
	{
		std::string a = "";
		a += CalculateAddressStringForInt(column);
		a += std::to_string(row + 1);
		return a;
	}
}

void CellAddress::SetRow(int newRow)
{
	if (newRow >= 0 && newRow < 701)
	{
		row = newRow;
	}
	else
	{
		throw Exceptions::LengthOutOfBounds();
	}
}

void CellAddress::SetColumn(int newColumn)
{
	if (newColumn >= 0 && newColumn < 701)
	{
		column = newColumn;
	}
	else
	{
		throw Exceptions::HeightOutOfBounds();
	}
}

int CellAddress::CalculateIntForAddressString(std::string value)
{
	int total = 0;
	total += (value[value.length() - 1]) - 65;
	if (value.length() >= 2)
	{
		int subTotal = (value[0] + 1) - 65;
		subTotal *= 26;
		for (int i = 1; i < (int)value.length() - 1; i++)
		{
			int temp = 1;
			temp = (value[i] + 1) - 65;
			temp *= 26;
			temp *= subTotal;
			subTotal += temp;
		}
		total += subTotal;
	}
	return total;
}

std::string CellAddress::CalculateAddressStringForInt(int value)
{
	std::string s = "";
	int calcValue = value / 26;

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
		while (value < 25)
		{
			value -= 25;
			s.push_back('A');
		}
		char f = ((value / 26) - 1) + 65;
		char s = ((value % 26)) + 65;
		std::string str;
		str.push_back(f);
		str.push_back(s);
		return str;
	}
}

CellAddress CellAddress::operator =(const CellAddress& otherAddress)
{
	if (this != &otherAddress)
	{
		this->row = otherAddress.row;
		this->column = otherAddress.column;
	}
	return *this;
}

CellAddress CellAddress::operator =(const std::string& a)
{
	if (a.length() > 0 && a.length() < 3)
	{
		int c, r;

		std::string temp;
		temp.push_back(a[0]);
		c = CalculateIntForAddressString(temp);

		r = a[1] - '0';
		column = c;
		row = r - 1;
	}
	else
	{
		throw Exceptions::BadAddressString();
	}
	return *this;
}

bool CellAddress::operator ==(const CellAddress& a) const
{
	return (this->row == a.row && this->column == a.column);
}

bool CellAddress::operator !=(const CellAddress& a) const
{
	return (this->row != a.row || this->column != a.column);
}