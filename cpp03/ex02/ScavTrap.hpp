/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:54:18 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 01:24:18 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRAPTRAP_HPP
#define STRAPTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
		// Canonical Form
					ScavTrap();
                	ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
					~ScavTrap();
		// Constructor
        			ScavTrap(const std::string& name);

		// Actions
		void		attack(const std::string& target);
		void		guardGate();
};

#endif