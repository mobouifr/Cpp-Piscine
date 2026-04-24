/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:53:41 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/13 23:13:51 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{

    ClapTrap ct1("CT-One");
    ClapTrap ct2("CT-Two");

    std::cout << "\n=== Basic Attack Test ===" << std::endl;
    ct1.attack("CT-Two");
    ct2.takeDamage(5); 

    std::cout << "\n=== Repair Test ===" << std::endl;
    ct1.beRepaired(3);  
    ct2.beRepaired(20);

    std::cout << "\n=== Zero Energy Test ===" << std::endl;

    for (int i = 0; i < 10; ++i)
        ct1.attack("DummyTarget");
        
    ct1.beRepaired(10);

    std::cout << "\n=== Death Test ===" << std::endl;
    ct2.takeDamage(200);       
    ct2.attack("CT-One");
    ct2.beRepaired(10);

    std::cout << "\n=== Copy & Assignment Test ===" << std::endl;
    ClapTrap ct3(ct1);
    ClapTrap ct4("Temp");
    ct4 = ct1;

    return 0;    
}


/*
EX00 - Aaaaand... OPEN!

Goal: Implement a basic class called ClapTrap.

What to do:
- Create a class with name, hit points (10), energy points (10), and attack damage (0).
- Add these public methods:
  - attack(target)
  - takeDamage(amount)
  - beRepaired(amount)
- Display messages for all actions and in constructors/destructor.
- Prevent actions when no hit points or energy left.
*/
