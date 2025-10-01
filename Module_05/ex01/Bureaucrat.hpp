/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/01 15:56:23 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

    static const int _highestGrade = 1;
    static const int _lowestGrade = 150;

  public:
    Bureaucrat(void);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat(void);

    const std::string &getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);

    void signForm(Form &form);

    class GradeTooHighException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
