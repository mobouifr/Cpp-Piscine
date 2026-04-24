/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:44 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 16:49:44 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Dog::Dog() : Animal(), _brain(new Brain())
{
    std::cout << "[Dog] Constructor called" << std::endl; 
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), _brain (new Brain(*other._brain))
{
    std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] Copy assignment called" << std::endl;

    if (this != &other)
    {
        Animal::operator=(other);
        
        if (_brain)
            delete _brain;
        
        _brain = new Brain(*other._brain); // deep copy
    }
    return (*this);   
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
    delete _brain;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}

// optional for testing deep copie
Brain* Dog::getBrain() const 
{
    return _brain;
}