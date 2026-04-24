/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 04:41:10 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/08 14:40:05 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type )
{
    this->type = type;
}

void Weapon::setType( const std::string &type )
{
    this->type = type;
}

const std::string &Weapon::getType()
{
    return type;
}

