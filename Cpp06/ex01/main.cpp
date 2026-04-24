/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:03:50 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/24 18:10:12 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.value = 42;
    data.name = "forty-two";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << originalPtr << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "Pointers are equal ✅" << std::endl;
    else
        std::cout << "Pointers are NOT equal ❌" << std::endl;

    std::cout << "Data through deserialized pointer:" << std::endl;
    std::cout << "value = " << deserializedPtr->value << std::endl;
    std::cout << "name  = " << deserializedPtr->name << std::endl;

    return 0;
}