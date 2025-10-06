/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:47:16 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/02 02:42:01 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
    : _name("Default Form"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade)
	throw GradeTooHighException();
    if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade)
	throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
	_signed = other._signed;
    }
    return *this;
}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const { return _name; }

bool AForm::isSigned(void) const { return _signed; }

int AForm::getGradeToSign(void) const { return _gradeToSign; }

int AForm::getGradeToExecute(void) const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
	throw GradeTooLowException();
    _signed = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const {
    if (!_signed)
	throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
	throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what(void) const throw() {
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
    return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what(void) const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form " << form.getName()
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
