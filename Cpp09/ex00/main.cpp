/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:24 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/31 15:04:25 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.loadDatabase("data.csv"))
    {
        std::cout << "Error: could not open database." << std::endl;
        return 1;
    }

    btc.processInputFile(argv[1]);
    return 0;
}
