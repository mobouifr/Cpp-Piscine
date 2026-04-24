#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// Canonical
ShrubberyCreationForm::ShrubberyCreationForm()
	                 : AForm("ShrubberyCreation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
                     : AForm("ShrubberyCreation", 145, 137), target(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
        AForm::operator=(other);
        this->target = other.target; 
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	                 : AForm(other), target(other.target) {}

// Actual execution logic
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
		throw AForm::NotSignedException();
	
    if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile)
		return;

	outfile << "          &&& &&  & &&\n";
	outfile << "      && &\\/&\\|& ()|/ @, &&\n";
	outfile << "      &\\/(/&/&||/& /_/)_&/_&\n";
	outfile << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
	outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	outfile << "&&   && & &| &| /& & % ()& /&&\n";
	outfile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	outfile << "     &&     \\|||\n";
	outfile << "             |||\n";
	outfile << "             |||\n";
	outfile << "             |||\n";
	outfile << "       , -=-~  .-^- _\n";

	outfile.close();
}
