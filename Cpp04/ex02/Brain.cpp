/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:19:24 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 13:24:40 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// -------------------------------------------------------------
//  Canonical Form: Constructor, Copy, Assignment, Destructor
// -------------------------------------------------------------

Brain::Brain()
{
	std::cout << "[Brain] Default constructor called" << std::endl;
	
    for (int i = 0; i < 100; ++i)
		this->ideas[i] = "Empty idea";
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;

    for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] Assignment operator called" << std::endl;

    if (this != &other)
    {
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	
    return *this;
}

Brain::~Brain() 
{
	std::cout << "[Brain] Destructor called" << std::endl;
}

// -------------------------------------------------------------
//  Optional: helpers for testing
// -------------------------------------------------------------

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];

    return "Out of bounds";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}