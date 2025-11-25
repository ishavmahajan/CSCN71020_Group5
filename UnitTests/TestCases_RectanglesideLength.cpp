#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
#include "../PolygonChecker/rectangleSolver.h"

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_RectanglesideLength
{
    TEST_CLASS(TestCases_RectanglesideLength)
    {
    public:
        TEST_METHOD(T001)   
        {
            int x1 = 0;
            int y1 = 0;
            int x2 = 5;
            int y2 = 0;

            double expectedResult = 5;
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }
        TEST_METHOD(T002)
        {
            int x1 = 3;
            int y1 = 2;
            int x2 = 3;
            int y2 = 8;

            double expectedResult = 6;
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }

        // Diagonal line (Pythagorean)
        TEST_METHOD(T003)
        {
            int x1 = 1;
            int y1 = 1;
            int x2 = 4;
            int y2 = 5;

            double expectedResult = 5; // sqrt(3^2 + 4^2)
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }

        // Same point (zero length)
        TEST_METHOD(T004)
        {
            int x1 = 2;
            int y1 = 2;
            int x2 = 2;
            int y2 = 2;

            double expectedResult = 0;
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }

        // Negative coordinates
        TEST_METHOD(T005)
        {
            int x1 = -2;
            int y1 = -3;
            int x2 = -5;
            int y2 = 1;

            double expectedResult = 5; // sqrt((-3)^2 + 4^2)
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }

        // Mixed positive & negative coordinates
        TEST_METHOD(T006)
        {
            int x1 = -4;
            int y1 = 2;
            int x2 = 1;
            int y2 = -1;

            double expectedResult = sqrt(5 * 5 + 3 * 3); // sqrt(34)
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult, 0.0001);
        }

        // Large values test
        TEST_METHOD(T007)
        {
            int x1 = 1000;
            int y1 = 2000;
            int x2 = 4000;
            int y2 = 6000;

            double expectedResult = 5000; // sqrt(3000^2 + 4000^2)
            double actualResult = RectanglesideLength(x1, y1, x2, y2);
            Assert::AreEqual(expectedResult, actualResult);
        }
       
    };
}
