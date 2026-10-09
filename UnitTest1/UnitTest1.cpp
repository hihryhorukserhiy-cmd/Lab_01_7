#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1_7/BitString.h"
#include "../lab_1_7/BitString.cpp"
#include "../lab_1_7/Set.h"
#include "../lab_1_7/Set.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BitString bs;
			bs.Init(0, 1);
			BitString shifted = bs.ShiftLeft(33);
			Assert::AreEqual(2UL, shifted.GetHigh()); // 1 << (33 - 32) = 2
			Assert::AreEqual(0UL, shifted.GetLow());
		}
	};
}
