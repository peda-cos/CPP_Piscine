#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

static void testEmptyArray()
{
	std::cout << "=== Test: Empty Array ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	try
	{
		empty[0] = 1;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception on empty access: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void testConstArray()
{
	std::cout << "=== Test: Const Array Access ===" << std::endl;
	const Array<int> constArr(5);
	std::cout << "Const array size: " << constArr.size() << std::endl;
	std::cout << "Const access [0]: " << constArr[0] << std::endl;
	std::cout << std::endl;
}

static void testDeepCopy()
{
	std::cout << "=== Test: Deep Copy Independence ===" << std::endl;
	Array<int> original(3);
	original[0] = 42;
	original[1] = 21;
	original[2] = 84;

	Array<int> copyConstructed(original);
	Array<int> copyAssigned;
	copyAssigned = original;

	copyConstructed[0] = 100;
	copyAssigned[1] = 200;

	std::cout << "Original[0]: " << original[0] << " (expected 42)" << std::endl;
	std::cout << "Original[1]: " << original[1] << " (expected 21)" << std::endl;
	std::cout << "CopyConstructed[0]: " << copyConstructed[0] << " (expected 100)" << std::endl;
	std::cout << "CopyAssigned[1]: " << copyAssigned[1] << " (expected 200)" << std::endl;
	std::cout << std::endl;
}

static void testStringType()
{
	std::cout << "=== Test: String Type ===" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "42";
	std::cout << "strings[0]: " << strings[0] << std::endl;
	std::cout << "strings[1]: " << strings[1] << std::endl;
	std::cout << "strings[2]: " << strings[2] << std::endl;
	std::cout << "Size: " << strings.size() << std::endl;
	std::cout << std::endl;
}

static void testOriginalSubject()
{
	std::cout << "=== Test: Original Subject Test ===" << std::endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return;
		}
	}
	std::cout << "All " << MAX_VAL << " values match after copy/destruction test" << std::endl;

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception on negative index: " << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception on out-of-bounds: " << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();

	delete[] mirror;
	std::cout << std::endl;
}

int main()
{
	testEmptyArray();
	testConstArray();
	testDeepCopy();
	testStringType();
	testOriginalSubject();

	std::cout << "=== All tests completed ===" << std::endl;
	return 0;
}
