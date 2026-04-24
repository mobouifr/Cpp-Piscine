#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // for rand()
#include <ctime>   // for time()

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        // Canonical
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm(const RobotomyRequestForm& other);
        
        // Override execute
        void execute(Bureaucrat const& executor) const;
};

#endif
