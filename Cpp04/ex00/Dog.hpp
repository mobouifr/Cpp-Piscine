/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:46 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 16:59:25 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
    	// Canonical Form
                Dog();
                Dog(const Dog& other);
        Dog&    operator=(const Dog& other);
                ~Dog();
        
        // Actions
        void    makeSound() const;
};

#endif