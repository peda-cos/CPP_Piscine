/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:41 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 11:27:14 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : count(0), oldestIndex(0)
{
}

std::string PhoneBook::truncate(const std::string &str) const
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

void PhoneBook::displayHeader() const
{
	std::cout << "|" << std::setw(10) << "Index"
				<< "|";
	std::cout << std::setw(10) << "First Name"
				<< "|";
	std::cout << std::setw(10) << "Last Name"
				<< "|";
	std::cout << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw(10) << "-"
				<< "|";
	std::cout << std::setw(10) << "-"
				<< "|";
	std::cout << std::setw(10) << "-"
				<< "|";
	std::cout << std::setw(10) << "-"
				<< "|" << std::endl;
	std::cout << std::setfill(' ');
}

void PhoneBook::displayContactRow(int index) const
{
	std::cout << "|" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << truncate(contacts[index].getNickname()) << "|" << std::endl;
}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[oldestIndex] = contact;
	oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
	if (count < MAX_CONTACTS)
	{
		count++;
	}
}

void PhoneBook::searchContacts() const
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	displayHeader();
	for (int i = 0; i < count; i++)
	{
		displayContactRow(i);
	}
	int index;
	std::cout << "\nEnter index of contact to display: ";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return ;
	}
	std::cin.ignore(10000, '\n');
	if (!displayContact(index))
	{
		std::cout << "Invalid index." << std::endl;
	}
}

bool PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= count)
	{
		return (false);
	}
	std::cout << "\nContact details:" << std::endl;
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	return (true);
}

int PhoneBook::getCount() const
{
	return (count);
}
