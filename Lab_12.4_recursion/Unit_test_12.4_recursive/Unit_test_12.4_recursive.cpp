#include "pch.h"
#include "CppUnitTest.h"
#include <list>
#include "../Lab_12.4_recursion/Lab_12.4_recirsion.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest124recursive
{
	TEST_CLASS(Unittest124recursive)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* list = NULL;
			Info value1 = 1;
			Info value2 = 2;
			Info value3 = 3;

			Insert(list, value1);
			Insert(list, value2);
			Insert(list, value3);

			insertAfterRecursive(list, 3, list);
			Assert::AreEqual(3, list->link->info);
		}
	};
}



