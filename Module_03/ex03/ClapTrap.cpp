/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 09:49:17 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 10:19:52 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
		return;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			  << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		return;
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
		return;
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}

const std::string &ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHP() const { return _hitPoints; }
unsigned int ClapTrap::getEP() const { return _energyPoints; }
unsigned int ClapTrap::getAD() const { return _attackDamage; }
