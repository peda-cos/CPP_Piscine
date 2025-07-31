/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:59:17 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 16:07:53 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl	harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	std::cout << "[ UNKNOWN ]" << std::endl;
	harl.complain("UNKNOWN");
	return (0);
}
