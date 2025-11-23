#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "pch.h"
extern "C" {
#include "../PolygonChecker/main.h"
#include "../PolygonChecker/trianglesolver.h"
#include "../PolygonChecker/anglefinder.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GetTriangleSides
{
    TEST_CLASS(GetTriangleSidesTests)
    {
    public:

        TEST_METHOD(TestValidThreeSides)
        {
            FILE* f = fopen("input.txt", "w");
            Assert::IsNotNull(f);
            fputs("3 4 5\n", f);
            fclose(f);

            // redirect stdin and check
            FILE* in = freopen("input.txt", "r", stdin);
            Assert::IsNotNull(in);

            int sides[3] = { 0, 0, 0 };
            int* ret = getTriangleSides(sides);

            // optional pointer equality check
            Assert::IsTrue(ret == sides, L"getTriangleSides should return the same pointer passed in");

            // verify values
            Assert::AreEqual(3, sides[0]);
            Assert::AreEqual(4, sides[1]);
            Assert::AreEqual(5, sides[2]);

            // cleanup
            fclose(in); // closes the reopened stream
            remove("input.txt");
        }

        TEST_METHOD(TestInvalidFirstInputSetsZero)
        {
            FILE* f = fopen("input.txt", "w");
            Assert::IsNotNull(f);
            fputs("abc\n4\n5\n", f);
            fclose(f);

            FILE* in = freopen("input.txt", "r", stdin);
            Assert::IsNotNull(in);

            int sides[3] = { -1, -1, -1 };
            int* ret = getTriangleSides(sides);

            Assert::IsTrue(ret == sides, L"getTriangleSides should return the same pointer passed in");
            Assert::AreEqual(0, sides[0]);   // invalid first input -> set to 0
            Assert::AreEqual(4, sides[1]);
            Assert::AreEqual(5, sides[2]);

            fclose(in);
            remove("input.txt");
        }

        TEST_METHOD(TestZeroSideAccepted)
        {
            FILE* f = fopen("input.txt", "w");
            Assert::IsNotNull(f);
            fputs("0 4 5\n", f);
            fclose(f);

            FILE* in = freopen("input.txt", "r", stdin);
            Assert::IsNotNull(in);

            int sides[3] = { 9, 9, 9 };
            int* ret = getTriangleSides(sides);

            Assert::IsTrue(ret == sides, L"getTriangleSides should return the same pointer passed in");
            Assert::AreEqual(0, sides[0]);
            Assert::AreEqual(4, sides[1]);
            Assert::AreEqual(5, sides[2]);

            fclose(in);
            remove("input.txt");
        }
    };
}

