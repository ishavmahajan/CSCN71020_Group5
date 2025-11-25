#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
#include "../PolygonChecker/rectangleSolver.h"

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_rectangleArea
{
    TEST_CLASS(TestCases_rectangleArea)
    {
    public:
        TEST_METHOD(T001)
        {
            double side1 = 5;
            double side2 = 10;

            double expected = 50;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // One side = 0
        TEST_METHOD(T002)
        {
            double side1 = 0;
            double side2 = 8;

            double expected = 0;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // Both sides = 0
        TEST_METHOD(T003)
        {
            double side1 = 0;
            double side2 = 0;

            double expected = 0;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // Decimal side lengths
        TEST_METHOD(T004)
        {
            double side1 = 3.5;
            double side2 = 2.2;

            double expected = 7.7;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual, 0.0001);
        }

        // Large values
        TEST_METHOD(T005)
        {
            double side1 = 10000;
            double side2 = 20000;

            double expected = 200000000;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // Mixed integer and decimal
        TEST_METHOD(T006)
        {
            double side1 = 10;
            double side2 = 2.5;

            double expected = 25;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // Negative values (mathematically area shouldn't be negative but function just multiplies)
        TEST_METHOD(T007)
        {
            double side1 = -5;
            double side2 = 4;

            double expected = -20;  // based on function behavior
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

        // Two negative values (result positive)
        TEST_METHOD(T008)
        {
            double side1 = -6;
            double side2 = -7;

            double expected = 42;
            double actual = rectangleArea(side1, side2);

            Assert::AreEqual(expected, actual);
        }

    };
}
