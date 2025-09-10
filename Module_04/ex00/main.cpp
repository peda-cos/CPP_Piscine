/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:52:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/09/10 20:26:37 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string &title)
{
	std::cout << "\n==== " << title << " ====" << std::endl;
}

int main()
{
	separator("Subject Basic Test");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	separator("Polymorphic Array Test");
	const size_t N = 4;
	const Animal* zoo[N];
	for (size_t idx = 0; idx < N; ++idx)
	{
		if (idx % 2 == 0)
			zoo[idx] = new Dog();
		else
			zoo[idx] = new Cat();
	}
	for (size_t idx = 0; idx < N; ++idx)
	{
		std::cout << idx << ": " << zoo[idx]->getType() << " -> ";
		zoo[idx]->makeSound();
	}
	for (size_t idx = 0; idx < N; ++idx)
		delete zoo[idx];

	separator("WrongAnimal Polymorphism Failure Demo");
	const WrongAnimal* w = new WrongCat();
	const WrongCat wc;
	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	wc.makeSound();
	delete w;

	separator("Done");
	return (0);
}
