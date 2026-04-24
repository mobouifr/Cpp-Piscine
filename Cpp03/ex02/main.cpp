/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:02:26 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 01:30:45 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap frag("MontassirBot");

    frag.attack("target dummy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\nNow let's test energy drain:\n";
    for (int i = 0; i < 101; ++i)
        frag.attack("spam");

    return 0;
}

/*
EX02 - Repetitive work

Goal: Create another derived class FragTrap from ClapTrap.

What to do:
- Inherit from ClapTrap.
- Update default values:
  - Hit points = 100
  - Energy points = 100
  - Attack damage = 30
- Override constructors/destructor with different messages.
- Add new method: highFivesGuys() that prints a positive message.
*/
