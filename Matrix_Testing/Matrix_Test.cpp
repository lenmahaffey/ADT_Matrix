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
			int expected, actual;

			Matrix<int> test = Matrix<int>(1, 10, 0);
			expected = 10;

			actual = test.GetLength();
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Constructor_HasHeight)
		{
			int expected, actual;

			Matrix<int> test = Matrix<int>(10, 1, 0);
			expected = 10;

			actual = test.GetHeight();
			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(ConstructorExceptions_Test)
		{
			auto func1 = [] { Matrix<int> test = Matrix<int>(701, 10, 0); };
			Assert::ExpectException<Exceptions::HeightOutOfBounds>(func1);

			auto func2 = [] { Matrix<int> test = Matrix<int>(0, 701, 0); };
			Assert::ExpectException<Exceptions::LengthOutOfBounds>(func2);
		}

		TEST_METHOD(GetName_Test)
		{
			string expected, actual;
			Matrix<int> test = Matrix<int>(10, 10, 0);

			expected = "A1";
			actual = test.GetCell("A1").GetName();
			Assert::AreEqual(expected, actual);

			expected = "B10";
			actual = test.GetCell("B10").GetName();
			Assert::AreEqual(expected, actual);

			expected = "I10";
			actual = test.GetCell("I10").GetName();
			Assert::AreEqual(expected, actual);

			auto func1 = [] { std::string test = Matrix<int>(10, 10, 0).GetCell("Y1").GetName(); };
			Assert::ExpectException<Exceptions::BadAddressString>(func1);

			auto func2 = [] { std::string test = Matrix<int>(10, 10, 0).GetCell("A11").GetName(); };
			Assert::ExpectException<Exceptions::BadAddressString>(func2);
		}
	};
}
