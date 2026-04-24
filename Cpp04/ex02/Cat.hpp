/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:41:41 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 19:18:27 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
	private:
		Brain* _brain;

	public:
	// Canonical form
				Cat();
				Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
				~Cat();

	// Action
		void 	makeSound() const;
		Brain*	getBrain() const; // optional for testing deep copie
};

#endif
