#include "CellAddress.h"
ADT::CellAddress::CellAddress() :
	row{ -1 }, column{ -1 }, addressString{ "" }
{
}

ADT::CellAddress::CellAddress(const std::string& a)
{
	std::string tempC{};
	std::string tempR{};

	for (int i = 0; i < (int)a.length(); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			tempC.push_back(a[i]);
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			tempR.push_back(a[i]);
		}
		else
		{
			throw std::BadAddressString();
		}
	}
	int c = CellAddress::CalculateIntForAddressString(tempC);
	int r = stoi(tempR) - 1;
	column = c;
	row = r;
	addressString = a;
}

ADT::CellAddress::CellAddress(const int& c, const int& r)
{
	row = r;
	column = c;
	std::string n = "";
	n += CalculateAddressStringForInt(c);
	n += std::to_string(r + 1);
	addressString = n;
}

ADT::CellAddress::CellAddress(const CellAddress& other)
{
	if (*this != other)
	{
		row = other.row;
		column = other.column;
		addressString = other.addressString;
	}
}

int ADT::CellAddress::GetRow() const
{
	return row;
}

int ADT::CellAddress::GetColumn() const
{
	return column;
}

std::string ADT::CellAddress::GetAddressString() const
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

void ADT::CellAddress::SetRow(const int& newRow)
{
	row = newRow;
}

void ADT::CellAddress::SetColumn(const int& newColumn)
{
	column = newColumn;
}

int ADT::CellAddress::CalculateIntForAddressString(const std::string& v)
{
	std::string value{ v };
	int total{ 0 };
	int subTotal{ 0 };
	int loopCount{ 0 };

	if (value.length() == 1)
	{
		total += (v[0] - 'A');
		return total;
	}
	else if (value.length() == 2)
	{
		total += (v[0] - 'A');
		subTotal += ((total + 1) * 26);
		for (int i = 1; i < value.length(); i++)
		{
			subTotal += (v[i] - 'A') + 1;
			total = subTotal;
			total -= 1;
		}
	}
	else if (value.length() == 3)
	{
		total += (v[0] - 'A');
		for (int i = 1; i < value.length(); i++)
		{
			subTotal += ((v[i] - 'A') + 1) * 26;
		}
		total += subTotal;
	}
	return total;
}

std::string ADT::CellAddress::CalculateAddressStringForInt(const int& v)
{
	int value{ v };
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

ADT::CellAddress ADT::CellAddress::operator =(const ADT::CellAddress& otherAddress)
{
	if (this != &otherAddress)
	{
		this->SetRow(otherAddress.row);
		this->SetColumn(otherAddress.column);
		this->addressString = otherAddress.GetAddressString();
	}
	return *this;
}

ADT::CellAddress ADT::CellAddress::operator =(const std::string& a)
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
		throw std::BadAddressString();
	}
	return *this;
}

bool ADT::CellAddress::operator ==(const CellAddress& a) const
{
	return (this->row == a.row && this->column == a.column);
}

bool ADT::CellAddress::operator !=(const CellAddress& a) const
{
	return (this->row != a.row || this->column != a.column);
}