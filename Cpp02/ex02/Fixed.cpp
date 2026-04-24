/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:23:50 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/12 03:53:48 by mobouifr         ###   ########.fr       */
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

int	Fixed::getRawBits( void ) const
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

// --------------------- Comparison Operators ---------------------:

bool Fixed::operator>(const Fixed& other) const 
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return(this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return(this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return(this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return(this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return(this->_value != other._value);
}

// --------------------- Arithmetic Operators ---------------------:

Fixed 	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits(this->_value + other._value);
	
	return (result);
}

Fixed 	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits(this->_value - other._value);
	
	return (result);
}

Fixed 	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits((this->_value * other._value) >> _fractionalBits);	
	
	return (result);
}

Fixed 	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	
	result.setRawBits((this->_value << _fractionalBits) / other._value);
	
	return (result);	
}

// --------------------- Increment / Decrement ---------------------:

Fixed&	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	_value++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	_value--;
	return (temp);
}

// --------------------- Min / Max ---------------------:

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);	
}

// --------------------- Output Stream Overload --------------------:

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
{
	out << fixed.toFloat();
	return (out);
}
	