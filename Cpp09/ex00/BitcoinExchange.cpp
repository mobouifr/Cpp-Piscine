/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:21 by mobouifr          #+#    #+#             */
/*   Updated: 2026/01/02 17:09:55 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    return (s.substr(start, end - start));
}

bool BitcoinExchange::isValidDateFormat(const std::string& date)
{
    if (date.size() != 10)
        return (false);

    if (date[4] != '-' || date[7] != '-')
        return (false);

    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return (false);
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return (false);

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return (false);

    return (true);
}


bool BitcoinExchange::parseValue(const std::string& s, double& value)
{
    std::stringstream ss(s);
    
    ss >> value;
    if (ss.fail())
        return (false);

    ss >> std::ws;
    return (ss.eof());
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return (false);

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date; 
        std::string priceStr;

        if (!std::getline(ss, date, ','))
            continue ;
        if (!std::getline(ss, priceStr))
            continue ;

        double price;
        if (!parseValue(priceStr, price))
            continue ;

        _db[date] = price;
    }

    return (true);
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line))
    {
        std::string original = line;

        if (firstLine)
        {
            firstLine = false;

            size_t pipePos = line.find('|');
            if (pipePos == std::string::npos)
            {
                std::cout << "Error: bad input => " << original << std::endl;
                continue;
            }

            std::string date = trim(line.substr(0, pipePos));
            std::string valueStr = trim(line.substr(pipePos + 1));

            if ((date == "date") && (valueStr == "value"))
                continue ;
        }
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << original << std::endl;
            continue ;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDateFormat(date))
        {
            std::cout << "Error: bad input => " << original << std::endl;
            continue ;
        }

        double value;
        if (!parseValue(valueStr, value))
        {
            std::cout << "Error: bad input => " << original << std::endl;
            continue ; 
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue ;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue ;
        }

        std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

        if (it == _db.end() || it->first != date)
        {
            if (it == _db.begin())
            {
                std::cout << "Error: bad input => " << original << std::endl;
                continue ;
            }
            --it;
        }

        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
