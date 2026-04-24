/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:28 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/31 15:04:29 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    std::string expr = argv[1];
    RPN rpn;
    int result = 0;

    if (!rpn.evaluate(expr, result))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    std::cout << result << std::endl;
    return (0);
}
