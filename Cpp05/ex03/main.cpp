#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;

    std::cout << "---- Test 1: Robotomy ----" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "coffee machine");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n---- Test 2: Shrubbery ----" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n---- Test 3: Presidential ----" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "lbakhti");
    if (form)
    {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n---- Test 4: Invalid form ----" << std::endl;
    form = someRandomIntern.makeForm("coffee request", "Me");
    if (!form)
        std::cout << "Form creation failed as expected" << std::endl;

    return 0;
}


