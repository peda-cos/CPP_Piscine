#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;

public:
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Index out of bounds";
		}
	};

	Array();
	Array(unsigned int n);
	Array(Array const &src);
	Array &operator=(Array const &rhs);
	~Array();

	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

	unsigned int size() const;
};

#include "Array.tpp"

#endif
