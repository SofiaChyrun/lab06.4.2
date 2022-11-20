#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab6.4.2/ChyrunSofialab6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0642
{
	TEST_CLASS(UnitTest0642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int n = 6, C = 3;
			double a[n] = { 1,2,3,4,5,6 };
			t = Count(a, n - 1, C, 0);
			Assert::AreEqual(t, 2);
		}
	};
}
