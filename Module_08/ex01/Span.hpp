#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

	Span();

public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void			addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		unsigned int count = std::distance(begin, end);
		if (_numbers.size() + count > _maxSize)
			throw std::out_of_range("Not enough space to add all numbers");
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif
