/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:09:02 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:24:23 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
  private:
    AForm *createPresidentialPardonForm(const std::string &target);
    AForm *createRobotomyRequestForm(const std::string &target);
    AForm *createShrubberyCreationForm(const std::string &target);

  public:
    Intern(void);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern(void);

    AForm *makeForm(const std::string &formName, const std::string &target);

    class FormNotFoundException : public std::exception {
      public:
	virtual const char *what(void) const throw();
    };
};

#endif
