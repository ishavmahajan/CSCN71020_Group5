#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "pch.h"

extern "C" {
#include "../PolygonChecker/main.h"
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/anglefinder.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrintShapeMenu
{
    TEST_CLASS(PrintShapeMenuTests)
    {
    public:

        TEST_METHOD(TestValidInput)
        {
            FILE* f = fopen("input.txt", "w");
            fputs("1\n", f);
            fclose(f);

            freopen("input.txt", "r", stdin);

            int result = printShapeMenu();
            Assert::AreEqual(1, result);

            remove("input.txt");
        }

        TEST_METHOD(TestInvalidInput)
        {
            FILE* f = fopen("input.txt", "w");
            fputs("abc\n", f);
            fclose(f);

            freopen("input.txt", "r", stdin);

            int result = printShapeMenu();
            Assert::AreEqual(-1, result);

            remove("input.txt");
        }
    };
}


