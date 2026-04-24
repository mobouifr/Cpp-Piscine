/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:02:11 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 01:25:53 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Canonical Form
					FragTrap();
					FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
					~FragTrap();
		
		// Constructor			
					FragTrap(const std::string& name);

		// Actions			
		void		attack(const std::string& target);		
		void		highFivesGuys();
};

#endif
