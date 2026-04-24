/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:31 by mobouifr          #+#    #+#             */
/*   Updated: 2026/01/02 18:20:52 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <iostream>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void) other; return (*this); }
RPN::~RPN() {}

static bool isSingleDigitNumberToken(const std::string& tok)
{
    return (tok.size() == 1 && std::isdigit(static_cast<unsigned char>(tok[0])));
}

static bool isOperatorToken(const std::string& tok)
{
    return (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'));
}

bool RPN::evaluate(const std::string& expr, int& result) const
{
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        std::cout << "token : {" << token << "}" << std::endl;
        if (isSingleDigitNumberToken(token))
        {
            int val = token[0] - '0';
            st.push(val);
        }
        
        else if (isOperatorToken(token))
        {
            if (st.size() < 2)
                return (false);

            int right = st.top();
            st.pop();
            
            int left  = st.top();
            st.pop();
            
            int res;
            char op = token[0];
            if (op == '+')
            {
                res = left + right;
            }
            else if (op == '-')
            {
                res = left - right;
            }
            else if (op == '*')
            {
                res = left * right;
            }
            else if (op == '/')
            {
                if (right == 0)
                    return (false);

                res = left / right;
            }

            st.push(res);
        }
        
        else
            return (false);
    }

    if (st.size() != 1)
        return (false);

    result = st.top();
    return (true);
}