#include "CppUnitTest.h"
#include "../Matrix/Matrix.h"
#include "../"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Battleship;

namespace BattleshipTesting
{
	TEST_CLASS(Matrix_Test)
	{
		TEST_METHOD(ValiateCellName_Test)
		{
			Matrix<int>test = Matrix<int>(10, 10);
			test.validateCellName("A1");
		}
	};
}
