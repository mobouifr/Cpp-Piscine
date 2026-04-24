/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:04:18 by mobouifr          #+#    #+#             */
/*   Updated: 2025/12/31 15:04:19 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _db;

        static std::string trim(const std::string& s);
        static bool isValidDateFormat(const std::string& date);
        static bool parseValue(const std::string& s, double& value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();

        bool loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename) const;
};

#endif
