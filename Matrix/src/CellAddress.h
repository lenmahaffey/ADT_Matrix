#ifndef CELLADDRESS_H
#define CELLADDRESS_H

#include <string>
#include "MatrixExceptions.h"

class CellAddress
{
public:
	CellAddress();
	CellAddress(std::string address);
	CellAddress(int column, int row);
	CellAddress(CellAddress& other);
	int GetRow();
	int GetColumn();
	std::string GetAddressString();
	void SetRow(int newRow);
	void SetColumn(int newColumn);
	static int CalculateIntForAddressString(std::string address);
	static std::string CalculateAddressStringForInt(int value);

	CellAddress operator =(const CellAddress& otherAddress);
	CellAddress operator =(const std::string& addressString);
	bool operator ==(const CellAddress& otherAddress) const;
	bool operator !=(const CellAddress& otherAddress) const;

private:
	int row;
	int column;
	std::string address;
};


#endif // CELLADDRESS_H