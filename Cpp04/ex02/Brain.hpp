/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:19:22 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 13:21:52 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
	// Canonical form
				Brain();
				Brain(const Brain& other);
		Brain&	operator=(const Brain& other); 
				~Brain();                 

	// Optional helper functions for tests:
		std::string getIdea(int index) const;
		void 		setIdea(int index, const std::string& idea);
};

#endif