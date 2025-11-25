#include "pch.h" 
#include "CppUnitTest.h" 
extern "C" {
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/angleFinder.h"
#include "../PolygonChecker/rectangleSolver.h"

}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases_rectanglePerimeter
{
    TEST_CLASS(TestCases_rectanglePerimeter)
    {
    public:
        TEST_METHOD(TestnormalRectangle)
        {

            Assert::AreEqual(20.0, rectanglePerimeter(4.0, 6.0, 4.0, 6.0), 0.0001);
        }

        TEST_METHOD(TestSquare)
        {

            Assert::AreEqual(20.0, rectanglePerimeter(5.0, 5.0, 5.0, 5.0), 0.0001);
        }

        TEST_METHOD(Testwithzeroside)
        {
            Assert::AreEqual(10.0, rectanglePerimeter(0.0, 5.0, 0.0, 5.0), 0.0001);
        }

        TEST_METHOD(TestAllsidesZeros)
        {
            Assert::AreEqual(0.0, rectanglePerimeter(0.0, 0.0, 0.0, 0.0), 0.0001);
        }

        TEST_METHOD(TestDecimal)
        {
            Assert::AreEqual(14.0, rectanglePerimeter(2.5, 4.5, 2.5, 4.5), 0.0001);
        }

        TEST_METHOD(TestLargeValues)
        {
            Assert::AreEqual(4000000.0,
                rectanglePerimeter(1000000.0, 1000000.0, 1000000.0, 1000000.0), 0.1);
        }

        TEST_METHOD(TestNegative)
        {
            Assert::AreEqual(4.0, rectanglePerimeter(-4.0, 6.0, -4.0, 6.0), 0.0001);

        }
    };
}
