#include "CppUnitTest.h"
#include "../Matrix/src/Cell.h"

using namespace std;
using namespace Exceptions;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTesting
{
	TEST_CLASS(Cell_Test)
	{
		TEST_METHOD(Constructor_HasNoName)
		{
			//arrange
			Cell<int> testCell{};
			string expected = "";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasCellAddressObj)
		{
			//arrange
			Cell<int> testCell{};
			CellAddress expected{};

			//act
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(Constructor_HasAddressObjWithNoAddressString)
		{
			//arrange
			Cell<int> testCell{};
			string expected{ "" };

			//act
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasNoContents)
		{
			//arrange
			Cell<int> testCell{};
			int expected{};

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_IsEmpty)
		{
			//arrange
			Cell<int> testCell{};
			bool expected = true;

			//act
			bool actual = testCell.IsEmpty();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddress_HasAddressObj)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			CellAddress expected{};

			//act
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddress_HasAddressObjWithCorrectAddressString)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			string expected{"B3"};

			//act
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddress_HasNameString)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			string expected = "B3";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddress_HasCorrectNameString)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			string expected = "B3";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddress_HasNoContents)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			int expected{};

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddress_IsEmpty)
		{
			//arrange
			Cell<int> testCell{ "B3" };
			bool expected = true;

			//act
			bool actual = testCell.IsEmpty();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithContents_HasNoName)
		{
			//arrange
			Cell<int> testCell{ 5 };
			string expected = "";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithContents_HasAddressObj)
		{
			//arrange
			Cell<int> testCell{ 5 };
			CellAddress expected{};

			//act
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithContents_HasAddressObjWithEmptyAddressString)
		{
			//arrange
			Cell<int> testCell{ 5 };
			string expected{};

			//act
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithContents_HasContentsType)
		{
			//arrange
			Cell<int> testCell{ 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithContents_HasCorrectContents)
		{
			//arrange
			Cell<int> testCell{ 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithContents_IsNotEmpty)
		{
			//arrange
			Cell<int> testCell{ 5 };
			bool expected = false;

			//act
			bool actual = testCell.IsEmpty();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasName)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			string expected = "B3";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasCorrectName)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			string expected = "B3";

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasAddressObj)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			CellAddress expected{ "B3" };

			//act
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasAddressObjWithCorrectAddressString)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			string expected{ "B3" };

			//act
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasContents)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddressAndContents_HasCorrectContents)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressAndContents_IsNotEmpty)
		{
			//arrange
			Cell<int> testCell{ "B3", 5 };
			bool expected = false;

			//act
			bool actual = testCell.IsEmpty();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ReturnsAString)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			string expected{ "C4" };

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetName_ReturnsCorrectString)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			string expected{ "C4" };

			//act
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetAddress_ReturnsACellAddress)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			CellAddress expected{ "C4" };

			//act
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetAddress_ReturnsCorrectCellAddress)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			string expected{ "C4" };

			//act
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetAddressString_ReturnsACellAddress)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			string expected{ "C4" };

			//act
			string actual = testCell.GetCellAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetAddressString_ReturnsCorrectCellAddress)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			string expected{ "C4" };

			//act
			string actual = testCell.GetCellAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetContents_ReturnsContents)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetContents_ReturnsCorrectContents)
		{
			//arrange
			Cell<int> testCell{ "C4", 5 };
			int expected{ 5 };

			//act
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetName_SetsCorrectly)
		{
			//arrange
			Cell<int> testCell{};
			string expected{"B4"};

			//act
			testCell.SetName("B4");
			string actual = testCell.GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetCellAddressWithCellAddress_SetsCorrectly)
		{
			//arrange
			Cell<int> testCell{};
			CellAddress expected{ "D3" };

			//act
			CellAddress newAddress{ "D3" };
			testCell.SetAddress(newAddress);
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(SetCellAddressWithCellAddress_SetsCorrectAddress)
		{
			//arrange
			Cell<int> testCell{};
			string expected{ "D3" };

			//act
			CellAddress newAddress{ "D3" };
			testCell.SetAddress(newAddress);
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetCellAddressWithString_SetsCorrectly)
		{
			//arrange
			Cell<int> testCell{};
			CellAddress expected{ "D3" };

			//act
			testCell.SetAddress("D3");
			CellAddress actual = testCell.GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(SetCellAddressWithString_SetsCorrectAddress)
		{
			//arrange
			Cell<int> testCell{};
			string expected{ "D3" };

			//act
			testCell.SetAddress("D3");
			string actual = testCell.GetCellAddress().GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetContents_SetsCorrectly)
		{
			//arrange
			Cell<int> testCell{};
			int expected{ 42 };

			//act
			int newContents{ 42 };
			testCell.SetContents(newContents);
			int actual = testCell.GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}
	};
}