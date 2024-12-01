#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../lab6.4/6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSumNegativeElements)
        {
            double arr[] = { -1.5, 3.4, -2.1, 0.5, -4.7 };
            int size = 5;
            double expectedSum = -8.3;
            double actualSum = sumNegativeElements(arr, size);
            Assert::AreEqual(expectedSum, actualSum, 0.001);
        }
        TEST_METHOD(TestSortEvenNumbers)
        {
            double arr[] = { 4.2, 6.1, 3.5, 2.4, 8.3 };
            int size = 5;
            double expectedArr[] = { 2.4, 4.2, 3.5, 6.1, 8.3 };
            sortEvenNumbers(arr, size);
            for (int i = 0; i < size; ++i)
            {
                Assert::AreEqual(expectedArr[i], arr[i], 0.001);
            }
        }
    };
}
