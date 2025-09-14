/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:50:03 by peda-cos          #+#    #+#             */
/*   Updated: 2025/09/02 03:23:56 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "[Dog] Default constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Dog] Copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "[Dog] Copy assignment" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (!this->brain)
			this->brain = new Brain(*other.brain);
		else
			*(this->brain) = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	if (brain)
		brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const
{
	if (brain)
		return (brain->getIdea(index));
	static const std::string empty = "";
	return (empty);
}

void Dog::printIdeas(int start, int count) const
{
	if (brain)
		brain->printIdeas(start, count);
}
