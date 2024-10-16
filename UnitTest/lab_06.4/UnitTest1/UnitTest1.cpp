#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06.4/lab_06.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForArrayProcessing
{
    TEST_CLASS(UnitTestForArrayProcessing)
    {
    public:

        
        TEST_METHOD(TestGenerateArray)
        {
            std::vector<double> arr(5);
            generateArray(arr, 5, -10.0, 10.0);

            
            for (double elem : arr) {
                Assert::IsTrue(elem >= -10.0 && elem <= 10.0, L"Element out of range [-10, 10]");
            }
        }

        
        TEST_METHOD(TestSumAfterFirstNegative)
        {
            std::vector<double> arr = { 4.4, -3.3, 2.2, 6.6, -7.7 };
            double expectedSum = fabs(2.2) + fabs(6.6) + fabs(-7.7);  
            double resultSum = sumAfterFirstNegative(arr);
            Assert::AreEqual(expectedSum, resultSum, 0.001, L"Wrong sum after first negative element");
        }

        
        TEST_METHOD(TestCompressArray)
        {
            std::vector<double> arr = { 1.1, 2.2, 3.3, 4.4, 5.5 };
            double a = 2.0, b = 4.5;
            std::vector<double> expectedArr = { 1.1, 5.5, 0.0, 0.0, 0.0 };

            compressArray(arr, a, b);

            for (int i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expectedArr[i], arr[i], 0.001, L"Array compression failed");
            }
        }

    };
}
