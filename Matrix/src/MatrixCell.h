#pragma once
#include <string>
#include <iostream>

template <class T>
class MatrixCell
{
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const MatrixCell<T>& a);
private:
	T contents;
	std::string name;

public:
	MatrixCell<T>();
	T GetContents();
	std::string GetName();
	void SetName(const std::string& newName);
	void SetContents(const T& newContents);
	~MatrixCell();
};

template <class T>
MatrixCell<T>::MatrixCell() :
	contents{},
	name{""}
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
void MatrixCell<T>::SetName(const std::string& newName)
{
	name = newName;
}

template <class T>
void MatrixCell<T>::SetContents(const T& newContent)
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