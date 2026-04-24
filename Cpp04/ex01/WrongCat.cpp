/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:58 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 14:09:09 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "[WrongCat] Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "[WrongCat] Assignment operator called" << std::endl;

    if (this != &other)
        this->type = other.type;

    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Public Member Functions: Actions
// -------------------------------------------------------------

void WrongCat::makeSound() const 
{
    std::cout << "[WrongCat] Meeeow! (WrongCat)" << std::endl;
}
