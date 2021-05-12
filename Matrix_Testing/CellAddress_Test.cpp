#include "CppUnitTest.h"
#include "../Matrix/src/CellAddress.h"
#include "../Matrix/src/CellAddress.cpp"
#include "../Matrix/src/MatrixExceptions.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ADT;
namespace MatrixTesting
{
	TEST_CLASS(CellAddress_Test)
	{
		TEST_METHOD(Constructor_HasNegativeRow)
		{
			//arrange
			CellAddress test;
			int expected{ -1 };

			//act
			int actual = test.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasNegativeColumn)
		{

			//arrange
			CellAddress test;
			int expected{ -1 };

			//act
			int actual = test.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasNoAddress)
		{
			//arrange
			CellAddress test;
			string expected{ "" };

			//act
			string actual = test.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressString_HasCorrectRow)
		{
			//arrange
			CellAddress test{"A1"};
			int expected{ 0 };

			//act
			int actual = test.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressString_HasCorrectColumn)
		{

			//arrange
			CellAddress test{ "A1" };
			int expected{ 0 };

			//act
			int actual = test.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithAddressString_HasAddress)
		{
			//arrange
			CellAddress test{ "A1" };
			string expected{ "A1" };

			//act
			string actual = test.GetAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithAddressString_HasCorrectAddress)
		{
			//arrange
			CellAddress test{ "A1" };
			string expected{ "A1" };

			//act
			string actual = test.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithInts_HasCorrectRow)
		{
			//arrange
			CellAddress test{ 0, 0 };
			int expected{ 0 };

			//act
			int actual = test.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithInts_HasCorrectColumn)
		{
			//arrange
			CellAddress test{ 0, 0 };
			int expected{ 0 };

			//act
			int actual = test.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ConstructorWithInts_HasAddress)
		{
			//arrange
			CellAddress test{ 0, 0 };
			string expected{ "A1" };

			//act
			string actual = test.GetAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(ConstructorWithInts_HasCorrectAddress)
		{
			//arrange
			CellAddress test{ 0, 0 };
			string expected{ "A1" };

			//act
			string actual = test.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_HasCorrectRow)
		{
			//arrange
			CellAddress cell{ "B2" };
			int expected{ 1 };

			//act
			CellAddress testCell = cell;
			int actual = testCell.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_HasCorrectColumn)
		{

			//arrange
			CellAddress cell{ "D5" };
			int expected{ 3 };

			//act
			CellAddress testCell = cell;
			int actual = testCell.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_HasAddress)
		{
			//arrange
			CellAddress cell{ "B5" };
			string expected{ "B5" };

			//act
			CellAddress testCell = cell;
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(CopyConstructor_HasCorrectAddress)
		{
			//arrange
			CellAddress cell1{ "B2" };
			string expected{ "B2" };

			//act
			CellAddress testCell = cell1;
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetRow_ReturnsAnInt)
		{
			//Arrange
			CellAddress testCell{ "B4" };
			int expected{ 3 };

			//Act
			int actual = testCell.GetRow();

			//Assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetRow_ReturnsCorrectInt)
		{
			//Arrange
			CellAddress testCell{ "C7" };
			int expected{ 6 };

			//Act
			int actual = testCell.GetRow();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetColumn_ReturnsAnInt)
		{
			//Arrange
			CellAddress testCell{ "C1" };
			int expected{ 2 };

			//Act
			int actual = testCell.GetColumn();

			//Assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetColumn_ReturnsCorrectInt)
		{
			//Arrange
			CellAddress testCell{ "B1" };
			int expected{ 1 };

			//Act
			int actual = testCell.GetColumn();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetAddressString_ReturnsAString)
		{
			//Arrange
			CellAddress testCell{ "B1" };
			string expected{ "B1" };

			//Act
			string actual = testCell.GetAddressString();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetAddressString_ReturnsCorrectString)
		{
			//Arrange
			CellAddress testCell{ "B1" };
			string expected{ "B1" };

			//Act
			string actual = testCell.GetAddressString();

			//Assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(SetRow_SetRowCorrectly)
		{
			//Arrange
			CellAddress test;
			int expectedRow{ 4 };

			//Act
			test.SetRow(4);
			int actualRow = test.GetRow();

			//Arrange
			Assert::AreEqual(expectedRow, actualRow);
		}

		TEST_METHOD(SetColumn_SetsColumnCorrectly)
		{
			//Arrange
			CellAddress test;
			int expected{ 5 };

			//Act
			test.SetColumn(5);
			int actual = test.GetColumn();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateAddressValueFromInt_MultipleValues)
		{
			CellAddress test;
			string expected;
			string actual;

			expected = "A";
			actual = test.CalculateAddressStringForInt(0);
			Assert::AreEqual(expected, actual);

			expected = "Q";
			actual = test.CalculateAddressStringForInt(16);
			Assert::AreEqual(expected, actual);

			expected = "Z";
			actual = test.CalculateAddressStringForInt(25);
			Assert::AreEqual(expected, actual);

			expected = "AA";
			actual = test.CalculateAddressStringForInt(26);
			Assert::AreEqual(expected, actual);

			expected = "AB";
			actual = test.CalculateAddressStringForInt(27);
			Assert::AreEqual(expected, actual);

			expected = "AZ";
			actual = test.CalculateAddressStringForInt(51);
			Assert::AreEqual(expected, actual);

			expected = "BA";
			actual = test.CalculateAddressStringForInt(52);
			Assert::AreEqual(expected, actual);

			expected = "FA";
			actual = test.CalculateAddressStringForInt(156);
			Assert::AreEqual(expected, actual);

			expected = "ZA";
			actual = test.CalculateAddressStringForInt(676);
			Assert::AreEqual(expected, actual);

			expected = "ZZ";
			actual = test.CalculateAddressStringForInt(701);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateAddressValueFromString_MultipleValues)
		{
			CellAddress test;
			int expected;
			int actual;

			expected = 0;
			actual = test.CalculateIntForAddressString("A");
			Assert::AreEqual(expected, actual);

			expected = 7;
			actual = test.CalculateIntForAddressString("H");
			Assert::AreEqual(expected, actual);

			expected = 22;
			actual = test.CalculateIntForAddressString("W");
			Assert::AreEqual(expected, actual);

			expected = 25;
			actual = test.CalculateIntForAddressString("Z");
			Assert::AreEqual(expected, actual);

			expected = 26;
			actual = test.CalculateIntForAddressString("AA");
			Assert::AreEqual(expected, actual);

			expected = 51;
			actual = test.CalculateIntForAddressString("AZ");
			Assert::AreEqual(expected, actual);

			expected = 52;
			actual = test.CalculateIntForAddressString("BA");
			Assert::AreEqual(expected, actual);

			expected = 103;
			actual = test.CalculateIntForAddressString("CZ");
			Assert::AreEqual(expected, actual);

			expected = 701;
			actual = test.CalculateIntForAddressString("ZZ");
			Assert::AreEqual(expected, actual);
		}

		//TEST_METHOD(CalculateAddressValueFromInt_ExpectException)
		//{
		//	//Arrange
		//	auto func = [] {CellAddress::CalculateAddressStringForInt(702); };

		//	//Assert
		//	Assert::ExpectException<Exceptions::CellAddressOutOfRange>(func);
		//}

		//TEST_METHOD(CalculateAddressValueFromString_ExpectException)
		//{
		//	//Arrange
		//	auto func = [] {CellAddress::CalculateIntForAddressString("AAA"); };

		//	//Assert
		//	Assert::ExpectException<Exceptions::CellAddressOutOfRange>(func);
		//}

		TEST_METHOD(AssignmentOperatorWithCellAddress_HasCorrectRow)
		{
			//arrange
			CellAddress cell{ "B2" };
			int expected{ 1 };

			//act
			CellAddress testCell = cell;
			int actual = testCell.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AssignmentOperatorWithCellAddress_HasCorrectColumn)
		{

			//arrange
			CellAddress cell{ "D5" };
			int expected{ 3 };

			//act
			CellAddress testCell = cell;
			int actual = testCell.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AssignmentOperatorWithCellAddress_HasAddress)
		{
			//arrange
			CellAddress cell{ "B5" };
			string expected{ "B5" };

			//act
			CellAddress testCell = cell;
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(AssignmentOperatorWithCellAddress_HasCorrectAddress)
		{
			//arrange
			CellAddress cell1{ "B2" };
			string expected{ "B2" };

			//act
			CellAddress testCell = cell1;
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AssignmentOperatorWithString_HasCorrectRow)
		{
			//arrange
			int expected{ 1 };

			//act
			CellAddress testCell = "B2";
			int actual = testCell.GetRow();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AssignmentOperatorWithString_HasCorrectColumn)
		{

			//arrange
			int expected{ 3 };

			//act
			CellAddress testCell = "D5";
			int actual = testCell.GetColumn();

			//act
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AssignmentOperatorWithString_HasAddress)
		{
			//arrange
			string expected{ "B5" };

			//act
			CellAddress testCell = "B5";
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(AssignmentOperatorWithString_HasCorrectAddress)
		{
			//arrange
			string expected{ "B2" };

			//act
			CellAddress testCell = "B2";
			string actual = testCell.GetAddressString();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(EqulityOperator_IsCorrect)
		{
			//arrange
			CellAddress testCellAddress1{ "A1" };
			CellAddress testCellAddress2{ "A1" };
			bool expected = true;

			//act
			bool actual = testCellAddress1 == testCellAddress2;

			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(InequlityOperator_IsCorrect)
		{
			//arrange
			CellAddress testCellAddress1{ "A1" };
			CellAddress testCellAddress2{ "B1" };
			bool expected = true;

			//act
			bool actual = testCellAddress1 != testCellAddress2;

			//assert
			Assert::AreEqual(expected, actual);
		}
	};
}
