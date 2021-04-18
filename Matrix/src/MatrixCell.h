#pragma once
#include <string>
#include <iostream>
#include "CellAddress.h"

template <class T>
class MatrixCell
{
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const MatrixCell<T>& a);

public:
	MatrixCell();
	T GetContents();
	std::string GetName();
	CellAddress GetAddress();
	void SetAddress(CellAddress newAddress);
	void SetName(std::string& newName);
	void SetContents(T& newContents);
	~MatrixCell();

private:
	T contents;
	CellAddress address;
	std::string name;

};

template <class T>
MatrixCell<T>::MatrixCell() :
	contents{},
	name{""},
	address{}
{

}

template <class T>
T MatrixCell<T>::GetContents()
{
	return contents;
}

template <class T>
std::string MatrixCell<T>::GetName()
{
	return name;
}
template <class T>
CellAddress MatrixCell<T>::GetAddress()
{
	return address;
}

template <class T>
void MatrixCell<T>::SetAddress(CellAddress newAddress)
{
	address = newAddress;
}

template <class T>
void MatrixCell<T>::SetName(std::string& newName)
{
	name = newName;
}

template <class T>
void MatrixCell<T>::SetContents(T& newContent)
{
	contents = newContent;
}

template <class T>
MatrixCell<T>::~MatrixCell()
{

}
template<class T>
std::ostream& operator<<(std::ostream& os, const MatrixCell<T>& a)
{
	os << a.contents;
	return os;
}