#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span small(1);
	small.addNumber(1);
	try
	{
		small.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span big(10000);
	std::vector<int> nums;
	for (int i = 0; i < 10000; i++)
		nums.push_back(i);
	big.addNumbers(nums.begin(), nums.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;

	Span range(5);
	int arr[] = {100, 200, 300};
	range.addNumbers(arr, arr + 3);
	std::cout << range.shortestSpan() << std::endl;
	std::cout << range.longestSpan() << std::endl;

	return 0;
}
