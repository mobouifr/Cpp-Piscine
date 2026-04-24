/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:05:05 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/12 03:58:59 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// --------------------- Canonical Form ---------------------:

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copie constructor called" << std::endl;
	this->_value = other._value;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copie assignement constructor called" << std::endl;

	if (this != &other)
		this->_value = other._value;
		
	return (*this);
}

Fixed::~Fixed() 
{
	std::cout << "destructor called" << std::endl; 
}

// --------------------- Raw Bit Access ---------------------:

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}
