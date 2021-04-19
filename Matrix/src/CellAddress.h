#pragma once
#include <string>
#include "MatrixExceptions.h"

class CellAddress
{
public:
	CellAddress();
	CellAddress(int column, int row);
	CellAddress(CellAddress& other);
	int GetRow();
	int GetColumn();
	std::string GetAddress();
	void SetRow(int newRow);
	void SetColumn(int newColumn);
	static int calculateIntForAddressString(std::string address);
	static std::string calculateAddressStringForInt(int value);

private:
	int row;
	int column;
	std::string address;
};

