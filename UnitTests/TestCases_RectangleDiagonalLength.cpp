#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
#include "../PolygonChecker/rectangleSolver.h"

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_RectangleDiagonalLength
{
    TEST_CLASS(TestCases_RectangleDiagonalLength)
    {
    public:
        TEST_METHOD(T001)
        {
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		double expectedResult = 0.0;
        double actualResult = RectangleDiagonalLength(x1, y1, x2, y2);

		Assert::AreEqual(expectedResult, actualResult, 0.0001);
        }

        TEST_METHOD(T002)
        {
            int x1 = 0, y1 = 0, x2 = 1, y2 = 1;
            double expectedResult = 1.41421;
            double actualResult = RectangleDiagonalLength(x1, y1, x2, y2);

            Assert::AreEqual(expectedResult, actualResult, 0.0001);
        }
        TEST_METHOD(T003)
        {
            int x1 = 0, y1 = 0, x2 = -1, y2 = -1;
            double expectedResult = 1.41421;
            double actualResult = RectangleDiagonalLength(x1, y1, x2, y2);

            Assert::AreEqual(expectedResult, actualResult, 0.0001);
        }
    };
}
