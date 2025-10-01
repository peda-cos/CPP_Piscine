/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:47:16 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/01 15:56:18 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
    : _name("Default Form"), _signed(false), _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade)
	throw GradeTooHighException();
    if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade)
	throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
	_signed = other._signed;
    }
    return *this;
}

Form::~Form(void) {}

const std::string &Form::getName(void) const { return _name; }

bool Form::isSigned(void) const { return _signed; }

int Form::getGradeToSign(void) const { return _gradeToSign; }

int Form::getGradeToExecute(void) const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
	throw GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form " << form.getName()
       << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
