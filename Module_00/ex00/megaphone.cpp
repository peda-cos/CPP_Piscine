/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:12:26 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/10 16:53:25 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg(argv[i]);
			for (std::string::size_type j = 0; j < arg.length(); j++)
				std::cout << static_cast<char>(std::toupper(arg[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}
