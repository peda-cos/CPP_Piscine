/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:46:57 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/02 02:41:59 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

    static const int _highestGrade = 1;
    static const int _lowestGrade = 150;

  protected:
    void checkExecution(const Bureaucrat &executor) const;

  public:
    AForm(void);
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);

    const std::string &getName(void) const;
    bool isSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };

    class FormNotSignedException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
