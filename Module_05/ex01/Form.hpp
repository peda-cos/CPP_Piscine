/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:46:57 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/01 16:02:16 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

    static const int _highestGrade = 1;
    static const int _lowestGrade = 150;

  public:
    Form(void);
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form(void);

    const std::string &getName(void) const;
    bool isSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
