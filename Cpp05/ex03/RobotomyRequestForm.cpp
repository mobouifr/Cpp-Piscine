#include "RobotomyRequestForm.hpp"
#include <iostream>

// Canonical
RobotomyRequestForm::RobotomyRequestForm()
	               : AForm("RobotomyRequest", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	               : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
        AForm::operator=(other);
        this->target = other.target; 
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	               : AForm("RobotomyRequest", 72, 45), target(target) {}


// Execution logic
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "💥 BZZZZZ 💥 DRRRRZZZZZZZ 💣🔧\n";

	std::srand(std::time(NULL)); // Seed random once
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully 🤖✅\n";
	else
		std::cout << "Robotomy failed on " << target << " ❌💥\n";
}
