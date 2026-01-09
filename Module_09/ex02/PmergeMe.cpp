#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
#include <climits>
#include <algorithm>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vector(other._vector), _deque(other._deque),
	  _vectorTime(other._vectorTime), _dequeTime(other._dequeTime)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char* argv[])
{
	if (argc < 2)
	{
		throw InvalidInputException();
	}

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg.empty())
		{
			throw InvalidInputException();
		}

		for (size_t j = 0; j < arg.length(); ++j)
		{
			if (arg[j] < '0' || arg[j] > '9')
			{
				throw InvalidInputException();
			}
		}

		char* endPtr;
		long value = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || value < 0 || value > INT_MAX)
		{
			throw InvalidInputException();
		}

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
	{
		return jacobsthal;
	}

	jacobsthal.push_back(0);
	if (n == 1)
	{
		return jacobsthal;
	}

	jacobsthal.push_back(1);

	while (true)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= n)
		{
			break;
		}
		jacobsthal.push_back(next);
	}

	return jacobsthal;
}

template<typename Container>
size_t PmergeMe::binarySearchInsertPos(const Container& sorted, int value, size_t end)
{
	size_t left = 0;
	size_t right = end;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sorted[mid] > value)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1)
	{
		return;
	}

	if (n == 2)
	{
		if (arr[0] > arr[1])
		{
			std::swap(arr[0], arr[1]);
		}
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;

	if (hasStraggler)
	{
		straggler = arr[n - 1];
	}

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
		{
			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			pairs.push_back(std::make_pair(b, a));
		}
	}

	std::vector<std::pair<std::pair<int, int>, size_t> > indexedPairs;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		indexedPairs.push_back(std::make_pair(pairs[i], i));
	}

	for (size_t i = 1; i < indexedPairs.size(); ++i)
	{
		std::pair<std::pair<int, int>, size_t> key = indexedPairs[i];
		size_t j = i;
		while (j > 0 && indexedPairs[j - 1].first.first > key.first.first)
		{
			indexedPairs[j] = indexedPairs[j - 1];
			--j;
		}
		indexedPairs[j] = key;
	}

	std::vector<int> sortedLarger;
	for (size_t i = 0; i < indexedPairs.size(); ++i)
	{
		sortedLarger.push_back(indexedPairs[i].first.first);
	}

	if (sortedLarger.size() > 1)
	{
		fordJohnsonVector(sortedLarger);
	}

	std::vector<std::pair<int, int> > sortedPairs;
	std::vector<bool> used(indexedPairs.size(), false);

	for (size_t i = 0; i < sortedLarger.size(); ++i)
	{
		for (size_t j = 0; j < indexedPairs.size(); ++j)
		{
			if (!used[j] && indexedPairs[j].first.first == sortedLarger[i])
			{
				sortedPairs.push_back(indexedPairs[j].first);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<int> mainChain;
	std::vector<int> pend;

	if (!sortedPairs.empty())
	{
		mainChain.push_back(sortedPairs[0].second);
		for (size_t i = 0; i < sortedPairs.size(); ++i)
		{
			mainChain.push_back(sortedPairs[i].first);
		}

		for (size_t i = 1; i < sortedPairs.size(); ++i)
		{
			pend.push_back(sortedPairs[i].second);
		}
	}

	if (hasStraggler)
	{
		pend.push_back(straggler);
	}

	if (!pend.empty())
	{
		std::vector<size_t> jacobsthal = generateJacobsthalSequence(pend.size() + 2);

		std::vector<size_t> insertionOrder;
		size_t inserted = 0;

		for (size_t k = 2; k < jacobsthal.size() && inserted < pend.size(); ++k)
		{
			size_t jk = jacobsthal[k];
			size_t jk_1 = jacobsthal[k - 1];

			size_t start = (jk <= pend.size()) ? jk : pend.size();
			for (size_t i = start; i > jk_1 && inserted < pend.size(); --i)
			{
				bool alreadyInserted = false;
				for (size_t m = 0; m < insertionOrder.size(); ++m)
				{
					if (insertionOrder[m] == i - 1)
					{
						alreadyInserted = true;
						break;
					}
				}
				if (!alreadyInserted && i - 1 < pend.size())
				{
					insertionOrder.push_back(i - 1);
					++inserted;
				}
			}
		}

		for (size_t i = 0; i < pend.size(); ++i)
		{
			bool found = false;
			for (size_t j = 0; j < insertionOrder.size(); ++j)
			{
				if (insertionOrder[j] == i)
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				insertionOrder.push_back(i);
			}
		}

		for (size_t i = 0; i < insertionOrder.size(); ++i)
		{
			size_t idx = insertionOrder[i];
			int value = pend[idx];
			size_t pos = binarySearchInsertPos(mainChain, value, mainChain.size());
			mainChain.insert(mainChain.begin() + static_cast<std::ptrdiff_t>(pos), value);
		}
	}

	arr = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1)
	{
		return;
	}

	if (n == 2)
	{
		if (arr[0] > arr[1])
		{
			std::swap(arr[0], arr[1]);
		}
		return;
	}

	std::deque<std::pair<int, int> > pairs;
	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;

	if (hasStraggler)
	{
		straggler = arr[n - 1];
	}

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
		{
			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			pairs.push_back(std::make_pair(b, a));
		}
	}

	std::deque<std::pair<std::pair<int, int>, size_t> > indexedPairs;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		indexedPairs.push_back(std::make_pair(pairs[i], i));
	}

	for (size_t i = 1; i < indexedPairs.size(); ++i)
	{
		std::pair<std::pair<int, int>, size_t> key = indexedPairs[i];
		size_t j = i;
		while (j > 0 && indexedPairs[j - 1].first.first > key.first.first)
		{
			indexedPairs[j] = indexedPairs[j - 1];
			--j;
		}
		indexedPairs[j] = key;
	}

	std::deque<int> sortedLarger;
	for (size_t i = 0; i < indexedPairs.size(); ++i)
	{
		sortedLarger.push_back(indexedPairs[i].first.first);
	}

	if (sortedLarger.size() > 1)
	{
		fordJohnsonDeque(sortedLarger);
	}

	std::deque<std::pair<int, int> > sortedPairs;
	std::deque<bool> used(indexedPairs.size(), false);

	for (size_t i = 0; i < sortedLarger.size(); ++i)
	{
		for (size_t j = 0; j < indexedPairs.size(); ++j)
		{
			if (!used[j] && indexedPairs[j].first.first == sortedLarger[i])
			{
				sortedPairs.push_back(indexedPairs[j].first);
				used[j] = true;
				break;
			}
		}
	}

	std::deque<int> mainChain;
	std::deque<int> pend;

	if (!sortedPairs.empty())
	{
		mainChain.push_back(sortedPairs[0].second);
		for (size_t i = 0; i < sortedPairs.size(); ++i)
		{
			mainChain.push_back(sortedPairs[i].first);
		}

		for (size_t i = 1; i < sortedPairs.size(); ++i)
		{
			pend.push_back(sortedPairs[i].second);
		}
	}

	if (hasStraggler)
	{
		pend.push_back(straggler);
	}

	if (!pend.empty())
	{
		std::vector<size_t> jacobsthal = generateJacobsthalSequence(pend.size() + 2);

		std::vector<size_t> insertionOrder;
		size_t inserted = 0;

		for (size_t k = 2; k < jacobsthal.size() && inserted < pend.size(); ++k)
		{
			size_t jk = jacobsthal[k];
			size_t jk_1 = jacobsthal[k - 1];

			size_t start = (jk <= pend.size()) ? jk : pend.size();
			for (size_t i = start; i > jk_1 && inserted < pend.size(); --i)
			{
				bool alreadyInserted = false;
				for (size_t m = 0; m < insertionOrder.size(); ++m)
				{
					if (insertionOrder[m] == i - 1)
					{
						alreadyInserted = true;
						break;
					}
				}
				if (!alreadyInserted && i - 1 < pend.size())
				{
					insertionOrder.push_back(i - 1);
					++inserted;
				}
			}
		}

		for (size_t i = 0; i < pend.size(); ++i)
		{
			bool found = false;
			for (size_t j = 0; j < insertionOrder.size(); ++j)
			{
				if (insertionOrder[j] == i)
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				insertionOrder.push_back(i);
			}
		}

		for (size_t i = 0; i < insertionOrder.size(); ++i)
		{
			size_t idx = insertionOrder[i];
			int value = pend[idx];
			size_t pos = binarySearchInsertPos(mainChain, value, mainChain.size());
			mainChain.insert(mainChain.begin() + static_cast<std::ptrdiff_t>(pos), value);
		}
	}

	arr = mainChain;
}

