/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:52:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:34:09 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void separator(const std::string& title) {
    std::cout << "\n==== " << title << " ====\n";
}

int main() {
    separator("Subject Basic Test");
    {
        // Animal is now abstract (makeSound is pure virtual). Instantiate derived classes only.
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        delete j;
        delete i;
    }

    separator("Polymorphic Array Test");
    {
        const size_t N = 4;
        const Animal* zoo[N];
        for (size_t idx = 0; idx < N; ++idx) {
            if (idx % 2 == 0) zoo[idx] = new Dog();
            else              zoo[idx] = new Cat();
        }
        for (size_t idx = 0; idx < N; ++idx) {
            std::cout << idx << ": " << zoo[idx]->getType() << " -> ";
            zoo[idx]->makeSound();
        }
        for (size_t idx = 0; idx < N; ++idx)
            delete zoo[idx];
    }

    separator("Copy Semantics Test");
    {
        Dog a;
        Dog b(a);
        Dog c; c = b;
        std::cout << "Types: a=" << a.getType() << ", b=" << b.getType() << ", c=" << c.getType() << std::endl;
        Cat x;
        Cat y(x);
        Cat z; z = y;
        std::cout << "Types: x=" << x.getType() << ", y=" << y.getType() << ", z=" << z.getType() << std::endl;
    }

    separator("WrongAnimal Polymorphism Failure Demo");
    {
        const WrongAnimal* w = new WrongCat();
        w->makeSound();
        delete w;
        WrongCat wc;
        wc.makeSound();
    }

    separator("Done");
    return 0;
}
