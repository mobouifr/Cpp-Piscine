/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:05:02 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/09 18:19:31 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
		int					_value;
		static const int	_fractionalBits;

    public:
				Fixed();
				Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
				~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
