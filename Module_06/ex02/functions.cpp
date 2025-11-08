/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:30:39 by peda-cos          #+#    #+#             */
/*   Updated: 2025/11/08 01:11:08 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
    int random = std::rand() % 3;

    switch (random) {
    case 0:
	std::cout << "Generated type A" << std::endl;
	return new A();
    case 1:
	std::cout << "Generated type B" << std::endl;
	return new B();
    case 2:
	std::cout << "Generated type C" << std::endl;
	return new C();
    default:
	return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
	std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
	std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
	std::cout << "C" << std::endl;
    else
	std::cout << "Unknown type" << std::endl;
}

void identify(Base &p) {
    try {
	(void)dynamic_cast<A &>(p);
	std::cout << "A" << std::endl;
	return;
    } catch (std::exception &) {
    }

    try {
	(void)dynamic_cast<B &>(p);
	std::cout << "B" << std::endl;
	return;
    } catch (std::exception &) {
    }

    try {
	(void)dynamic_cast<C &>(p);
	std::cout << "C" << std::endl;
	return;
    } catch (std::exception &) {
    }

    std::cout << "Unknown type" << std::endl;
}
