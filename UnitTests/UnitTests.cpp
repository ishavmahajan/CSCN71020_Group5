#include "CppUnitTest.h"

extern "C" {

#include "../PolygonChecker/main.h"
#include "../PolygonChecker/trianglesolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TriangleTests)
	{
	public:
		
		TEST_METHOD(TestEquilateral)
		{
			char* result = analyzeTriangle(3, 3, 3);
			Assert::AreEqual("Equilateral triangle", result);
		}
	};
}
