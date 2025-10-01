/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:40 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/01 16:09:53 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printHeader(const std::string &title) {
    std::cout << "========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

void testValidFormConstruction(void) {
    printHeader("TEST 1: Valid Form Construction");

    try {
	Form formA("Tax Form", 50, 25);
	std::cout << formA << std::endl;

	Form formB("Building Permit", 1, 1);
	std::cout << formB << std::endl;

	Form formC("Parking Ticket", 150, 150);
	std::cout << formC << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInvalidFormConstruction(void) {
    printHeader("TEST 2: Invalid Form Construction - Grades Out of Bounds");

    try {
	Form invalid1("Invalid1", 0, 50);
	std::cout << invalid1 << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Form invalid2("Invalid2", 50, 151);
	std::cout << invalid2 << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Form invalid3("Invalid3", -5, 100);
	std::cout << invalid3 << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testSuccessfulSigning(void) {
    printHeader("TEST 3: Successful Form Signing");

    try {
	Bureaucrat alice("Alice", 25);
	Form formA("Requisition Form", 50, 30);

	std::cout << alice << std::endl;
	std::cout << formA << std::endl;
	std::cout << "\nAttempting to sign...\n";

	alice.signForm(formA);
	std::cout << "\nAfter signing:\n" << formA << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFailedSigning(void) {
    printHeader("TEST 4: Failed Form Signing - Grade Too Low");

    try {
	Bureaucrat bob("Bob", 100);
	Form formB("Presidential Pardon", 25, 5);

	std::cout << bob << std::endl;
	std::cout << formB << std::endl;
	std::cout << "\nAttempting to sign...\n";

	bob.signForm(formB);
	std::cout << "\nAfter attempt:\n" << formB << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testBoundaryGrades(void) {
    printHeader("TEST 5: Boundary Grade Testing");

    try {
	Bureaucrat ceo("CEO", 1);
	Bureaucrat intern("Intern", 150);
	Form topForm("Executive Order", 1, 1);
	Form bottomForm("Intern Request", 150, 150);

	std::cout << "High-level signing:\n";
	ceo.signForm(topForm);
	std::cout << topForm << std::endl;

	std::cout << "\nLow-level signing:\n";
	intern.signForm(bottomForm);
	std::cout << bottomForm << std::endl;

	std::cout << "\nCross-testing:\n";
	intern.signForm(topForm);
	ceo.signForm(bottomForm);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testMultipleSigning(void) {
    printHeader("TEST 6: Multiple Signing Attempts");

    try {
	Bureaucrat manager("Manager", 30);
	Form contract("Employment Contract", 50, 25);

	std::cout << contract << std::endl;
	std::cout << "\nFirst signing attempt:\n";
	manager.signForm(contract);

	std::cout << "\nSecond signing attempt (already signed):\n";
	manager.signForm(contract);

	std::cout << "\n" << contract << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFormCopyAndAssignment(void) {
    printHeader("TEST 7: Form Copy and Assignment");

    try {
	Form original("Original Form", 40, 30);
	Bureaucrat signer("Signer", 35);

	std::cout << "Original: " << original << std::endl;

	signer.signForm(original);
	std::cout << "After signing: " << original << std::endl;

	Form copy(original);
	std::cout << "\nCopy: " << copy << std::endl;

	Form assigned("Assigned Form", 100, 100);
	std::cout << "Before assignment: " << assigned << std::endl;

	assigned = original;
	std::cout << "After assignment: " << assigned << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testEdgeCases(void) {
    printHeader("TEST 8: Edge Cases");

    try {
	Bureaucrat perfectMatch("PerfectMatch", 50);
	Form exactForm("Exact Requirements", 50, 40);

	std::cout << perfectMatch << std::endl;
	std::cout << exactForm << std::endl;
	std::cout << "\nBureaucrat with exact grade requirement:\n";
	perfectMatch.signForm(exactForm);
	std::cout << exactForm << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Bureaucrat oneTooLow("OneTooLow", 51);
	Form strictForm("Strict Form", 50, 40);

	std::cout << oneTooLow << std::endl;
	std::cout << strictForm << std::endl;
	std::cout << "\nBureaucrat one grade too low:\n";
	oneTooLow.signForm(strictForm);
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(void) {
    testValidFormConstruction();
    testInvalidFormConstruction();
    testSuccessfulSigning();
    testFailedSigning();
    testBoundaryGrades();
    testMultipleSigning();
    testFormCopyAndAssignment();
    testEdgeCases();

    printHeader("All tests completed!");

    return 0;
}
