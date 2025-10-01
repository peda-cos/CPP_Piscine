/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:40 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/01 15:58:23 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void printHeader(const std::string &title) {
    std::cout << "========================================\n";
    std::cout << title << std::endl;
    std::cout << "========================================\n";
}

void testValidConstruction(void) {
    printHeader("TEST 1: Valid Construction");

    try {
	Bureaucrat bob("Bob", 75);
	std::cout << bob << std::endl;

	Bureaucrat alice("Alice", 1);
	std::cout << alice << std::endl;

	Bureaucrat charlie("Charlie", 150);
	std::cout << charlie << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInvalidConstruction(void) {
    printHeader("TEST 2: Invalid Construction - Grade Too High");

    try {
	Bureaucrat invalid("TooHigh", 0);
	std::cout << invalid << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Bureaucrat invalid2("TooHigh2", -5);
	std::cout << invalid2 << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInvalidConstructionLow(void) {
    printHeader("TEST 3: Invalid Construction - Grade Too Low");

    try {
	Bureaucrat invalid("TooLow", 151);
	std::cout << invalid << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Bureaucrat invalid2("TooLow2", 200);
	std::cout << invalid2 << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testIncrementGrade(void) {
    printHeader("TEST 4: Increment Grade (Valid)");

    try {
	Bureaucrat dave("Dave", 50);
	std::cout << "Before: " << dave << std::endl;

	dave.incrementGrade();
	std::cout << "After increment: " << dave << std::endl;

	dave.incrementGrade();
	std::cout << "After second increment: " << dave << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testIncrementGradeBoundary(void) {
    printHeader("TEST 5: Increment Grade - Boundary Exception");

    try {
	Bureaucrat topBureaucrat("TopGuy", 1);
	std::cout << topBureaucrat << std::endl;

	std::cout << "Attempting to increment grade 1..." << std::endl;
	topBureaucrat.incrementGrade();
	std::cout << topBureaucrat << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Bureaucrat almostTop("AlmostTop", 2);
	std::cout << almostTop << std::endl;

	almostTop.incrementGrade();
	std::cout << "After first increment: " << almostTop << std::endl;

	std::cout << "Attempting second increment..." << std::endl;
	almostTop.incrementGrade();
	std::cout << almostTop << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testDecrementGrade(void) {
    printHeader("TEST 6: Decrement Grade (Valid)");

    try {
	Bureaucrat eve("Eve", 50);
	std::cout << "Before: " << eve << std::endl;

	eve.decrementGrade();
	std::cout << "After decrement: " << eve << std::endl;

	eve.decrementGrade();
	std::cout << "After second decrement: " << eve << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testDecrementGradeBoundary(void) {
    printHeader("TEST 7: Decrement Grade - Boundary Exception");

    try {
	Bureaucrat bottomBureaucrat("BottomGuy", 150);
	std::cout << bottomBureaucrat << std::endl;

	std::cout << "Attempting to decrement grade 150..." << std::endl;
	bottomBureaucrat.decrementGrade();
	std::cout << bottomBureaucrat << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
	Bureaucrat almostBottom("AlmostBottom", 149);
	std::cout << almostBottom << std::endl;

	almostBottom.decrementGrade();
	std::cout << "After first decrement: " << almostBottom << std::endl;

	std::cout << "Attempting second decrement..." << std::endl;
	almostBottom.decrementGrade();
	std::cout << almostBottom << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment(void) {
    printHeader("TEST 8: Copy Constructor and Assignment Operator");

    try {
	Bureaucrat original("Original", 42);
	std::cout << "Original: " << original << std::endl;

	Bureaucrat copy(original);
	std::cout << "Copy: " << copy << std::endl;

	Bureaucrat assigned("Assigned", 100);
	std::cout << "Before assignment: " << assigned << std::endl;

	assigned = original;
	std::cout << "After assignment: " << assigned << std::endl;

	std::cout << "\nModifying original..." << std::endl;
	original.incrementGrade();
	std::cout << "Original after increment: " << original << std::endl;
	std::cout << "Copy (should be unchanged): " << copy << std::endl;
	std::cout << "Assigned (should be unchanged): " << assigned
		  << std::endl;
    } catch (std::exception &e) {
	std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main(void) {
    testValidConstruction();
    testInvalidConstruction();
    testInvalidConstructionLow();
    testIncrementGrade();
    testIncrementGradeBoundary();
    testDecrementGrade();
    testDecrementGradeBoundary();
    testCopyAndAssignment();

    printHeader("All tests completed!");

    return 0;
}
