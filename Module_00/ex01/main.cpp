/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 07:57:19 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 11:26:17 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

std::string getInput(const std::string &prompt)
{
	bool	valid;

	std::string input;
	valid = false;
	while (!valid)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nExiting program due to EOF." << std::endl;
			exit(0);
		}
		if (!input.empty())
		{
			valid = true;
		}
		else
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
		}
	}
	return (input);
}

int	main(void)
{
	PhoneBook	phoneBook;
	Contact		newContact;

	std::string command;
	std::cout << "Welcome to the PhoneBook program!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	while (true)
	{
		std::cout << "\nEnter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nExiting program due to EOF." << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			newContact.setFirstName(getInput("Enter first name: "));
			newContact.setLastName(getInput("Enter last name: "));
			newContact.setNickname(getInput("Enter nickname: "));
			newContact.setPhoneNumber(getInput("Enter phone number: "));
			newContact.setDarkestSecret(getInput("Enter darkest secret: "));
			if (newContact.isComplete())
			{
				phoneBook.addContact(newContact);
				std::cout << "Contact added successfully!" << std::endl;
			}
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the PhoneBook program. Goodbye!" << std::endl;
			break ;
		}
		else
		{
		}
	}
	return (0);
}
