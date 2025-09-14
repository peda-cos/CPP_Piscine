/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 01:53:42 by peda-cos          #+#    #+#             */
/*   Updated: 2025/09/02 03:15:07 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "[Brain] Copy constructor" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "[Brain] Copy assignment" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const
{
	static const std::string empty = "";
	if (index < 0 || index >= 100)
		return (empty);
	return (ideas[index]);
}

void Brain::printIdeas(int start, int count) const
{
	if (start < 0)
		start = 0;
	if (count < 0)
		count = 0;
	if (start >= 100 || count == 0)
		return ;
	if (start + count > 100)
		count = 100 - start;
	for (int i = 0; i < count; ++i)
	{
		int idx = start + i;
		if (!ideas[idx].empty())
			std::cout << "[Brain] idea[" << idx << "]: " << ideas[idx] << std::endl;
	}
}
