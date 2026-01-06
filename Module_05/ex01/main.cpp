#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== Test 1: Valid form creation ===" << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Invalid form (grade too high) ===" << std::endl;
	try
	{
		Form invalid("Invalid", 0, 25);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Invalid form (grade too low) ===" << std::endl;
	try
	{
		Form invalid("Invalid", 50, 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat signs form (success) ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 40);
		Form permit("Permit A38", 50, 25);
		std::cout << bob << std::endl;
		std::cout << permit << std::endl;
		bob.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat signs form (failure) ===" << std::endl;
	try
	{
		Bureaucrat lowRank("LowRank", 100);
		Form permit("Permit B52", 50, 25);
		std::cout << lowRank << std::endl;
		std::cout << permit << std::endl;
		lowRank.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
