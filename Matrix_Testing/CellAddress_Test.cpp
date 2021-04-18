#include "CppUnitTest.h"
#include "../Matrix/src/CellAddress.h"
#include "../Matrix/src/CellAddress.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
			string expectedAddress = "00";

			int actualRow = test.GetRow();
			int actualColumn = test.GetColumn();
			string actualAddress = test.GetAddress();

			Assert::AreEqual(expectedRow, actualRow);
			Assert::AreEqual(expectedColumn, actualColumn);
			Assert::AreEqual(expectedAddress, actualAddress);
		}

		TEST_METHOD(AssignemntConstructor_Test)
		{
			CellAddress first(4, 5);
			CellAddress test = first;
			int expectedRow = 4;
			int expectedColumn = 5;
			string expectedAddress = "45";

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

			//expected = "A";
			//actual = test.calculateAddressValue(0);
			//Assert::AreEqual(expected, actual);

			//expected = "Q";
			//actual = test.calculateAddressValue(16);
			//Assert::AreEqual(expected, actual);

			//expected = "Z";
			//actual = test.calculateAddressValue(25);
			//Assert::AreEqual(expected, actual);

			//expected = "AA";
			//actual = test.calculateAddressValue(26);
			//Assert::AreEqual(expected, actual);

			//expected = "AB";
			//actual = test.calculateAddressValue(27);
			//Assert::AreEqual(expected, actual);

			//expected = "AZ";
			//actual = test.calculateAddressValue(51);
			//Assert::AreEqual(expected, actual);

			//expected = "BA";
			//actual = test.calculateAddressValue(52);
			//Assert::AreEqual(expected, actual);

			//expected = "FA";
			//actual = test.calculateAddressValue(156);
			//Assert::AreEqual(expected, actual);

			expected = "ZA";
			actual = test.calculateAddressValue(676);
			Assert::AreEqual(expected, actual);

			expected = "ZZ";
			actual = test.calculateAddressValue(701);
			Assert::AreEqual(expected, actual);

			expected = "AAA";
			actual = test.calculateAddressValue(702);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateAddressValueFromString_Test)
		{

		}
	};
}
