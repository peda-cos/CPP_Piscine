#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat surgeon("Surgeon", 40);
		RobotomyRequestForm robotomy("Bender");
		std::cout << robotomy << std::endl;
		surgeon.signForm(robotomy);
		surgeon.executeForm(robotomy);
		surgeon.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execute unsigned form ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford Prefect");
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Grade too low to execute ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 50);
		RobotomyRequestForm robotomy("Marvin");
		Bureaucrat boss("Boss", 1);
		boss.signForm(robotomy);
		intern.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
