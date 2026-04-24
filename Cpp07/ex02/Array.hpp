/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:30:25 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/26 21:30:26 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;

    public:
        Array() : _data(NULL), _size(0) {}

        Array(unsigned int n) : _data(new T[n]), _size(n) {}

        Array(const Array& other) : _data(NULL), _size(other._size)
        {
            if (_size > 0)
            {
                _data = new T[_size];
                
                for (unsigned int i = 0; i < _size; i++)
                {
                    _data[i] = other._data[i];
                }
            }
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _data;
                
                _size = other._size;
                _data = (_size > 0) ? new T[_size] : NULL;
                
                for (unsigned int i = 0; i < _size; i++)
                {
                    _data[i] = other._data[i];
                }
            }
            return (*this);
        }

        ~Array()
        {
            delete[] _data;
        }

    #include <iostream>

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return (_data[index]);
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::exception();
            
            return (_data[index]);
        }

        unsigned int size() const
        {
            return (_size);
        }
};

#endif
