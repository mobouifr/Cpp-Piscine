/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:54 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 04:21:25 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
	protected:
		std::string type;

	public:
		// Canonical form
						WrongAnimal();
						WrongAnimal(const WrongAnimal& other);
		WrongAnimal& 	operator=(const WrongAnimal& other);
						~WrongAnimal();

		// Actions
		std::string	getType() const;
		void		makeSound() const;  // NOT virtual!
};

#endif
