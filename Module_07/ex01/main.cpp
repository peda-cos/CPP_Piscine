/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:43:12 by peda-cos          #+#    #+#             */
/*   Updated: 2025/11/08 02:00:44 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main() {
    std::cout << "Test with int array:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << "Print: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Increment and print: ";
    iter(intArray, 5, increment<int>);
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    return 0;
}

