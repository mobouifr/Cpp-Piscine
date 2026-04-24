#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
AForm::AForm() : name("Default"), isSigned(0), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, int sign, int exec)
	: name(name), isSigned(false), gradeToSign(sign), gradeToExecute(exec)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

// Getters
const std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

// Signing logic
void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "AForm is not signed!";
}

// Output
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm \"" << f.getName() << "\", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return out;
}