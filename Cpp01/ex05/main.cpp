/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:05:36 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/08 22:04:21 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;

    std::cout << "[ DEBUG ]" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "[ INFO ]" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "[ WARNING ]" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "[ ERROR ]" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    return 0;
}