#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <exception>
#include <utility>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	double _vectorTime;
	double _dequeTime;

	static std::vector<size_t> generateJacobsthalSequence(size_t n);

	void fordJohnsonVector(std::vector<int>& arr);
	void fordJohnsonDeque(std::deque<int>& arr);

	template<typename Container>
	size_t binarySearchInsertPos(const Container& sorted, int value, size_t end);

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseInput(int argc, char* argv[]);
	void sort();
	void displayResults() const;

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
