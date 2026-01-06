#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	struct FormType
	{
		std::string name;
		AForm *(*create)(const std::string &);
	};

	FormType formTypes[] = {{"shrubbery creation", createShrubbery},
							{"robotomy request", createRobotomy},
							{"presidential pardon", createPardon}};

	for (int i = 0; i < 3; i++)
	{
		if (formTypes[i].name == formName)
		{
			AForm *form = formTypes[i].create(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}

	std::cout << "Intern couldn't create form: unknown form type \"" << formName
			  << "\"" << std::endl;
	return (NULL);
}
