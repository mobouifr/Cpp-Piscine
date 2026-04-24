/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 03:42:00 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/14 04:26:10 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        // Canonical form
                    WrongCat();
                    WrongCat(const WrongCat& other);
        WrongCat&   operator=(const WrongCat& other);
                    ~WrongCat();

        // Actions
        void makeSound() const;  // Trying to override, but won't work through base*
};

#endif
