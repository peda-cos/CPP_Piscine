/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:47:58 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/31 12:26:52 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "(generic animal sound)" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
