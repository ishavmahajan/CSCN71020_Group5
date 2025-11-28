#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
#include "../PolygonChecker/acceptRectanglePoints.h"
#include "../PolygonChecker/rectangleSolver.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_analyzeRectangle
{
    TEST_CLASS(TestCases_analyzeRectangle)
    {
    public:
        TEST_METHOD(T01)
        {
            double side1 = 0;
            double side2 = 0;
            double side3 = 0;
            double side4 = 0;
            double diagonal1 = 0;
            double diagonal2 = 0;
            
            char* actualResult=analyzeRectangle(side1, side2, side3, side4, diagonal1, diagonal2);
			char* expectedResult = "Invalid rectangle";

			Assert::AreEqual(expectedResult, actualResult);
        }
        TEST_METHOD(T02)
        {
            double side1 = 5;
            double side2 = 100;
            double side3 = 10;
            double side4 = 50;
            double diagonal1 = 0;
            double diagonal2 = 0;

            char* actualResult = analyzeRectangle(side1, side2, side3, side4, diagonal1, diagonal2);
            char* expectedResult = "Invalid rectangle";

            Assert::AreEqual(expectedResult, actualResult);
        }
        TEST_METHOD(T03)
        {
            double side1 = 4;
            double side2 = 3;
            double side3 = 4;
            double side4 = 3;
            double diagonal1 = 5;
            double diagonal2 = 5;

            char* actualResult = analyzeRectangle(side1, side2, side3, side4, diagonal1, diagonal2);
            char* expectedResult = "Valid rectangle";

            Assert::AreEqual(expectedResult, actualResult);
        }
        TEST_METHOD(T04)
        {
            double side1 = 4;
            double side2 = 3;
            double side3 = 4;
            double side4 = 3;
            double diagonal1 = 5;
            double diagonal2 = 10;

            char* actualResult = analyzeRectangle(side1, side2, side3, side4, diagonal1, diagonal2);
            char* expectedResult = "Invalid rectangle";

            Assert::AreEqual(expectedResult, actualResult);
        }
        TEST_METHOD(T05)
        {
            double side1 = 4;
            double side2 = 4;
            double side3 = 4;
            double side4 = 4;
            double diagonal1 = 5.65685;
            double diagonal2 = 5.65685;

            char* actualResult = analyzeRectangle(side1, side2, side3, side4, diagonal1, diagonal2);
            char* expectedResult = "Valid rectangle";

            Assert::AreEqual(expectedResult, actualResult,0.00001);
        }
    };
}
