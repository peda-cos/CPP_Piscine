/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:10:53 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:17:51 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

static void section(const std::string &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	section("Construction chain");
	FragTrap f1("Fraggy");
	FragTrap f2("Blaster");
	FragTrap f3(f1);
	f2 = f1;

	section("High five ability");
	f1.highFivesGuys();
	f2.highFivesGuys();

	section("Basic combat");
	f1.attack("target dummy");
	f1.takeDamage(25);
	f1.beRepaired(10);
	f1.takeDamage(90); // fatal
	f1.attack("ghost"); // silent (dead)
	f1.highFivesGuys(); // allowed even if dead (no restriction specified)

	section("Energy consumption");
	for (int i = 0; i < 100; ++i)
		f2.attack("bot");
	f2.attack("bot"); // silent
	f2.highFivesGuys(); // still works

	section("Destruction chain follows automatically");
	return 0;
}
