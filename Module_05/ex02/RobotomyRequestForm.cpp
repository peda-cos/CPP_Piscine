/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:20:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/02 02:42:12 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy Request", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
	AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);

    std::cout << "* DRILLING NOISES: BZZZZZZZ WRRRRRR BZZZZZZZ *" << std::endl;

    static bool seeded = false;
    if (!seeded) {
	std::srand(std::time(NULL));
	seeded = true;
    }

    if (std::rand() % 2 == 0) {
	std::cout << _target << " has been robotomized successfully!"
		  << std::endl;
    } else {
	std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}
