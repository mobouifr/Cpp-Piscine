/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:40:27 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/29 21:03:17 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>   // std::numeric_limits
#include <algorithm> // std::sort, std::min_element, std::max_element

Span::Span() : _capacity(0) {}

Span::Span(const Span& other) :  _data(other._data), _capacity(other._capacity){}

Span::Span(unsigned int n) : _capacity(n) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _data = other._data;
        _capacity = other._capacity;
    }
    return (*this);
}

Span::~Span() {}


void Span::addNumber(int n)
{
    if (_data.size() >= _capacity)
        throw FullException();
    _data.push_back(n);
}

long long Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanException();

    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    long long minDiff = std::numeric_limits<long long>::max();
    for (size_t i = 0; i + 1 < tmp.size(); ++i)
    {
        long long diff = static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]);
        if (diff < minDiff)
            minDiff = diff;
    }
    return (minDiff);
}

long long Span::longestSpan() const
{
    if (_data.size() < 2)
        throw NoSpanException();

    std::vector<int>::const_iterator itMin = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator itMax = std::max_element(_data.begin(), _data.end());
    
    return (static_cast<long long>(*itMax) - static_cast<long long>(*itMin));
}

unsigned int Span::size() const { return (static_cast<unsigned int>(_data.size())); }

unsigned int Span::capacity() const { return (_capacity); }
