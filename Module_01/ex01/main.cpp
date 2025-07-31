/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:30:36 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 15:04:07 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		hordeSize;
	Zombie	*zombies;

	hordeSize = 5;
	zombies = zombieHorde(hordeSize, "Walker");
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie #" << i + 1 << ": ";
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}
