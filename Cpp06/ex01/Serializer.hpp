/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:56:38 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/24 18:03:08 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

struct Data
{
    int         value;
    std::string name;
};

class Serializer
{
    private:
                Serializer();
                Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
                ~Serializer();
    
    public:
    static uintptr_t   serialize(Data* ptr);
    static Data*       deserialize(uintptr_t raw);
    
};

#endif