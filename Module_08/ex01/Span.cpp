#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Span is full");
	_numbers.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(max - min);
}
