#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		PmergeMe sorter;
		sorter.parseInputArguments(argc, argv);

		std::cout << "Before:";
		const std::vector<int>& original = sorter.getVector();
		for (size_t i = 0; i < original.size(); ++i)
		{
			std::cout << " " << original[i];
		}
		std::cout << std::endl;

		sorter.sort();

		std::cout << "After:";
		const std::vector<int>& sorted = sorter.getVector();
		for (size_t i = 0; i < sorted.size(); ++i)
		{
			std::cout << " " << sorted[i];
		}
		std::cout << std::endl;

		std::cout << "Time to process a range of " << sorted.size()
				  << " elements with std::vector : " << sorter.getVectorTime() << " us" << std::endl;
		std::cout << "Time to process a range of " << sorter.getDeque().size()
				  << " elements with std::deque  : " << sorter.getDequeTime() << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
