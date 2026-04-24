/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:53:17 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/12 03:57:59 by mobouifr         ###   ########.fr       */
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
	std::cout << "Destructor called" << std::endl; 
}

// --------------------- Value Constructors ---------------------:

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed( const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractionalBits));
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

// --------------------- Conversions ---------------------:

float	Fixed::toFloat() const 
{
    return ((float)_value / (1 << _fractionalBits));
}

int		Fixed::toInt() const 
{
    return (_value >> _fractionalBits);
}

// --------------------- Output Stream Overload ---------------------:

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
    out << fixed.toFloat();
    return (out);
}
