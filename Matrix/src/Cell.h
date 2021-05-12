#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>
#include "CellAddress.h"

namespace ADT
{
	template <class T>
	class Cell
	{
	public:
		Cell();
		Cell(const T& contents);
		Cell(const CellAddress& cellAddress);
		Cell(const CellAddress& cellAddress, const T& contents);
		Cell(const int& c, const int& r);
		Cell(const int& c, const int& r, const T& contents);
		Cell(const std::string& addressString);
		Cell(const std::string& addressString, const T& contents);
		Cell(const Cell<T>& otherCell);
		bool IsEmpty() const;
		std::string GetName() const;
		CellAddress GetCellAddress() const;
		std::string GetCellAddressString() const;
		T GetContents() const;
		void SetAddress(const CellAddress& newAddress);
		void SetAddress(const std::string& newAddress);
		void SetContents(const T& newContents);
		void SetEmpty(const bool& v);

		Cell<T> operator=(const Cell<T>& othercell);
		bool operator==(const Cell<T>& othercell);
		bool operator!=(const Cell<T>& othercell);

		template <class T>
		friend std::ostream& operator<<(std::ostream& os, const Cell<T>& a);

	private:
		T contents;
		CellAddress cellAddress;
		std::string name;
		bool isEmpty;
	};

	template <class T>
	Cell<T>::Cell() :
		contents{}, name{ "" }, cellAddress{}, isEmpty{ true }
	{
	}

	template <class T>
	Cell<T>::Cell(const int& c, const int& r) :
		contents{}, name{ "" }, cellAddress{ c,r }, isEmpty{ true }
	{
		name = cellAddress.GetAddressString();
	}

	template <class T>
	Cell<T>::Cell(const int& c, const int& r, const T& contents) :
		contents{ contents }, name{ "" }, cellAddress{ c,r }, isEmpty{ false }
	{
		name = cellAddress.GetAddressString();
	}

	template <class T>
	Cell<T>::Cell(const T& contents) :
		contents{ contents }, name{ "" }, cellAddress{}, isEmpty{ false }
	{
	}

	template <class T>
	Cell<T>::Cell(const std::string& addressString) :
		contents{}, name{ addressString }, cellAddress{ CellAddress{ addressString } }, isEmpty{ true }
	{
	}

	template <class T>
	Cell<T>::Cell(const std::string& addressString, const T& contents) :
		contents{ contents }, name{ addressString }, cellAddress{ CellAddress{ addressString } }, isEmpty{ false }
	{
	}

	template <class T>
	Cell<T>::Cell(const Cell<T>& o) :
		contents{ o.contents }, name{ o.name }, cellAddress{ o.cellAddress }, isEmpty{ o.isEmpty }
	{
	}
	template <class T>
	bool Cell<T>::IsEmpty() const
	{
		return isEmpty;
	}

	template <class T>
	std::string Cell<T>::GetName() const
	{
		return cellAddress.GetAddressString();
	}
	template <class T>
	CellAddress Cell<T>::GetCellAddress() const
	{
		return cellAddress;
	}

	template <class T>
	std::string Cell<T>::GetCellAddressString() const
	{
		return cellAddress.GetAddressString();
	}

	template <class T>
	T Cell<T>::GetContents() const
	{
		return contents;
	}

	template <class T>
	void Cell<T>::SetAddress(const CellAddress& newAddress)
	{
		cellAddress = newAddress;
	}

	template <class T>
	void Cell<T>::SetAddress(const std::string& newAddress)
	{
		cellAddress = newAddress;
	}


	template <class T>
	void Cell<T>::SetContents(const T& newContent)
	{
		contents = newContent;
		isEmpty = false;
	}

	template<class T>
	void Cell<T>::SetEmpty(const bool& v)
	{
		isEmpty = v;
	}

	template<class T>
	std::ostream& operator<<(std::ostream& os, const Cell<T>& a)
	{
		os << a.contents;
		return os;
	}

	template <class T>
	Cell<T> Cell<T>::operator=(const Cell<T>& otherCell) {
		if (*this != otherCell)
		{
			this->SetAddress(otherCell.GetCellAddress());
			this->SetContents(otherCell.GetContents());
			this->SetEmpty(otherCell.IsEmpty());
		}
		return *this;
	}

	template <class T>
	bool Cell<T>::operator==(const Cell<T>& otherCell)
	{
		if ((this->GetCellAddressString() == otherCell.GetCellAddressString()) &&
			(this->GetContents() == otherCell.GetContents()))
		{
			return true;
		}
		return false;
	}

	template <class T>
	bool Cell<T>::operator!=(const Cell<T>& otherCell)
	{
		try
		{
			CellAddress thisCellAddress{ this->GetCellAddress() };
			CellAddress otherCellAddress{ otherCell.GetCellAddress() };
			if ((thisCellAddress.GetRow() != otherCellAddress.GetRow()) ||
				(thisCellAddress.GetColumn() != otherCellAddress.GetColumn()) ||
				(this->GetContents() != otherCell.GetContents()))
			{
				return true;
			}
			return false;
		}
		catch (std::exception e)
		{
			return false;
		}
	}
}

#endif //CELL_H