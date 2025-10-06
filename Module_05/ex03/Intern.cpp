/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:09:09 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:24:26 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void) {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(void) { std::cout << "Intern destructor called" << std::endl; }

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
			const std::string &target) {
    const std::string formNames[3] = {"presidential pardon", "robotomy request",
				      "shrubbery creation"};

    AForm *(Intern::*formCreators[3])(const std::string &) = {
	&Intern::createPresidentialPardonForm,
	&Intern::createRobotomyRequestForm,
	&Intern::createShrubberyCreationForm};

    for (int i = 0; i < 3; i++) {
	if (formName == formNames[i]) {
	    std::cout << "Intern creates " << formName << std::endl;
	    return (this->*formCreators[i])(target);
	}
    }

    std::cout << "Error: Form name \"" << formName << "\" does not exist"
	      << std::endl;
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what(void) const throw() {
    return "Form not found";
}
