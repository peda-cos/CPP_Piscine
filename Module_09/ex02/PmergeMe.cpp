#include "PmergeMe.hpp"
#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include <algorithm>

PmergeMe::PairedElements::PairedElements() : larger(0), smaller(0)
{
}

PmergeMe::PairedElements::PairedElements(int first, int second) : larger(first), smaller(second)
{
}

PmergeMe::PairedElementsWithIndex::PairedElementsWithIndex()
	: elements(), originalIndex(0)
{
}

PmergeMe::PairedElementsWithIndex::PairedElementsWithIndex(const PairedElements& pairElements, size_t index)
	: elements(pairElements), originalIndex(index)
{
}

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

void PmergeMe::parseInputArguments(int argc, char* argv[])
{
	if (argc < 2)
	{
		throw InvalidInputException();
	}

	for (int argumentIndex = 1; argumentIndex < argc; ++argumentIndex)
	{
		std::string argumentText = argv[argumentIndex];
		if (argumentText.empty())
		{
			throw InvalidInputException();
		}

		for (size_t charIndex = 0; charIndex < argumentText.length(); ++charIndex)
		{
			if (argumentText[charIndex] < '0' || argumentText[charIndex] > '9')
			{
				throw InvalidInputException();
			}
		}

		char* parseEnd = NULL;
		long value = std::strtol(argumentText.c_str(), &parseEnd, 10);
		if (*parseEnd != '\0' || value < 0 || value > INT_MAX)
		{
			throw InvalidInputException();
		}

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
}

std::vector<size_t> PmergeMe::buildJacobsthalSequence(size_t upperBoundExclusive)
{
	std::vector<size_t> sequence;
	if (upperBoundExclusive == 0)
	{
		return sequence;
	}

	sequence.push_back(0);
	if (upperBoundExclusive == 1)
	{
		return sequence;
	}

	sequence.push_back(1);
	while (true)
	{
		size_t nextValue = sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2];
		if (nextValue >= upperBoundExclusive)
		{
			break;
		}
		sequence.push_back(nextValue);
	}

	return sequence;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t pendingCount)
{
	std::vector<size_t> order;
	if (pendingCount == 0)
	{
		return order;
	}

	std::vector<size_t> jacobsthalSequence = buildJacobsthalSequence(pendingCount + 2);
	std::vector<bool> scheduled(pendingCount, false);
	size_t scheduledCount = 0;

	for (size_t groupIndex = 2; groupIndex < jacobsthalSequence.size() && scheduledCount < pendingCount; ++groupIndex)
	{
		size_t currentJacob = jacobsthalSequence[groupIndex];
		size_t previousJacob = jacobsthalSequence[groupIndex - 1];
		size_t startIndex = currentJacob < pendingCount ? currentJacob : pendingCount;

		for (size_t pendingIndex = startIndex; pendingIndex > previousJacob && scheduledCount < pendingCount; --pendingIndex)
		{
			size_t index = pendingIndex - 1;
			if (!scheduled[index])
			{
				order.push_back(index);
				scheduled[index] = true;
				++scheduledCount;
			}
		}
	}

	for (size_t index = 0; index < pendingCount; ++index)
	{
		if (!scheduled[index])
		{
			order.push_back(index);
		}
	}

	return order;
}

bool PmergeMe::comparePairsByLargerElement(const PairedElementsWithIndex& left,
								   const PairedElementsWithIndex& right)
{
	return left.elements.larger < right.elements.larger;
}

std::vector<PmergeMe::PairedElements> PmergeMe::buildVectorPairs(
	const std::vector<int>& elements, bool& hasStraggler, int& stragglerValue)
{
	std::vector<PairedElements> pairs;
	hasStraggler = (elements.size() % 2) != 0;
	if (hasStraggler)
	{
		stragglerValue = elements[elements.size() - 1];
	}

	for (size_t index = 0; index + 1 < elements.size(); index += 2)
	{
		int first = elements[index];
		int second = elements[index + 1];
		if (first >= second)
		{
			pairs.push_back(PairedElements(first, second));
		}
		else
		{
			pairs.push_back(PairedElements(second, first));
		}
	}

	return pairs;
}

