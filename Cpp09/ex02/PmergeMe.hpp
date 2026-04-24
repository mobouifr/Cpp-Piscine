/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:51:39 by mobouifr          #+#    #+#             */
/*   Updated: 2026/01/02 18:51:40 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    private:
        std::vector<int> _inputVec;

        // Ford-Johnson implementations
        static void fordJohnsonVector(std::vector<int>& v);
        static void fordJohnsonDeque(std::deque<int>& d);

        // helpers
        static bool             isPositiveInt(const std::string& s);
        static std::vector<int> jacobsthal_up_to(int limit);
        
        // binary insert helpers
        static void binary_insert_vector(std::vector<int>& v, int value);
        static void binary_insert_deque(std::deque<int>& d, int value);
    
    public:
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        PmergeMe();
        ~PmergeMe();

        // parse command-line args into _inputVec
        bool parseInput(int argc, char** argv);

        // run the two-container sorting and print outputs
        void run() const;

};

#endif
