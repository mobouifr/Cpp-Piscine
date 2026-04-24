#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        // Canonical Form
        AForm();
        AForm(const AForm &other);
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        
        // Pure virtual execute (makes this calss abstract)
        virtual void        execute(Bureaucrat const &executor) const = 0;
        
        // Getters
        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        // Signing logic
        void                beSigned(const Bureaucrat &b);

        // Exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NotSignedException : public std::exception
        {
	        public:
		        const char* what() const throw();
	    };


};

// Output overload
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif