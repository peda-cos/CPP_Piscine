/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:30:45 by peda-cos          #+#    #+#             */
/*   Updated: 2025/07/31 08:05:26 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int count;
	int oldestIndex;

	std::string truncate(const std::string &str) const;
	void displayHeader() const;
	void displayContactRow(int index) const;

public:
	PhoneBook();

	void addContact(const Contact &contact);
	void searchContacts() const;
	bool displayContact(int index) const;
	int getCount() const;
};

#endif
