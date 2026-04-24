/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:38 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 14:25:07 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Cat::Cat() : Animal(), _brain(new Brain())
{
    std::cout << "[Cat] Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "[Cat] Copy assignment operator called" << std::endl;

    if (this != &other)
    {
        Animal::operator=(other);
        
        if (_brain)
            delete _brain;
        
        _brain = new Brain(*other._brain); // deep copy
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "[Cat] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow meow" << std::endl;
}

// optional for testing deep copie
Brain* Cat::getBrain() const 
{
    return _brain;
}