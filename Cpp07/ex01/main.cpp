/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:30:43 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/26 21:30:44 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void increment(int &n)
{
    n += 1;
}

void printStr(const std::string &s)
{
    std::cout << s << std::endl;
}

int main()
{
    // --- Test 1: mutate ints ---
    int nums[] = {0, 1, 2, 3};
    const unsigned int nums_len = 4;

    iter(nums, nums_len, &increment);
    for (unsigned int i = 0; i < nums_len; ++i)
    {
        std::cout << nums[i];
        if (i + 1 < nums_len) std::cout << ' ';
    }
    std::cout << std::endl;

    std::string words[] = {"hello", "iter", "test"};
    const unsigned int words_len = 3;
    iter(words, words_len, &printStr);

    return 0;
}
