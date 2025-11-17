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
        TEST_METHOD(TestScalene)
        {
            char* result = analyzeTriangle(3, 4, 5);
            Assert::AreEqual("Scalene triangle", result);
        }

        TEST_METHOD(TestIsosceles)
        {
            char* result = analyzeTriangle(5, 5, 3);
            Assert::AreEqual("Isosceles triangle", result);
        }

	};
}
