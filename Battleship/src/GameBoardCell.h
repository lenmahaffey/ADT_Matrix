#pragma once
#include <string>
#include <iostream>

namespace Battleship
{
	template <class T>
	class GameBoardCell
	{
	private:
		T contents;
		std::string name;

	public:
		GameBoardCell<T>();
		T GetContents();
		std::string GetName();
		void SetName(const std::string& newName);
		void SetContents(const T& newContents);
		~GameBoardCell();
	};

	template <class T>
	GameBoardCell<T>::GameBoardCell<T>()
	{

	}

	template <class T>
	T GameBoardCell<T>::GetContents()
	{
		return contents;
	}

	template <class T>
	std::string GameBoardCell<T>::GetName()
	{
		return name;
	}

	template <class T>
	void GameBoardCell<T>::SetName(const std::string& newName)
	{
		name = newName;
	}

	template <class T>
	void GameBoardCell<T>::SetContents(const T& newContent)
	{
		contents = newContent;
	}

	template <class T>
	GameBoardCell<T>::~GameBoardCell()
	{

	}
}
