/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:52:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/31 12:28:43 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	separator(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n";
}

int	main(void)
{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j;
		delete i;
		const size_t N = 4;
		const Animal *zoo[N];
			delete zoo[idx];
		Dog a;
		Dog c;
		Cat x;
		Cat z;
		const WrongAnimal *w = new WrongCat();
		delete w;
		WrongCat wc;

	separator("Subject Basic Test");
	{
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
	}
	separator("Polymorphic Array Test");
	{
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
	}
	separator("Copy Semantics Test");
	{
		Dog b(a);
		c = b;
		std::cout << "Types: a=" << a.getType() << ", b=" << b.getType() << ", c=" << c.getType() << std::endl;
		Cat y(x);
		z = y;
		std::cout << "Types: x=" << x.getType() << ", y=" << y.getType() << ", z=" << z.getType() << std::endl;
	}
	separator("WrongAnimal Polymorphism Failure Demo");
	{
		w->makeSound();
		wc.makeSound();
	}
	separator("Done");
	return (0);
}
