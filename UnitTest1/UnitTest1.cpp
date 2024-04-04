#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string input = "Hello, (World)!";
			std::string expected = "Hello, !";
			Assert::AreEqual(expected, removeTextInBrackets(input));
		}

		TEST_METHOD(TestCopyFileWithRemovedBrackets)
		{
			
			std::string inputFile = "testInput.txt";
			std::string outputFile = "testOutput.txt";
			copyFileWithRemovedBrackets(inputFile, outputFile);
		
		}
	};
}
