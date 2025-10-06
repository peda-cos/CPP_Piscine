/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:15:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/02 02:44:34 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
	AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);

    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
	throw std::runtime_error("Failed to create file");
    }

    outfile << "       ###\n";
    outfile << "      #o###\n";
    outfile << "    #####o###\n";
    outfile << "   #o#\\#|#/###\n";
    outfile << "    ###\\|/#o#\n";
    outfile << "     # }|{  #\n";
    outfile << "       }|{\n";
    outfile << "\n";
    outfile << "      /\\___/\\\n";
    outfile << "     /       \\\n";
    outfile << "    /  o   o  \\\n";
    outfile << "   (  ==  ^  == )\n";
    outfile << "    )         (\n";
    outfile << "   (           )\n";
    outfile << "  ( (  )   (  ) )\n";
    outfile << " (__(__)___(__)__)\n";
    outfile << "\n";
    outfile << "        _-_\n";
    outfile << "     /~~   ~~\\\n";
    outfile << "  /~~         ~~\\\n";
    outfile << " {               }\n";
    outfile << "  \\  _-     -_  /\n";
    outfile << "    ~  \\\\ //  ~\n";
    outfile << " _- -   | | _- _\n";
    outfile << "   _ -  | |   -_\n";
    outfile << "       // \\\\\n";

    outfile.close();
}
