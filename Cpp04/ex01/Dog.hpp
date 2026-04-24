/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:46 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 21:56:27 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
        Brain* _brain;
    
	public:
        // Canonical Form
                Dog();
                Dog(const Dog& other);
        Dog&    operator=(const Dog& other);
                ~Dog();
        
	// Actions
        void    makeSound() const;
		Brain* 	getBrain() const; // optional for testing deep copie
};

#endif