#include "CppUnitTest.h"
#include "../Matrix/src/CellAddress.h"
#include "../Matrix/src/CellAddress.cpp"
#include "../Matrix/src/MatrixExceptions.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Exceptions;
namespace MatrixTesting
{
	TEST_CLASS(CellAddress_Test)
	{
		TEST_METHOD(Constructor_Test)
		{
			CellAddress test;
			int expectedRow = -1;
			int expectedColumn = -1;
			string expectedAddress = "";

			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(ConstructorWithValues_Test)
		{
			CellAddress test(0,0);
			int expectedRow = 0;
			int expectedColumn = 0;
			string expectedAddress = "A1";

			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(ConstructorExceptions_Test)
		{
			auto func1 = [] {CellAddress test = CellAddress(701, 0); };
			Assert::ExpectException<Exceptions::HeightOutOfBounds>(func1);

			auto func2 = [] {CellAddress test = CellAddress(0, 701); };
			Assert::ExpectException<Exceptions::LengthOutOfBounds>(func2);
		}

		TEST_METHOD(CopyConstructor_Test)
		{
			CellAddress first(1, 5);
			CellAddress test = first;
			int expectedColumn = 1;
			int expectedRow = 5;
			string expectedAddress = "B6";

			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(SetRow_Test)
		{
			CellAddress test;
			int expectedRow = 4;
			int expectedColumn = -1;
			string expectedAddress = "";

			test.SetRow(4);
			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(SetColumn_Test)
		{
			CellAddress test;
			int expectedRow = -1;
			int expectedColumn = 5;
			string expectedAddress = "";

			test.SetColumn(5);
			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(CalculateAddressValueFromInt_Test)
		{
			CellAddress test;
			string expected;
			string actual;

			expected = "A";
			actual = test.calculateAddressStringForInt(0);
			Assert::AreEqual(expected, actual);

			expected = "Q";
			actual = test.calculateAddressStringForInt(16);
			Assert::AreEqual(expected, actual);

			expected = "Z";
			actual = test.calculateAddressStringForInt(25);
			Assert::AreEqual(expected, actual);

			expected = "AA";
			actual = test.calculateAddressStringForInt(26);
			Assert::AreEqual(expected, actual);

			expected = "AB";
			actual = test.calculateAddressStringForInt(27);
			Assert::AreEqual(expected, actual);

			expected = "AZ";
			actual = test.calculateAddressStringForInt(51);
			Assert::AreEqual(expected, actual);

			expected = "BA";
			actual = test.calculateAddressStringForInt(52);
			Assert::AreEqual(expected, actual);

			expected = "FA";
			actual = test.calculateAddressStringForInt(156);
			Assert::AreEqual(expected, actual);

			expected = "ZA";
			actual = test.calculateAddressStringForInt(676);
			Assert::AreEqual(expected, actual);

			expected = "ZZ";
			actual = test.calculateAddressStringForInt(701);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateAddressValueFromString_Test)
		{
			CellAddress test;
			int expected;
			int actual;

			expected = 0;
			actual = test.calculateIntForAddressString("A");
			Assert::AreEqual(expected, actual);

			expected = 7;
			actual = test.calculateIntForAddressString("H");
			Assert::AreEqual(expected, actual);

			expected = 22;
			actual = test.calculateIntForAddressString("W");
			Assert::AreEqual(expected, actual);

			expected = 25;
			actual = test.calculateIntForAddressString("Z");
			Assert::AreEqual(expected, actual);

			expected = 26;
			actual = test.calculateIntForAddressString("AA");
			Assert::AreEqual(expected, actual);

			expected = 51;
			actual = test.calculateIntForAddressString("AZ");
			Assert::AreEqual(expected, actual);

			expected = 52;
			actual = test.calculateIntForAddressString("BA");
			Assert::AreEqual(expected, actual);

			expected = 103;
			actual = test.calculateIntForAddressString("CZ");
			Assert::AreEqual(expected, actual);

			expected = 701;
			actual = test.calculateIntForAddressString("ZZ");
			Assert::AreEqual(expected, actual);
		}
	};
}
