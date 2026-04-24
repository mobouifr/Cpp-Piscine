/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:07:27 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/22 12:17:27 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing generate() + identify ===" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();

        std::cout << "Pointer identify: ";
        identify(obj);

        std::cout << "Reference identify: ";
        identify(*obj);

        delete obj;
        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}