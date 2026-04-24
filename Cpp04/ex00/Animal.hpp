/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:34 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 20:36:20 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
	protected:
		std::string type;

	public:
	// Canonical Form
				Animal();                          
				Animal(const Animal& other);      
		Animal&	operator=(const Animal& other); 
		virtual	~Animal();

	// Actions
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif