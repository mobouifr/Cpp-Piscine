/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:37:52 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/11 17:00:44 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
				Fixed();
				Fixed(const int value);
				Fixed(const float value);
				Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
				~Fixed();
				
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float   toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