std::deque<PmergeMe::PairedElements> PmergeMe::buildDequePairs(
	const std::deque<int>& elements, bool& hasStraggler, int& stragglerValue)
{
	std::deque<PairedElements> pairs;
	hasStraggler = (elements.size() % 2) != 0;
	if (hasStraggler)
	{
		stragglerValue = elements[elements.size() - 1];
	}

	for (size_t index = 0; index + 1 < elements.size(); index += 2)
	{
		int first = elements[index];
		int second = elements[index + 1];
		if (first >= second)
		{
			pairs.push_back(PairedElements(first, second));
		}
		else
		{
			pairs.push_back(PairedElements(second, first));
		}
	}

	return pairs;
}

std::vector<PmergeMe::PairedElementsWithIndex> PmergeMe::indexVectorPairs(
	const std::vector<PairedElements>& pairs)
{
	std::vector<PairedElementsWithIndex> indexedPairs;
	indexedPairs.reserve(pairs.size());
	for (size_t index = 0; index < pairs.size(); ++index)
	{
		indexedPairs.push_back(PairedElementsWithIndex(pairs[index], index));
	}
	return indexedPairs;
}

std::deque<PmergeMe::PairedElementsWithIndex> PmergeMe::indexDequePairs(
	const std::deque<PairedElements>& pairs)
{
	std::deque<PairedElementsWithIndex> indexedPairs;
	for (size_t index = 0; index < pairs.size(); ++index)
	{
		indexedPairs.push_back(PairedElementsWithIndex(pairs[index], index));
	}
	return indexedPairs;
}

void PmergeMe::sortVectorPairsByLargerElement(std::vector<PairedElementsWithIndex>& indexedPairs)
{
	std::stable_sort(indexedPairs.begin(), indexedPairs.end(), comparePairsByLargerElement);
}

void PmergeMe::sortDequePairsByLargerElement(std::deque<PairedElementsWithIndex>& indexedPairs)
{
	std::stable_sort(indexedPairs.begin(), indexedPairs.end(), comparePairsByLargerElement);
}

std::vector<int> PmergeMe::extractVectorLargerElements(
	const std::vector<PairedElementsWithIndex>& indexedPairs)
{
	std::vector<int> largerElements;
	largerElements.reserve(indexedPairs.size());
	for (size_t index = 0; index < indexedPairs.size(); ++index)
	{
		largerElements.push_back(indexedPairs[index].elements.larger);
	}
	return largerElements;
}

std::deque<int> PmergeMe::extractDequeLargerElements(
	const std::deque<PairedElementsWithIndex>& indexedPairs)
{
	std::deque<int> largerElements;
	for (size_t index = 0; index < indexedPairs.size(); ++index)
	{
		largerElements.push_back(indexedPairs[index].elements.larger);
	}
	return largerElements;
}

std::vector<PmergeMe::PairedElements> PmergeMe::reorderVectorPairsByLarger(
	const std::vector<PairedElementsWithIndex>& indexedPairs,
	const std::vector<int>& sortedLargerElements)
{
	std::vector<PairedElements> orderedPairs;
	orderedPairs.reserve(indexedPairs.size());
	std::vector<bool> used(indexedPairs.size(), false);

	for (size_t valueIndex = 0; valueIndex < sortedLargerElements.size(); ++valueIndex)
	{
		int targetLarger = sortedLargerElements[valueIndex];
		for (size_t pairIndex = 0; pairIndex < indexedPairs.size(); ++pairIndex)
		{
			if (!used[pairIndex] && indexedPairs[pairIndex].elements.larger == targetLarger)
			{
				orderedPairs.push_back(indexedPairs[pairIndex].elements);
				used[pairIndex] = true;
				break;
			}
		}
	}

	return orderedPairs;
}

