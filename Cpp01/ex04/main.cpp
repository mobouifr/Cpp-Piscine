/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:05:25 by mobouifr          #+#    #+#             */
/*   Updated: 2025/06/08 15:05:26 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


std::string	replaceAll(std::string line, std::string s1, std::string s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result.append(line.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
	}
	result.append(line.substr(pos));
	
	return result;
}

bool isInvalidInput(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return true;
    }

    if (std::string(argv[2]).empty())
    {
        std::cerr << "Error: s1 cannot be empty (would cause infinite loop)." << std::endl;
        return true;
    }

    return false;
}

int main(int argc, char **argv)
{
    if (isInvalidInput(argc, argv))
		return 1;

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inFile(filename.c_str());
	if(!inFile.is_open())
	{
		std::cerr << "Error: cannot open input file." << std::endl;
		return 1;
	}

	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: cannot open output file." << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		outFile << replaceAll(line, s1, s2) << std::endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}