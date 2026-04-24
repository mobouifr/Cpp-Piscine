/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:30:48 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/26 21:30:49 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F>
void iter(T* array, const unsigned int len, F f)
{
    for (unsigned int i = 0; i < len; ++i)
        f(array[i]);
}

#endif