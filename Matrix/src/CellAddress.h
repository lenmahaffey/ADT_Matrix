#pragma once
#include <string>

class CellAddress
{
public:
	CellAddress();
	CellAddress(int row, int column);
	CellAddress(CellAddress& other);
	int GetRow();
	int GetColumn();
	std::string GetAddress();
	void SetRow(int newRow);
	void SetColumn(int newColumn);
	int calculateAddressValue(std::string address);
	std::string calculateAddressValue(int value);

private:
	int row;
	int column;
	std::string address;

};

