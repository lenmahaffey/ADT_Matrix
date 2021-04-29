#ifndef CELL_H
#define CELL_H

#include <string>
#include <iostream>
#include "CellAddress.h"

template <class T>
class Cell
{
public:
	Cell();
	Cell(std::string addressString);
	Cell(std::string addressString, T contents);
	bool IsEmpty() const;
	std::string GetName();
	CellAddress GetCellAddress();
	std::string GetCellAddressString();
	T GetContents();
	void SetName(const std::string& newName);
	void SetAddress(const CellAddress& newAddress);
	void SetAddress(const std::string& newAddress);
	void SetContents(const T& newContents);

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
Cell<T>::Cell(std::string addressString) :
	contents{}, name{ addressString }, cellAddress{ CellAddress{ addressString } }, isEmpty{ true }
{
}

template <class T>
Cell<T>::Cell(std::string addressString, T contents) :
	contents{ contents }, name{ addressString }, cellAddress{ CellAddress{ addressString } }, isEmpty{ false }
{
}

template <class T>
bool Cell<T>::IsEmpty() const
{
	return isEmpty;
}

template <class T>
std::string Cell<T>::GetName()
{
	return name;
}
template <class T>
CellAddress Cell<T>::GetCellAddress()
{
	return cellAddress;
}

template <class T>
std::string Cell<T>::GetCellAddressString()
{
	return cellAddress.GetAddressString();
}

template <class T>
T Cell<T>::GetContents()
{
	return contents;
}

template <class T>
void Cell<T>::SetName(const std::string& newName)
{
	name = newName;
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
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Cell<T>& a)
{
	os << a.contents;
	return os;
}
#endif //CELL_H