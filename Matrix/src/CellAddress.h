#ifndef CELLADDRESS_H
#define CELLADDRESS_H

#include <string>
#include "MatrixExceptions.h"

namespace ADT
{
	class CellAddress
	{
	public:
		CellAddress();
		CellAddress(std::string address);
		CellAddress(int column, int row);
		CellAddress(const CellAddress& other);
		int GetRow() const;
		int GetColumn() const;
		std::string GetAddressString() const;
		void SetRow(const int& newRow);
		void SetColumn(const int& newColumn);
		static int CalculateIntForAddressString(const std::string& address);
		static std::string CalculateAddressStringForInt(const int& value);

		CellAddress operator =(const CellAddress& otherAddress);
		CellAddress operator =(const std::string& addressString);
		bool operator ==(const CellAddress& otherAddress) const;
		bool operator !=(const CellAddress& otherAddress) const;

	private:
		int row;
		int column;
		std::string address;
	};
}

#endif // CELLADDRESS_H