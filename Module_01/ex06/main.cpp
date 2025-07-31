/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:11:22 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 16:21:14 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
		std::cerr << "Valid levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return (1);
	}
	harl.filter(argv[1]);
	return (0);
}
