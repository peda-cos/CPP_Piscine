#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(vec, 7);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(42);
	lst.push_back(100);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(10);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 10);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> empty;
	try
	{
		easyfind(empty, 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
