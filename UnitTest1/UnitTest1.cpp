#include "pch.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            std::string expected = "Hello, World!";
            std::string actual = "Hello, World!";

            // Перетворюємо std::string в const char* для порівняння
            Assert::AreEqual(expected.c_str(), actual.c_str());
        }

        TEST_METHOD(TestMethod2)
        {
            std::string expected = "Hello, World!";
            std::string actual = "Hello, C++!";

            // Тест на невідповідність рядків
            Assert::AreNotEqual(expected.c_str(), actual.c_str());
        }
    };
}