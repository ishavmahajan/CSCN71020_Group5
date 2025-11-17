#include "CppUnitTest.h"
#include "pch.h"


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

        TEST_METHOD(TestZeroSide)
        {
            char* result = analyzeTriangle(0, 4, 5);
            Assert::AreEqual("The sides cannot form a triangle", result);
        }

        TEST_METHOD(TestNegativeSide)
        {
            char* result = analyzeTriangle(-2, 4, 5);
            Assert::AreEqual("The sides cannot form a triangle", result);
        }

        TEST_METHOD(TestBigDifference)
        {
            char* result = analyzeTriangle(10, 2, 2);
            Assert::AreEqual("The sides cannot form a triangle", result);
        }
	};
}
