/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:40 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:25:14 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void printHeader(const std::string &title) {
    std::cout << "========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

void testShrubberyCreation(void) {
    printHeader("TEST 1: ShrubberyCreationForm");

    try {
	Bureaucrat intern("Intern", 140);
	ShrubberyCreationForm form("home");

	std::cout << intern << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nSigning the form...\n";
	intern.signForm(form);

	std::cout << "\nExecuting the form...\n";
	intern.executeForm(form);

	std::cout << "\nFile 'home_shrubbery' should be created.\n";
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testShrubberyFailedExecution(void) {
    printHeader("TEST 2: ShrubberyCreationForm - Failed Execution");

    try {
	Bureaucrat lowGrade("LowGrade", 145);
	ShrubberyCreationForm form("garden");

	std::cout << lowGrade << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nSigning the form...\n";
	lowGrade.signForm(form);

	std::cout << "\nAttempting to execute (grade too low)...\n";
	lowGrade.executeForm(form);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testRobotomyRequest(void) {
    printHeader("TEST 3: RobotomyRequestForm");

    try {
	Bureaucrat manager("Manager", 40);
	RobotomyRequestForm form("Bender");

	std::cout << manager << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nSigning the form...\n";
	manager.signForm(form);

	std::cout << "\nExecuting the form (50% chance)...\n";
	manager.executeForm(form);

	std::cout << "\nExecuting again...\n";
	manager.executeForm(form);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testRobotomyUnsigned(void) {
    printHeader("TEST 4: RobotomyRequestForm - Unsigned");

    try {
	Bureaucrat supervisor("Supervisor", 30);
	RobotomyRequestForm form("Marvin");

	std::cout << supervisor << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nAttempting to execute unsigned form...\n";
	supervisor.executeForm(form);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testPresidentialPardon(void) {
    printHeader("TEST 5: PresidentialPardonForm");

    try {
	Bureaucrat president("President", 1);
	PresidentialPardonForm form("Arthur Dent");

	std::cout << president << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nSigning the form...\n";
	president.signForm(form);

	std::cout << "\nExecuting the form...\n";
	president.executeForm(form);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testPresidentialPardonFailed(void) {
    printHeader("TEST 6: PresidentialPardonForm - Failed");

    try {
	Bureaucrat vicePresident("VicePresident", 10);
	PresidentialPardonForm form("Ford Prefect");

	std::cout << vicePresident << std::endl;
	std::cout << form << std::endl;

	std::cout << "\nAttempting to sign (grade too low)...\n";
	vicePresident.signForm(form);

	std::cout << "\nAttempting to execute...\n";
	vicePresident.executeForm(form);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testAllFormsSuccessful(void) {
    printHeader("TEST 7: All Forms Successfully Executed");

    try {
	Bureaucrat ceo("CEO", 1);

	ShrubberyCreationForm shrub("office");
	RobotomyRequestForm robot("Employee");
	PresidentialPardonForm pardon("Criminal");

	std::cout << ceo << std::endl;
	std::cout << "\n--- Shrubbery Form ---\n";
	std::cout << shrub << std::endl;
	ceo.signForm(shrub);
	ceo.executeForm(shrub);

	std::cout << "\n--- Robotomy Form ---\n";
	std::cout << robot << std::endl;
	ceo.signForm(robot);
	ceo.executeForm(robot);

	std::cout << "\n--- Presidential Pardon ---\n";
	std::cout << pardon << std::endl;
	ceo.signForm(pardon);
	ceo.executeForm(pardon);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testBoundaryGrades(void) {
    printHeader("TEST 8: Boundary Grade Testing");

    try {
	Bureaucrat exact145("Exact145", 145);
	ShrubberyCreationForm shrub("boundary");

	std::cout << exact145 << std::endl;
	std::cout << shrub << std::endl;
	std::cout << "\nSigning with exact grade requirement...\n";
	exact145.signForm(shrub);

	Bureaucrat exact137("Exact137", 137);
	std::cout << "\nExecuting with exact grade requirement...\n";
	exact137.executeForm(shrub);

    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment(void) {
    printHeader("TEST 9: Copy and Assignment");

    try {
	ShrubberyCreationForm original("original");
	Bureaucrat signer("Signer", 100);

	std::cout << "Original: " << original << std::endl;
	signer.signForm(original);

	ShrubberyCreationForm copy(original);
	std::cout << "Copy: " << copy << std::endl;
	std::cout << "Copy is signed: " << (copy.isSigned() ? "yes" : "no")
		  << std::endl;

	ShrubberyCreationForm assigned("assigned");
	std::cout << "\nBefore assignment: " << assigned << std::endl;
	assigned = original;
	std::cout << "After assignment: " << assigned << std::endl;
	std::cout << "Assigned is signed: "
		  << (assigned.isSigned() ? "yes" : "no") << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternBasic(void) {
    printHeader("TEST 10: Intern - Basic Form Creation");

    try {
	Intern someRandomIntern;
	AForm *rrf;

	std::cout << "\nCreating robotomy request form...\n";
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf) {
	    std::cout << *rrf << std::endl;
	    delete rrf;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternAllForms(void) {
    printHeader("TEST 11: Intern - All Form Types");

    Intern intern;
    AForm *forms[3];
    int i;

    try {
	std::cout << "\nCreating shrubbery creation form...\n";
	forms[0] = intern.makeForm("shrubbery creation", "garden");

	std::cout << "\nCreating robotomy request form...\n";
	forms[1] = intern.makeForm("robotomy request", "Marvin");

	std::cout << "\nCreating presidential pardon form...\n";
	forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << "\n--- Forms Created ---\n";
	for (i = 0; i < 3; i++) {
	    if (forms[i]) {
		std::cout << *forms[i] << std::endl;
	    }
	}

	std::cout << "\n--- Cleaning up ---\n";
	for (i = 0; i < 3; i++) {
	    delete forms[i];
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternInvalidForm(void) {
    printHeader("TEST 12: Intern - Invalid Form Name");

    try {
	Intern intern;
	AForm *form;

	std::cout << "\nAttempting to create non-existent form...\n";
	form = intern.makeForm("coffee making", "Kitchen");

	if (form) {
	    std::cout << *form << std::endl;
	    delete form;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternWithBureaucrat(void) {
    printHeader("TEST 13: Intern - Forms with Bureaucrat");

    try {
	Intern intern;
	Bureaucrat boss("Boss", 1);
	AForm *form;

	std::cout << "\nIntern creates form...\n";
	form = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");

	if (form) {
	    std::cout << "\n" << boss << std::endl;
	    std::cout << *form << std::endl;

	    std::cout << "\nBoss signs the form...\n";
	    boss.signForm(*form);

	    std::cout << "\nBoss executes the form...\n";
	    boss.executeForm(*form);

	    delete form;
	}
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternMultipleCreations(void) {
    printHeader("TEST 14: Intern - Multiple Form Creations");

    try {
	Intern intern;
	AForm *form1;
	AForm *form2;
	AForm *form3;

	std::cout << "\nCreating first robotomy request...\n";
	form1 = intern.makeForm("robotomy request", "Target1");

	std::cout << "\nCreating second robotomy request...\n";
	form2 = intern.makeForm("robotomy request", "Target2");

	std::cout << "\nCreating third robotomy request...\n";
	form3 = intern.makeForm("robotomy request", "Target3");

	std::cout << "\n--- All forms created ---\n";
	if (form1)
	    std::cout << *form1 << std::endl;
	if (form2)
	    std::cout << *form2 << std::endl;
	if (form3)
	    std::cout << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(void) {
    testShrubberyCreation();
    testShrubberyFailedExecution();
    testRobotomyRequest();
    testRobotomyUnsigned();
    testPresidentialPardon();
    testPresidentialPardonFailed();
    testAllFormsSuccessful();
    testBoundaryGrades();
    testCopyAndAssignment();

    std::cout << "\n\n";
    printHeader("=== INTERN TESTS ===");
    std::cout << "\n";

    testInternBasic();
    testInternAllForms();
    testInternInvalidForm();
    testInternWithBureaucrat();
    testInternMultipleCreations();

    printHeader("All tests completed!");

    return 0;
}
