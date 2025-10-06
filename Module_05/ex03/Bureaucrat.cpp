/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:35 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/02 02:42:05 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < _highestGrade)
	throw GradeTooHighException();
    if (grade > _lowestGrade)
	throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
	_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

const std::string &Bureaucrat::getName(void) const { return _name; }

int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
    if (_grade - 1 < _highestGrade)
	throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade + 1 > _lowestGrade)
	throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) {
    try {
	form.beSigned(*this);
	std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
	std::cout << _name << " couldn't sign " << form.getName() << " because "
		  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
	form.execute(*this);
	std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
	std::cout << _name << " couldn't execute " << form.getName()
		  << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
       << ".";
    return os;
}
