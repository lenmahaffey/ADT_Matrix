#include "CppUnitTest.h"
#include "../Matrix/src/matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace MatrixTesting
{
	TEST_CLASS(Matrix_Test)
	{
		TEST_METHOD(Constructor_HasLength)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(1, 10, 0);
			int expected = 10;

			//act
			int actual = testMatrix.GetLength();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasHeight)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 1, 0);
			int expected = 10;

			//act
			int actual = testMatrix.GetHeight();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_ExpectHeightException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix = Matrix<int>(701, 10, 0); };

			//assert
			Assert::ExpectException<Exceptions::RowOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_ExpectLengthException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix = Matrix<int>(1, 701, 0); };

			//assert
			Assert::ExpectException<Exceptions::ColumnOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_ExpectMatrixException)
		{
			//arrange
			auto func = [] { Matrix<int> testMatrix = Matrix<int>(0, 701, 0); };

			//assert
			Assert::ExpectException<Exceptions::MatrixException>(func);
		}

		TEST_METHOD(GetName_ReturnsAString)
		{
			//arrange
			string expected = "A1";
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);

			//act
			string actual = testMatrix.GetCell("A1").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ReturnsCorrectString)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			string expected = "B10";

			//act
			string actual = testMatrix.GetCell("B10").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ExpectException)
		{
			//Arrange
			auto func1 = [] { std::string testMatrix = Matrix<int>(10, 10, 0).GetCell("Y1").GetName(); };

			//Assert
			Assert::ExpectException<Exceptions::ColumnOutOfBounds>(func1);
		}

		TEST_METHOD(GetCellWithInts_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			Cell<int> expected{ 2, 4, 0 };

			//act
			Cell<int> actual = testMatrix.GetCell(2, 4);

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellWithInts_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			string expected = "C5";

			//act
			string actual = testMatrix.GetCell(2, 4).GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(GetCellWithString_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			Cell<int> expected = Cell<int>();

			//act
			Cell<int> actual = testMatrix.GetCell("A1");

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellWithString_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			string expected = "A1";

			//act
			string actual = testMatrix.GetCell("A1").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetCellContentsWithInts_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell(2, 4).GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellContentsWithInts_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell(2,4).GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetCellContentsWithString_ReturnsACell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell("A1").GetContents();

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellContentsWithString_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			int expected{ 0 };

			//act
			int actual = testMatrix.GetCell("A1").GetContents();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SetCellWithIntAddress_SetsCorrectValue)
		{
			//arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
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
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
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
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			string testString{ "C5" };
			CellAddress expected{ 3, 4 };

			//act
			CellAddress actual = testMatrix.GetCellAddressFromAddressString(testString);

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsCorrectAddress)
		{
			//Arrange
			Matrix<int> testMatrix = Matrix<int>(10, 10, 0);
			string testString{ "C5" };
			CellAddress expected{ 2, 4 };

			//act
			CellAddress actual = testMatrix.GetCellAddressFromAddressString(testString);

			//assert
			Assert::AreEqual(expected.GetAddressString(), actual.GetAddressString());
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsCorrectAddressFromDoubleDigit)
		{
			//Arrange
			Matrix<int> testMatrix = Matrix<int>(10, 60, 0);
			string testString{ "C55" };
			CellAddress expected{ 2, 54 };

			//act
			CellAddress actual = testMatrix.GetCellAddressFromAddressString(testString);

			//assert
			Assert::AreEqual(expected.GetAddressString(), actual.GetAddressString());
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsCorrectAddressFromDoubleLetter)
		{
			//Arrange
			Matrix<int> testMatrix = Matrix<int>(50, 10, 0);
			string testString{ "AC5" };
			CellAddress expected{ 28, 4 };

			//act
			CellAddress actual = testMatrix.GetCellAddressFromAddressString(testString);

			//assert
			Assert::AreEqual(expected.GetAddressString(), actual.GetAddressString());
		}

		TEST_METHOD(GetCellAddressFromAddressString_ReturnsCorrectAddressFromDoubleLetterandDigit)
		{
			//Arrange
			Matrix<int> testMatrix = Matrix<int>(50, 10, 0);
			string testString{ "AC55" };
			CellAddress expected{ 28, 54 };

			//act
			CellAddress actual = testMatrix.GetCellAddressFromAddressString(testString);

			//assert
			Assert::AreEqual(expected.GetAddressString(), actual.GetAddressString());
		}
	};
}