std::deque<PmergeMe::PairedElements> PmergeMe::reorderDequePairsByLarger(
	const std::deque<PairedElementsWithIndex>& indexedPairs,
	const std::deque<int>& sortedLargerElements)
{
	std::deque<PairedElements> orderedPairs;
	std::deque<bool> used(indexedPairs.size(), false);

	for (size_t valueIndex = 0; valueIndex < sortedLargerElements.size(); ++valueIndex)
	{
		int targetLarger = sortedLargerElements[valueIndex];
		for (size_t pairIndex = 0; pairIndex < indexedPairs.size(); ++pairIndex)
		{
			if (!used[pairIndex] && indexedPairs[pairIndex].elements.larger == targetLarger)
			{
				orderedPairs.push_back(indexedPairs[pairIndex].elements);
				used[pairIndex] = true;
				break;
			}
		}
	}

	return orderedPairs;
}

std::vector<int> PmergeMe::buildVectorMainChain(const std::vector<PairedElements>& sortedPairs)
{
	std::vector<int> mainChain;
	if (!sortedPairs.empty())
	{
		mainChain.reserve(sortedPairs.size() + 1);
		mainChain.push_back(sortedPairs[0].smaller);
		for (size_t index = 0; index < sortedPairs.size(); ++index)
		{
			mainChain.push_back(sortedPairs[index].larger);
		}
	}
	return mainChain;
}

std::deque<int> PmergeMe::buildDequeMainChain(const std::deque<PairedElements>& sortedPairs)
{
	std::deque<int> mainChain;
	if (!sortedPairs.empty())
	{
		mainChain.push_back(sortedPairs[0].smaller);
		for (size_t index = 0; index < sortedPairs.size(); ++index)
		{
			mainChain.push_back(sortedPairs[index].larger);
		}
	}
	return mainChain;
}

std::vector<int> PmergeMe::buildVectorPendingElements(
	const std::vector<PairedElements>& sortedPairs, bool hasStraggler, int stragglerValue)
{
	std::vector<int> pendingElements;
	if (sortedPairs.size() > 1)
	{
		pendingElements.reserve(sortedPairs.size());
		for (size_t index = 1; index < sortedPairs.size(); ++index)
		{
			pendingElements.push_back(sortedPairs[index].smaller);
		}
	}
	if (hasStraggler)
	{
		pendingElements.push_back(stragglerValue);
	}
	return pendingElements;
}

std::deque<int> PmergeMe::buildDequePendingElements(
	const std::deque<PairedElements>& sortedPairs, bool hasStraggler, int stragglerValue)
{
	std::deque<int> pendingElements;
	if (sortedPairs.size() > 1)
	{
		for (size_t index = 1; index < sortedPairs.size(); ++index)
		{
			pendingElements.push_back(sortedPairs[index].smaller);
		}
	}
	if (hasStraggler)
	{
		pendingElements.push_back(stragglerValue);
	}
	return pendingElements;
}

size_t PmergeMe::findVectorInsertPosition(const std::vector<int>& sortedChain, int value, size_t endIndex) const
{
	size_t left = 0;
	size_t right = endIndex;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sortedChain[mid] > value)
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

