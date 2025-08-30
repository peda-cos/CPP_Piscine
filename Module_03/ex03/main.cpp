/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:15:08 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:20:47 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

static void section(const std::string &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	section("Construction chain");
	DiamondTrap d1("Shiny");
	DiamondTrap d2("Hybrid");
	DiamondTrap d3(d1);
	d2 = d1;

	section("Identity test");
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();

	section("Attack delegation (ScavTrap version)");
	d1.attack("target dummy");

	section("Attributes check via actions");
	// Show energy consumption (should start at 50) and HP (100)
	for (int i = 0; i < 5; ++i)
		d1.attack("bot");
	d1.takeDamage(40);
	d1.beRepaired(10);
	d1.takeDamage(80); // fatal
	d1.attack("ghost"); // silent
	d1.whoAmI(); // still prints names

	section("Destruction follows");
	return 0;
}
