#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &elem)
{
	std::cout << elem << " ";
}

void increment(int &n)
{
	n++;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Int array: ";
	::iter(intArray, intLen, print<int>);
	std::cout << std::endl;

	::iter(intArray, intLen, increment);
	std::cout << "After increment: ";
	::iter(intArray, intLen, print<int>);
	std::cout << std::endl;

	std::string strArray[] = {"hello", "world", "42"};
	size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "String array: ";
	::iter(strArray, strLen, print<std::string>);
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd'};
	size_t charLen = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Char array: ";
	::iter(charArray, charLen, print<char>);
	std::cout << std::endl;

	::iter(charArray, charLen, toUpper);
	std::cout << "After toUpper: ";
	::iter(charArray, charLen, print<char>);
	std::cout << std::endl;

	int const constArray[] = {10, 20, 30};
	std::cout << "Const array: ";
	::iter(constArray, 3, print<int>);
	std::cout << std::endl;

	return 0;
}
