/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:44 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 13:31:55 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Dog::Dog() : Animal()
{
    std::cout << "[Dog] Constructor called" << std::endl; 
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] Copy assignment called" << std::endl;

    if (this != &other)
        this->type = other.type;
    
    return (*this);   
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void Dog::makeSound() const
{
    std::cout << "[Dog] Woof! Woof!" << std::endl;
}