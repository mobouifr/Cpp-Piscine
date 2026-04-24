/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:24:48 by mobouifr          #+#    #+#             */
/*   Updated: 2026/01/02 18:45:40 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>
#include <iterator>


bool PmergeMe::isPositiveInt(const std::string& s)
{
    if (s.empty())
        return (false);
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return (false);
    }

    std::istringstream ss(s);
    long n;
    ss >> n;

    if (ss.fail())
        return (false);
    
    if (n < 0 || n > 2147483647)
        return (false);
    
    return (true);
}

void PmergeMe::binary_insert_vector(std::vector<int>& v, int value)
{
    std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), value);
    v.insert(it, value);
}

void PmergeMe::binary_insert_deque(std::deque<int>& d, int value)
{
    std::deque<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}

std::vector<int> PmergeMe::jacobsthal_up_to(int limit)
{
    std::vector<int> J;

    J.push_back(0);
    J.push_back(1);

    if (limit <= 1)
        return (J);

    while (J.back() < limit)
    {
        int n = static_cast<int>(J.size());
        int next = J[n - 1] + 2 * J[n - 2]; // J[n] = J[n-1] + 2*J[n-2]
        J.push_back(next);
    }
    return (J);
}

void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    size_t n = v.size();
    if (n <= 1)
        return ;

    std::vector<int> big;  
    std::vector<int> small;

    big.reserve((n + 1) / 2);
    small.reserve(n / 2);

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = v[i];
        int b = v[i + 1];
        if (a > b)
        {
            big.push_back(a);
            small.push_back(b);
        }
        else
        {
            big.push_back(b);
            small.push_back(a);
        }
    }

    bool hasStraggler = (n % 2 == 1);
    if (hasStraggler)
        big.push_back(v.back()); 

    fordJohnsonVector(big);

    int m = static_cast<int>(small.size());
    if (m > 0)
    {
        std::vector<int> J = jacobsthal_up_to(m);

        binary_insert_vector(big, small[0]);

        for (size_t k = 2; k < J.size(); ++k)
        {
            int from = J[k - 1];
            int to = J[k];

            if (from >= m) 
                break;
            
            if (to > m)
                to = m;

            for (int idx = to - 1; idx >= from; --idx)
                binary_insert_vector(big, small[idx]);
        }
    }

    v.swap(big);
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    size_t n = d.size();
    
    if (n <= 1)
        return ;

    std::deque<int> big;
    std::deque<int> small;

    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int a = d[i];
        int b = d[i + 1];
        if (a > b)
        {
            big.push_back(a);
            small.push_back(b);
        }
        else
        {
            big.push_back(b);
            small.push_back(a);
        }
    }

    bool hasStraggler = (n % 2 == 1);
    if (hasStraggler)
        big.push_back(d.back());

    fordJohnsonDeque(big);

    int m = static_cast<int>(small.size());
    if (m > 0)
    {
        std::vector<int> J = jacobsthal_up_to(m);

        binary_insert_deque(big, small[0]);

        for (size_t k = 2; k < J.size(); ++k)
        {
            int from = J[k - 1];
            int to = J[k];

            if (from >= m)
                break ;
            
            if (to > m)
                to = m;

            for (int idx = to - 1; idx >= from; --idx)
                binary_insert_deque(big, small[idx]);
        }
    }

    d.swap(big);
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return(*this); }
PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        
        if (!isPositiveInt(s))
            return (false);

        std::istringstream ss(s);
        int v;

        ss >> v;
        _inputVec.push_back(v);
    }
    return (true);
}

static double elapsed_us(const timeval& a, const timeval& b)
{
    return (double(b.tv_sec - a.tv_sec) * 1e6 + double(b.tv_usec - a.tv_usec));
}

void PmergeMe::run() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _inputVec.size(); ++i)
    {
        std::cout << _inputVec[i];
        if (i + 1 < _inputVec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec = _inputVec;
    std::deque<int> deq(_inputVec.begin(), _inputVec.end());

    timeval t0;
    timeval t1;

    gettimeofday(&t0, NULL);
    PmergeMe::fordJohnsonVector(vec);
    gettimeofday(&t1, NULL);
    double timeVec = elapsed_us(t0, t1);

    timeval t2;
    timeval t3;

    gettimeofday(&t2, NULL);
    PmergeMe::fordJohnsonDeque(deq);
    gettimeofday(&t3, NULL);
    double timeDeq = elapsed_us(t2, t3);

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i + 1 < vec.size()) std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _inputVec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _inputVec.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}
