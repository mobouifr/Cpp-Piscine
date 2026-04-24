/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:40:25 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/29 21:02:00 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>

class  Span
{
    private:
        std::vector<int>    _data;
        unsigned int        _capacity;

    public:
        Span();
        Span(const Span& other);
        Span(unsigned int n);
        Span& operator=(const Span& other);
        ~Span();

        class FullException : public std::exception 
        {
            public:
            const char* what() const throw()
            {
                return ("Span: container full");
            }
        };

        class NoSpanException : public std::exception 
        {
            public:
            const char* what() const throw()
            {
                return ("No span");            
            }
        };

        void            addNumber(int n);
        long long       shortestSpan() const;
        long long       longestSpan() const;
        unsigned int    size() const;
        unsigned int    capacity() const;
        
        template <typename InputIt>
        void    addRange(InputIt begin, InputIt end)
        {
            for (InputIt it = begin; it != end ; it++)
            {
                addNumber(*it);
            }
        }

};

#endif