void PmergeMe::sort()
{
	struct timeval start, end;

	std::vector<int> vectorCopy = _vector;
	gettimeofday(&start, NULL);
	fordJohnsonVector(vectorCopy);
	gettimeofday(&end, NULL);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	_vector = vectorCopy;

	std::deque<int> dequeCopy = _deque;
	gettimeofday(&start, NULL);
	fordJohnsonDeque(dequeCopy);
	gettimeofday(&end, NULL);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	_deque = dequeCopy;
}

void PmergeMe::displayResults() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size() && i < 10; ++i)
	{
		std::cout << " " << _vector[i];
	}
	if (_vector.size() > 10)
	{
		std::cout << " [...]";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	std::vector<int> sorted = _vector;
	for (size_t i = 0; i < sorted.size() && i < 10; ++i)
	{
		std::cout << " " << sorted[i];
	}
	if (sorted.size() > 10)
	{
		std::cout << " [...]";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << _dequeTime << " us" << std::endl;
}

const std::vector<int>& PmergeMe::getVector() const
{
	return _vector;
}

const std::deque<int>& PmergeMe::getDeque() const
{
	return _deque;
}

double PmergeMe::getVectorTime() const
{
	return _vectorTime;
}

double PmergeMe::getDequeTime() const
{
	return _dequeTime;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return "Error";
}
