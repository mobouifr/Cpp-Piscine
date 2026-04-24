/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:54:08 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/13 23:32:03 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap basic("BasicBot");
    basic.attack("Enemy");
    basic.beRepaired(5);

    std::cout << "\n=== SCAVTRAP TESTS ===" << std::endl;
    ScavTrap guard("GateKeeper");
    guard.attack("Enemy");
    guard.takeDamage(60);
    guard.beRepaired(20);
    guard.guardGate(); // Unique to ScavTrap

    std::cout << "\n=== Copy and Assignment Test ===" << std::endl;
    ScavTrap copy(guard);
    ScavTrap another("Temporary");
    another = guard;

    return 0;
}

/*
EX01 - Serena, my love!

Goal: Create a derived class ScavTrap from ClapTrap.

What to do:
- Inherit from ClapTrap.
- Update default values:
  - Hit points = 100
  - Energy points = 50
  - Attack damage = 20
- Override attack() and constructors/destructor to show different messages.
- Add new method: guardGate() to activate Gate keeper mode.
*/
