/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:00:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/09/10 20:34:43 by peda-cos         ###   ########.fr       */
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

static void	testArray(void)
{
	const int	kCount = 10;
	Animal		*animals[kCount];

	separator("Animal Array Allocation/Deletion");
	for (int i = 0; i < kCount; ++i)
	{
		if (i < kCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < kCount; ++i)
	{
		animals[i]->makeSound();
	}
	for (int i = 0; i < kCount; ++i)
	{
		delete animals[i];
	}
}

static void	testDeepCopyDog(void)
{
	Dog	a;
	Dog	c;

	separator("Dog Deep Copy");
	a.setIdea(0, "Chase cats");
	Dog b(a);
	std::cout << "Original idea[0]: " << a.getIdea(0) << std::endl;
	std::cout << "Copy idea[0]:     " << b.getIdea(0) << std::endl;
	a.setIdea(0, "Sleep");
	std::cout << "After change original idea[0]: " << a.getIdea(0) << std::endl;
	std::cout << "Copy still idea[0]:            " << b.getIdea(0) << std::endl;
	c = a;
	std::cout << "Assigned idea[0]: " << c.getIdea(0) << std::endl;
	a.setIdea(1, "Eat");
	std::cout << "Original idea[1]: " << a.getIdea(1) << std::endl;
	std::cout << "Assigned idea[1]: " << c.getIdea(1) << std::endl;
}

static void	testDeepCopyCat(void)
{
	Cat	a;
	Cat	c;

	separator("Cat Deep Copy");
	a.setIdea(0, "Ignore humans");
	Cat b(a);
	std::cout << "Original idea[0]: " << a.getIdea(0) << std::endl;
	std::cout << "Copy idea[0]:     " << b.getIdea(0) << std::endl;
	a.setIdea(0, "Knock objects");
	std::cout << "After change original idea[0]: " << a.getIdea(0) << std::endl;
	std::cout << "Copy still idea[0]:            " << b.getIdea(0) << std::endl;
	c = a;
	std::cout << "Assigned idea[0]: " << c.getIdea(0) << std::endl;
	a.setIdea(1, "Sleep");
	std::cout << "Original idea[1]: " << a.getIdea(1) << std::endl;
	std::cout << "Assigned idea[1]: " << c.getIdea(1) << std::endl;
	a.printIdeas(0, 2);
	b.printIdeas(0, 2);
	a.printIdeas(0, 2);
	b.printIdeas(0, 2);
}

static void	subjectSample(void)
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	delete			i;

	separator("Subject Sample");
	delete j;
}

static void	testEdgeCases(void)
{
	separator("Edge Cases");
	{
		std::cout << "-- Dog self-assignment --" << std::endl;
		Dog d;
		d.setIdea(0, "Guard the house");
		{
			Dog tmp = d;
			d = tmp;
		}
		std::cout << "Idea[0] after self-assign: " << d.getIdea(0) << std::endl;
	}
	{
		std::cout << "-- Dog fresh copy divergence --" << std::endl;
		Dog a;
		Dog b(a);
		a.setIdea(0, "A idea");
		b.setIdea(0, "B idea");
		std::cout << "A idea[0]: " << a.getIdea(0) << " | B idea[0]: " << b.getIdea(0) << std::endl;
	}
	{
		std::cout << "-- Dog chained assignment --" << std::endl;
		Dog x; x.setIdea(0, "X0");
		Dog y; y.setIdea(0, "Y0");
		Dog z; z.setIdea(0, "Z0");
		y = x;
		z = y;
		x.setIdea(0, "X1");
		std::cout << "x idea[0]: " << x.getIdea(0) << std::endl;
		std::cout << "y idea[0]: " << y.getIdea(0) << std::endl;
		std::cout << "z idea[0]: " << z.getIdea(0) << std::endl;
	}
	{
		std::cout << "-- Cat self-assignment --" << std::endl;
		Cat c;
		c.setIdea(0, "Ignore everyone");
		{
			Cat tmp = c;
			c = tmp;
		}
		std::cout << "Cat idea[0] after self-assign: " << c.getIdea(0) << std::endl;
	}
	{
		std::cout << "-- Cat chained assignment --" << std::endl;
		Cat a; a.setIdea(0, "Nap");
		Cat b; b.setIdea(0, "Eat");
		Cat c; c.setIdea(0, "Play");
		b = a;
		c = b;
		a.setIdea(0, "Hunt");
		std::cout << "a idea[0]: " << a.getIdea(0) << std::endl;
		std::cout << "b idea[0]: " << b.getIdea(0) << std::endl;
		std::cout << "c idea[0]: " << c.getIdea(0) << std::endl;
	}
}

int	main(void)
{
	subjectSample();
	testArray();
	testDeepCopyDog();
	testDeepCopyCat();
	testEdgeCases();
	separator("Done");
	return (0);
}
