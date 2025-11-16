#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_angleFinder
{
    TEST_CLASS(TestCases_angleFinder)
    {
    public:
        //**this code works- DO NOT CHANGE ANYMORE**
        TEST_METHOD(T001_EquilateralTriangle)
        {
            int side1 = 10;
            int side2 = 10;
            int side3 = 10;
            double angleA = 0;
            double angleB = 0;
            double angleC = 0;
            double expectedResult = 60;
            anglefinder(side1, side2, side3, &angleA, &angleB, &angleC);

            Assert::AreEqual(expectedResult, angleA, 0.05); //tolerance of 0.05
            Assert::AreEqual(expectedResult, angleB, 0.05);
            Assert::AreEqual(expectedResult, angleC, 0.05);

        }
        TEST_METHOD(T002_IsoscelesTriangle)
        {
            int side1 = 3;
            int side2 = 3;
            int side3 = 5;
            double angleA = 0;
            double angleB = 0;
            double angleC = 0;
            double expectedResultA = 33.56;
            double expectedResultB = 33.56;
            double expectedResultC = 112.89;
            anglefinder(side1, side2, side3, &angleA, &angleB, &angleC);

            Assert::AreEqual(expectedResultA, angleA, 0.05); //tolerance of 0.05
            Assert::AreEqual(expectedResultB, angleB, 0.05);
            Assert::AreEqual(expectedResultC, angleC, 0.05);

        }
        TEST_METHOD(T003_ScaleneTriangle)
        {
            int side1 = 3;
            int side2 = 4;
            int side3 = 5;
            double angleA = 0;
            double angleB = 0;
            double angleC = 0;
            double expectedResultA = 36.87;
            double expectedResultB = 53.13;
            double expectedResultC = 90;
            anglefinder(side1, side2, side3, &angleA, &angleB, &angleC);

            Assert::AreEqual(expectedResultA, angleA, 0.05); //tolerance of 0.05
            Assert::AreEqual(expectedResultB, angleB, 0.05);
            Assert::AreEqual(expectedResultC, angleC, 0.05);

        }
    };
}
