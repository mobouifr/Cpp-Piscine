#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>


bool isNumeric(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

PhoneBook::PhoneBook()
{
    CurrentIndex = 0;
    TotalContacts = 0;
}

void    PhoneBook::AddNewContact()
{
    contacts[CurrentIndex].SetInfos();
    CurrentIndex = (CurrentIndex + 1) % 8;
    if (TotalContacts < 8)
        TotalContacts++;
}

void    PhoneBook::SearchContact()
{
    if (TotalContacts == 0)
    {
        std::cout << "No contact available." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nakename" << "|" << std::endl;

    int i = 0;
    while(i < TotalContacts)
    {
        contacts[i].DisplayShortInfos(i);
        i++;
    }

    std::cout << "Enter index: ";
    std::string input;
    std::getline(std::cin, input);

    if (!isNumeric(input))
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = atoi(input.c_str());

    if (index < 0 || index >= TotalContacts)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    contacts[index].DisplayFullInfos();
}