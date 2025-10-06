/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:30:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:50:56 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
	std::cout << "Usage: ./convert <literal>" << std::endl;
	return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
