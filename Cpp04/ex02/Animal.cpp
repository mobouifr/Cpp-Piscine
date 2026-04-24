/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:31 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 17:02:38 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Animal::Animal() : type("Animal")
{
    std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "[Animal] Copy constructor called" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[Animal] Copy assignment called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return (*this);
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

std::string Animal::getType() const
{
    return (this->type);
}

// void Animal::makeSound() const
// {
//     std::cout << "[Animal] makes an undefined sound..." << std::endl;
// }