size_t PmergeMe::findDequeInsertPosition(const std::deque<int>& sortedChain, int value, size_t endIndex) const
{
	size_t left = 0;
	size_t right = endIndex;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (sortedChain[mid] > value)
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

void PmergeMe::insertVectorPendingElements(std::vector<int>& mainChain, const std::vector<int>& pendingElements)
{
	if (pendingElements.empty())
	{
		return;
	}

	std::vector<size_t> insertionOrder = buildInsertionOrder(pendingElements.size());
	for (size_t orderIndex = 0; orderIndex < insertionOrder.size(); ++orderIndex)
	{
		size_t pendingIndex = insertionOrder[orderIndex];
		int value = pendingElements[pendingIndex];
		size_t insertPosition = findVectorInsertPosition(mainChain, value, mainChain.size());
		mainChain.insert(mainChain.begin()
			+ static_cast<std::vector<int>::difference_type>(insertPosition), value);
	}
}

void PmergeMe::insertDequePendingElements(std::deque<int>& mainChain, const std::deque<int>& pendingElements)
{
	if (pendingElements.empty())
	{
		return;
	}

	std::vector<size_t> insertionOrder = buildInsertionOrder(pendingElements.size());
	for (size_t orderIndex = 0; orderIndex < insertionOrder.size(); ++orderIndex)
	{
		size_t pendingIndex = insertionOrder[orderIndex];
		int value = pendingElements[pendingIndex];
		size_t insertPosition = findDequeInsertPosition(mainChain, value, mainChain.size());
		mainChain.insert(mainChain.begin()
			+ static_cast<std::deque<int>::difference_type>(insertPosition), value);
	}
}

void PmergeMe::fordJohnsonVector(std::vector<int>& elements)
{
	if (elements.size() <= 1)
	{
		return;
	}

	if (elements.size() == 2)
	{
		if (elements[0] > elements[1])
		{
			std::swap(elements[0], elements[1]);
		}
		return;
	}

	bool hasStraggler = false;
	int stragglerValue = 0;
	std::vector<PairedElements> pairs = buildVectorPairs(elements, hasStraggler, stragglerValue);
	std::vector<PairedElementsWithIndex> indexedPairs = indexVectorPairs(pairs);

	sortVectorPairsByLargerElement(indexedPairs);

	std::vector<int> largerElements = extractVectorLargerElements(indexedPairs);
	if (largerElements.size() > 1)
	{
		fordJohnsonVector(largerElements);
	}

	std::vector<PairedElements> orderedPairs = reorderVectorPairsByLarger(indexedPairs, largerElements);
	std::vector<int> mainChain = buildVectorMainChain(orderedPairs);
	std::vector<int> pendingElements = buildVectorPendingElements(orderedPairs, hasStraggler, stragglerValue);

	insertVectorPendingElements(mainChain, pendingElements);

	elements = mainChain;
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& elements)
{
	if (elements.size() <= 1)
	{
		return;
	}

	if (elements.size() == 2)
	{
		if (elements[0] > elements[1])
		{
			std::swap(elements[0], elements[1]);
		}
		return;
	}

	bool hasStraggler = false;
	int stragglerValue = 0;
	std::deque<PairedElements> pairs = buildDequePairs(elements, hasStraggler, stragglerValue);
	std::deque<PairedElementsWithIndex> indexedPairs = indexDequePairs(pairs);

	sortDequePairsByLargerElement(indexedPairs);

	std::deque<int> largerElements = extractDequeLargerElements(indexedPairs);
	if (largerElements.size() > 1)
	{
		fordJohnsonDeque(largerElements);
	}

	std::deque<PairedElements> orderedPairs = reorderDequePairsByLarger(indexedPairs, largerElements);
	std::deque<int> mainChain = buildDequeMainChain(orderedPairs);
	std::deque<int> pendingElements = buildDequePendingElements(orderedPairs, hasStraggler, stragglerValue);

	insertDequePendingElements(mainChain, pendingElements);

	elements = mainChain;
}

void PmergeMe::sort()
{
	struct timeval startTime;
	struct timeval endTime;

	std::vector<int> vectorCopy = _vector;
	gettimeofday(&startTime, NULL);
	fordJohnsonVector(vectorCopy);
	gettimeofday(&endTime, NULL);
	_vectorTime = (endTime.tv_sec - startTime.tv_sec) * 1000000.0
		+ (endTime.tv_usec - startTime.tv_usec);
	_vector = vectorCopy;

	std::deque<int> dequeCopy = _deque;
	gettimeofday(&startTime, NULL);
	fordJohnsonDeque(dequeCopy);
	gettimeofday(&endTime, NULL);
	_dequeTime = (endTime.tv_sec - startTime.tv_sec) * 1000000.0
		+ (endTime.tv_usec - startTime.tv_usec);
	_deque = dequeCopy;
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
