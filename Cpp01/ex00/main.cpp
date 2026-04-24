/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:07:34 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/08 03:39:05 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie stackZombie("Montassir1");
    Zombie *heapZombie = newZombie("Montassir2");

    stackZombie.announce();
    heapZombie->announce();
    randomChump("Montassir3");

    delete heapZombie;
    
    return 0;
}