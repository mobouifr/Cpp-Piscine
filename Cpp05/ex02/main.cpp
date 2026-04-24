#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try 
	{
		Bureaucrat bob("Bob", 1);  // Grade 1: can do everything

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		//AForm *rf;

		std::cout << "\n--- Signing forms ---\n";
		bob.signForm(shrub);
		bob.signForm(robo);
		bob.signForm(pardon);

		std::cout << "\n--- Executing forms ---\n";
		bob.executeForm(shrub);
		bob.executeForm(robo);
		bob.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

