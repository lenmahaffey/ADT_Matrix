#include "CppUnitTest.h"
#include "../Matrix/src/matrix.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace ADT;
namespace MatrixTesting
{
	TEST_CLASS(Matrix_Test)
	{
		TEST_METHOD(Constructor_HasLength)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 1, 0 };
			int expected = 10;

			//act
			int actual = testMatrix.GetLength();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasHeight)
		{
			//arrange
			Matrix<int> testMatrix{ 1, 10, 0 };
			int expected = 10;

			//act
			int actual = testMatrix.GetHeight();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_ExpectHeightException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix{ 701, 10, 0 }; };

			//assert
			Assert::ExpectException<Exceptions::ColumnOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_ExpectLengthException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix{ 1, 701, 0 }; };

			//assert
			Assert::ExpectException<Exceptions::RowOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_Constuct2x3Correctly_HasTopLeftCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 2, 3, 0 };
			string expected{ "A1" };

			//act
			string actual{ testMatrix.GetCell(0,0).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct2x3Correctly_HasTopRightCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 2, 3, 0 };
			CellAddress testAddress{ "B1" };
			string expected{ testAddress.GetAddressString() };

			//act
			string actual{ testMatrix.GetCell(1, 0).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct2x3Correctly_HasBottomLeftCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 2, 3, 0 };
			CellAddress testAddress{ "A2" };
			string expected{ testAddress.GetAddressString() };

			//act
			string actual{ testMatrix.GetCell(0, 1).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct2x3Correctly_HasBottomRightCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 2, 3, 0 };
			CellAddress testAddress{ "B2" };
			string expected{ testAddress.GetAddressString() };

			//act
			string actual{ testMatrix.GetCell(1, 1).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct3x2Correctly_HasTopLeftCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 3, 2, 0 };
			string expected{"A1"};

			//act
			string actual{ testMatrix.GetCell(0, 0).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct3x2Correctly_HasTopRightCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 3, 2, 0 };
			string expected{ "C1" };

			//act
			string actual{ testMatrix.GetCell(2, 0).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct3x2Correctly_HasBottomLeftCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 3, 2, 0 };
			string expected{ "A2" };

			//act
			string actual{ testMatrix.GetCell(0, 1).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_Constuct3x2Correctly_HasBottomRightCorner)
		{
			//arrange
			Matrix<int> testMatrix{ 3, 2, 0 };
			string expected{ "C2" };

			//act
			string actual{ testMatrix.GetCell(2, 1).GetCellAddressString() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_HasLength)
		{
			//arrange
			Matrix<int> testMatrix{ Matrix<int>{ 10, 1, 0 } };
			int expected = 10;

			//act
			int actual = testMatrix.GetLength();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_HasHeight)
		{
			//arrange
			Matrix<int> testMatrix{ Matrix<int>{ 1, 10, 0 } };
			int expected = 10;

			//act
			int actual = testMatrix.GetHeight();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CopyConstructor_ExpectHeightException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix{ Matrix<int>{708, 10, 0} }; };

			//assert
			Assert::ExpectException<Exceptions::ColumnOutOfBounds>(func);
		}

		TEST_METHOD(CopyConstructor_ExpectLengthException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix = Matrix<int>{ 1, 701, 0 }; };

			//assert
			Assert::ExpectException<Exceptions::RowOutOfBounds>(func);
		}

		TEST_METHOD(GetCellWithAddressInts_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			Cell<int> expected{ 2, 4, 0 };

			//act
			Cell<int> actual = testMatrix.GetCell(2, 4);

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellWithAddressInts_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			Cell<int> expected{ 2, 4, 0 };

			//act
			Cell<int> actual = testMatrix.GetCell(2, 4);

			//assert
			Assert::AreEqual(expected.GetCellAddressString(), actual.GetCellAddressString());
		}


		TEST_METHOD(GetCellWithAddressString_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			Cell<int> expected = Cell<int>();

			//act
			Cell<int> actual = testMatrix.GetCell("A1");

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellWithAddressString_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			string expected = "A1";

			//act
			string actual{ testMatrix.GetCell("A1").GetName() };

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetCellContentsWithAddressInts_ReturnsAContentType)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell(2, 4).GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellContentsWithAddressInts_ReturnsCorrectContents)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			string expected{ "C5" };

			//act
			string actual = testMatrix.GetCell(2,4).GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetCellContentsWithAddressString_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell("A1").GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellContentsWithAddressString_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			string expected{ "A1" };

			//act
			string actual = testMatrix.GetCell("A1").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetCellWithIntAddress_SetsCorrectValue)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			int expected{ 5 };

			//act
			testMatrix.SetCellContents(0, 0, 5);
			int actual = testMatrix.GetCellContents("A1");

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetCellWithAddressString_SetsCorrectValue)
		{
			//arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			int expected{ 5 };

			//act
			testMatrix.SetCellContents("A1", 5);
			int actual = testMatrix.GetCellContents("A1");

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsACellAddress)
		{
			//Arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			CellAddress expected{ 3, 4 };

			//act
			CellAddress actual = testMatrix.GetCell("D5").GetCellAddress();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsCorrectCell)
		{
			//Arrange
			Matrix<int> testMatrix{ 10, 10, 0 };
			string testString{ "C5" };
			CellAddress expected{ 2, 4 };

			//act
			CellAddress actual = testMatrix.GetCell("C5").GetCellAddress();

			//assert
			Assert::AreEqual(expected.GetAddressString(), actual.GetAddressString());
		}

		TEST_METHOD(GetCellFromAddressString_ReturnsCellAddressFromDoubleDigit)
		{
			//Arrange
			Matrix<int> testMatrix{ 2, 27, 0 };
			Cell<int> testCell{1, 26, 0};
			string expected{ "B27" };

			//act
			Cell<int> actual{ testMatrix.GetCell("B27") };

			//assert
			Assert::AreEqual(expected, actual.GetCellAddressString());
		}

		TEST_METHOD(GetCellFromAddressString_ReturnsCorrectCellFromDoubleLetter)
		{
			//Arrange
			Matrix<int> testMatrix{ 27, 5, 0 };
			Cell<int> expected{ 26, 4, 0 };

			//act
			Cell<int> actual = testMatrix.GetCell("AA5");

			//assert
			Assert::AreEqual(expected.GetCellAddressString(), actual.GetCellAddressString());
		}

		TEST_METHOD(GetCellFromAddressString_ReturnsCorrectCellFromDoubleLetterandDigit)
		{
			//Arrange
			Matrix<int> testMatrix{ 28, 54, 7 };
			Cell<int> expected{ 27, 53, 7 };

			//act
			Cell<int> actual = testMatrix.GetCell("AB54");

			//assert
			Assert::AreEqual(expected.GetCellAddressString(), actual.GetCellAddressString());
		}

		TEST_METHOD(EqualityOperator_ReturnsTrueCorrectly)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 10, 0};
			bool expected{ true };

			//act
			bool actual = (testMatrix1 == testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(EqualityOperator_ReturnsFalseCorrectlyLength)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 20, 0};
			bool expected{ false };

			//act
			bool actual = (testMatrix1 == testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(EqualityOperator_ReturnsFalseCorrectlyHeight)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{10, 10, 0};
			bool expected{ false };

			//act
			bool actual = (testMatrix1 == testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(EqualityOperator_ReturnsFalseCorrectlyAllContent)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 10, 2};
			bool expected{ false };

			//act
			bool actual = (testMatrix1 == testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(EqualityOperator_ReturnsFalseCorrectlyOneContent)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 10, 0};
			bool expected{ false };

			//act
			testMatrix2.SetCellContents("B2", 6);
			bool actual = (testMatrix1 == testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InequalityOperator_ReturnsTrueCorrectly)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{10, 10, 0};
			bool expected{ true };

			//act
			bool actual = (testMatrix1 != testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(InequalityOperator_ReturnsTrueCorrectlyLength)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 20, 0};
			bool expected{ true };

			//act
			bool actual = (testMatrix1 != testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(InequalityOperator_ReturnsTrueCorrectlyHeight)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{10, 10, 0};
			bool expected{ true };

			//act
			bool actual = (testMatrix1 != testMatrix2);

			//assert
			Assert::AreEqual(expected, actual);

		}

		TEST_METHOD(InequalityOperator_ReturnsTrueCorrectlyAllContent)
		{
			//arrange
			Matrix<int> testMatrix1{50, 10, 0};
			Matrix<int> testMatrix2{50, 50, 2};
			bool expected{ true };

			//act
			bool actual = (testMatrix1 != testMatrix2);

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InequalityOperator_ReturnsTrueCorrectlyOneContent)
		{
			//arrange
			Matrix<int> testMatrix1{3, 2, 0};
			Matrix<int> testMatrix2{3, 2, 0};
			bool expected{ true };

			//act
			testMatrix2.SetCellContents("B1", 6);
			bool actual = (testMatrix1 != testMatrix2);


			//assert
			Assert::AreEqual(expected, actual);
		}
	};
}
