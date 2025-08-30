/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:49:13 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:14:41 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap4;

	std::cout << "=== Creating ClapTrap instances ===" << std::endl;
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("FR4G-TP");
	std::cout << "\n=== Testing combat mechanics ===" << std::endl;
	std::cout << "\n--- Attack tests ---" << std::endl;
	clap1.attack("Skag");
	clap1.attack("Psycho");
	std::cout << "\n--- Damage tests ---" << std::endl;
	clap1.takeDamage(5);
	clap1.takeDamage(3);
	std::cout << "\n--- Repair tests ---" << std::endl;
	clap1.beRepaired(2);
	clap1.beRepaired(4);
	std::cout << "\n=== Testing resource depletion ===" << std::endl;
	std::cout << "\n--- Depleting energy points ---" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Attack #" << (i + 1) << ": ";
		clap2.attack("Target");
	}
	std::cout << "Energy depleted, this attack should fail silently: ";
	clap2.attack("Target");
	std::cout << "\n--- Taking fatal damage ---" << std::endl;
	clap2.takeDamage(15);
	std::cout << "Hit points depleted, this repair should fail silently: ";
	clap2.beRepaired(5);
	std::cout << "\n=== Testing copy constructor and assignment ===" << std::endl;
	ClapTrap clap3(clap1);
	clap3.attack("Bandit");
	clap4 = clap1;
	clap4.attack("Badass");
	std::cout << "\n=== End of tests ===" << std::endl;
	return (0);
}
