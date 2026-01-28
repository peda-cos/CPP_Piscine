#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <cstddef>

class PmergeMe
{
private:
	struct PairedElements
	{
		int larger;
		int smaller;
		PairedElements();
		PairedElements(int first, int second);
	};

	struct PairedElementsWithIndex
	{
		PairedElements elements;
		size_t originalIndex;
		PairedElementsWithIndex();
		PairedElementsWithIndex(const PairedElements& pairElements, size_t index);
	};

	std::vector<int> _vector;
	std::deque<int> _deque;
	double _vectorTime;
	double _dequeTime;

	static std::vector<size_t> buildJacobsthalSequence(size_t upperBoundExclusive);
	static std::vector<size_t> buildInsertionOrder(size_t pendingCount);

	static bool comparePairsByLargerElement(const PairedElementsWithIndex& left,
								   const PairedElementsWithIndex& right);

	std::vector<PairedElements> buildVectorPairs(const std::vector<int>& elements,
										bool& hasStraggler, int& stragglerValue);
	std::deque<PairedElements> buildDequePairs(const std::deque<int>& elements,
										bool& hasStraggler, int& stragglerValue);

	std::vector<PairedElementsWithIndex> indexVectorPairs(const std::vector<PairedElements>& pairs);
	std::deque<PairedElementsWithIndex> indexDequePairs(const std::deque<PairedElements>& pairs);

	void sortVectorPairsByLargerElement(std::vector<PairedElementsWithIndex>& indexedPairs);
	void sortDequePairsByLargerElement(std::deque<PairedElementsWithIndex>& indexedPairs);

	std::vector<int> extractVectorLargerElements(const std::vector<PairedElementsWithIndex>& indexedPairs);
	std::deque<int> extractDequeLargerElements(const std::deque<PairedElementsWithIndex>& indexedPairs);

	std::vector<PairedElements> reorderVectorPairsByLarger(
		const std::vector<PairedElementsWithIndex>& indexedPairs,
		const std::vector<int>& sortedLargerElements);
	std::deque<PairedElements> reorderDequePairsByLarger(
		const std::deque<PairedElementsWithIndex>& indexedPairs,
		const std::deque<int>& sortedLargerElements);

	std::vector<int> buildVectorMainChain(const std::vector<PairedElements>& sortedPairs);
	std::deque<int> buildDequeMainChain(const std::deque<PairedElements>& sortedPairs);

	std::vector<int> buildVectorPendingElements(const std::vector<PairedElements>& sortedPairs,
										bool hasStraggler, int stragglerValue);
	std::deque<int> buildDequePendingElements(const std::deque<PairedElements>& sortedPairs,
										bool hasStraggler, int stragglerValue);

	size_t findVectorInsertPosition(const std::vector<int>& sortedChain, int value, size_t endIndex) const;
	size_t findDequeInsertPosition(const std::deque<int>& sortedChain, int value, size_t endIndex) const;

	void insertVectorPendingElements(std::vector<int>& mainChain, const std::vector<int>& pendingElements);
	void insertDequePendingElements(std::deque<int>& mainChain, const std::deque<int>& pendingElements);

	void fordJohnsonVector(std::vector<int>& elements);
	void fordJohnsonDeque(std::deque<int>& elements);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseInputArguments(int argc, char* argv[]);
	void sort();

	const std::vector<int>& getVector() const;
	const std::deque<int>& getDeque() const;
	double getVectorTime() const;
	double getDequeTime() const;

	class InvalidInputException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
