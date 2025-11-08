/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 00:30:33 by peda-cos          #+#    #+#             */
/*   Updated: 2025/11/08 01:11:09 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
    std::srand(std::time(NULL));

    std::cout << "=== Test 1: Random generation and identification ==="
	      << std::endl;
    for (int i = 0; i < 5; i++) {
	std::cout << "\nTest " << i + 1 << ":" << std::endl;
	Base *ptr = generate();

	std::cout << "Identify by pointer: ";
	identify(ptr);

	std::cout << "Identify by reference: ";
	identify(*ptr);

	delete ptr;
    }

    std::cout << "\n=== Test 2: Specific types ===" << std::endl;

    std::cout << "\nTesting A:" << std::endl;
    Base *a = new A();
    std::cout << "Pointer identification: ";
    identify(a);
    std::cout << "Reference identification: ";
    identify(*a);
    delete a;

    std::cout << "\nTesting B:" << std::endl;
    Base *b = new B();
    std::cout << "Pointer identification: ";
    identify(b);
    std::cout << "Reference identification: ";
    identify(*b);
    delete b;

    std::cout << "\nTesting C:" << std::endl;
    Base *c = new C();
    std::cout << "Pointer identification: ";
    identify(c);
    std::cout << "Reference identification: ";
    identify(*c);
    delete c;

    std::cout << "\n=== Test 3: NULL pointer ===" << std::endl;
    Base *null_ptr = NULL;
    std::cout << "Identify NULL pointer: ";
    identify(null_ptr);

    return 0;
}
