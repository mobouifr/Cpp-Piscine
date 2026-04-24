/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 04:05:56 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/08 04:31:22 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie constructed" << std::endl;
}

void Zombie::setZombieName( const std::string &name )
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout <<  name <<" Zombie destructor!" <<std::endl;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombie = new Zombie[N]; 
    
    for(int i = 0; i < N; i++)
    {
        zombie[i].setZombieName(name);
        zombie[i].announce();
    }
    return zombie;
}

