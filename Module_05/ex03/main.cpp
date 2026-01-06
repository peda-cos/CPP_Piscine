#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Intern someRandomIntern;

	std::cout << "=== Test 1: Create robotomy request ===" << std::endl;
	{
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	std::cout << "\n=== Test 2: Create shrubbery creation ===" << std::endl;
	{
		AForm *scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		if (scf)
		{
			std::cout << *scf << std::endl;
			delete scf;
		}
	}

	std::cout << "\n=== Test 3: Create presidential pardon ===" << std::endl;
	{
		AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
		if (ppf)
		{
			std::cout << *ppf << std::endl;
			delete ppf;
		}
	}

	std::cout << "\n=== Test 4: Create unknown form ===" << std::endl;
	{
		AForm *unknown = someRandomIntern.makeForm("coffee request", "Office");
		if (unknown)
			delete unknown;
	}

	std::cout << "\n=== Test 5: Full workflow ===" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}

	return (0);
}
