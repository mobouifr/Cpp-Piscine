/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:38 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 04:18:33 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "[Cat] Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "[Cat] Copy assignment operator called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void Cat::makeSound() const
{
    std::cout << "[Cat] Meow meow" << std::endl;
}