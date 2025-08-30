/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:06:43 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:15:58 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap s1("Serena");
		ScavTrap s2("Guardian");
		ScavTrap s3(s1);
		s2 = s1;

		std::cout << "\n=== Basic actions ===" << std::endl;
		s1.attack("target dummy");
		s2.guardGate();
		s3.attack("bandit");

		std::cout << "\n=== Energy depletion (condensed) ===" << std::endl;
		// Perform enough attacks to exhaust energy (50 attacks) then one extra silent
		for (int i = 1; i <= 51; ++i)
		{
			bool shouldLabel = (i <= 3) || (i % 10 == 0) || (i > 47 && i <= 50); // exclude 51 (silent)
			if (shouldLabel)
				std::cout << "[Attack " << i << "] ";
			s1.attack("intruder");
		}
		std::cout << "(Attacks 4..47 omitted for brevity)" << std::endl;

		// Repair attempt after depletion (should fail silently if energy 0 or hp 0)
		std::cout << "Attempt repair after energy depletion (should be silent if no energy):" << std::endl;
		s1.beRepaired(10);

		std::cout << "\n=== Damage and fatal damage ===" << std::endl;
		s2.takeDamage(30);
		s2.takeDamage(80); // exceed remaining hp
		std::cout << "Attempt attack after HP zero (should be silent):" << std::endl;
		s2.attack("nobody"); // should fail silently if hp 0
		// Guard gate after death (still allowed? design choice: allowed)
		s2.guardGate();
	}
	// Destruction order will show reverse chain
	return 0;
}
