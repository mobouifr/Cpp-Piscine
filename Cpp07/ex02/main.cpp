/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:30:38 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/26 21:30:39 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    // Test 1: empty array
    Array<int> a;
    std::cout << "Size a: " << a.size() << std::endl;

    // Test 2: array with size
    Array<int> b(3);
    b[0] = 10;
    b[1] = 20;
    b[2] = 30;

    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    // Test 3: deep copy
    Array<int> c = b;
    c[1] = 99;

    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    // Test 4: out of bounds
    try
    {
        std::cout << b[10] << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}
