/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:27:16 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/29 14:27:17 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    // Test 1: found case
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl; // should print 20
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: not found case
    try
    {
        easyfind(v, 99); // not present
        std::cout << "Should not print this." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Not found (caught): " << e.what() << std::endl;
    }

    // Test 3: const container
    const std::vector<int> cv = v;
    try
    {
        std::vector<int>::const_iterator it = easyfind(cv, 10);
        std::cout << "Found in const container: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error const: " << e.what() << std::endl;
    }

    return 0;
}
