/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:10:17 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/19 10:17:17 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) 
{
    (void) other;
}

Intern& Intern::operator=(const Intern& other) 
{
    (void) other;
    return (*this);
    
}

Intern::~Intern() {}

//

static AForm* createShrubbery(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}


static AForm* createRobotomy(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* createPresidential(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* (*creators[3])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            AForm* form = creators[i](target);
            std::cout << "Intern creates " << names[i] << std::endl;
            return (form);
        }
    }
    std::cout << "Intern couldn't create \"" << name << "\" : form not found" << std::endl;
    return (NULL);
}

