#ifndef MATRIXCELL_H
#define MATRIXCELL_H

#include <string>
#include <iostream>
#include "CellAddress.h"

template <class T>
class Cell
{
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const Cell<T>& a);

public:
	Cell();
	T GetContents();
	std::string GetName();
	CellAddress GetAddress();
	void SetAddress(CellAddress newAddress);
	void SetName(std::string& newName);
	void SetContents(T& newContents);
	~Cell();

private:
	T contents;
	CellAddress address;
	std::string name;

};

template <class T>
Cell<T>::Cell() :
	contents{},
	name{""},
	address{}
{

}

template <class T>
T Cell<T>::GetContents()
{
	return contents;
}

template <class T>
std::string Cell<T>::GetName()
{
	return name;
}
template <class T>
CellAddress Cell<T>::GetAddress()
{
	return address;
}

template <class T>
void Cell<T>::SetAddress(CellAddress newAddress)
{
	address = newAddress;
}

template <class T>
void Cell<T>::SetName(std::string& newName)
{
	name = newName;
}

template <class T>
void Cell<T>::SetContents(T& newContent)
{
	contents = newContent;
}

template <class T>
Cell<T>::~Cell()
{

}
template<class T>
std::ostream& operator<<(std::ostream& os, const Cell<T>& a)
{
	os << a.contents;
	return os;
}
#endif //MATRIXCELL_H