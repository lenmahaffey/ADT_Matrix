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
			Matrix<int> test = Matrix<int>(1, 10, 0);
			int expected = 10;

			//act
			int actual = test.GetLength();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasHeight)
		{
			//arrange
			Matrix<int> test = Matrix<int>(10, 1, 0);
			int expected = 10;

			//act
			int actual = test.GetHeight();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_ExpectHeightException)
		{
			//arrange
			auto func = [] { Matrix<int> test = Matrix<int>(701, 10, 0); };

			//assert
			Assert::ExpectException<Exceptions::HeightOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_ExpectLengthException)
		{
			//arrange
			auto func = [] { Matrix<int> test = Matrix<int>(1, 701, 0); };

			//assert
			Assert::ExpectException<Exceptions::LengthOutOfBounds>(func);
		}

		TEST_METHOD(Constructor_ExpectMatrixException)
		{
			//arrange
			auto func = [] { Matrix<int> test = Matrix<int>(0, 701, 0); };

			//assert
			Assert::ExpectException<Exceptions::MatrixException>(func);
		}

		TEST_METHOD(GetCellWithString_ReturnsACell)
		{
			//arrange
			Matrix<int> test = Matrix<int>(10, 10, 0);
			Cell<int> expected = Cell<int>();

			//act
			Cell<int> actual = test.GetCell("A1");

			//assert
			Assert::AreEqual(typeid(expected).name(), typeid(actual).name());
		}

		TEST_METHOD(GetCellWithInts_ReturnsCorrectCell)
		{
			//arrange
			Matrix<int> test = Matrix<int>(10, 10, 0);
			string expected = "A1";

			//act
			string actual = test.GetCell("A1").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ReturnsAString)
		{
			//arrange
			string expected = "A1";
			Matrix<int> test = Matrix<int>(10, 10, 0);

			//act
			string actual = test.GetCell("A1").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ReturnsCorrectString)
		{
			//arrange
			string expected = "B10";
			Matrix<int> test = Matrix<int>(10, 10, 0);

			//act
			string actual = test.GetCell("B10").GetName();

			//assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(GetName_ExpectException)
		{
			//Arrange
			auto func1 = [] { std::string test = Matrix<int>(10, 10, 0).GetCell("Y1").GetName(); };

			//Assert
			Assert::ExpectException<Exceptions::BadAddressString>(func1);
		}
	};
}
