#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

bool isBlank(const std::string& str)
{
    int i;
    bool hasVisibleChar = false;

    i = 0;
    while (i < (int)str.length())
    {
        if (!std::isprint(str[i]))
            return true;

        if (!std::isspace(str[i]))
            hasVisibleChar = true;

        i++;
    }
    return !hasVisibleChar;
}

std::string getValidInput(const std::string& fieldName)
{
    std::string input;

    while (true) 
    {
        std::cout << fieldName << ": ";
        std::getline(std::cin, input);

        if (std::cin.eof()) 
        {
            std::cout << "\nInput cancelled. Exiting..." << std::endl;
            exit(1);
        }

        if (isBlank(input)) 
            std::cout << "Non valid input. Try again." << std::endl;

        else 
            return input;
    }
}


void    Contact::SetInfos()
{ 
    FirstName     = getValidInput("First name");
    LastName      = getValidInput("Last name");
    Nickname      = getValidInput("Nickname");
    PhoneNumber   = getValidInput("Phone number");
    DarkestSecret = getValidInput("Darkest secret");
}

void    Contact::DisplayShortInfos(int index)
{
    std::cout << std::setw(10) << index << "|";

    std::string Fields[3] = { FirstName, LastName, Nickname };
    
    int i = 0;
    while(i < 3)
    {
        if (Fields[i].length() > 10)
            std::cout << Fields[i].substr(0, 9) + ".";
        else
            std::cout << std::setw(10) << Fields[i];
        std::cout << "|";
        i++;
    }
    std::cout << std::endl;
}

void    Contact::DisplayFullInfos()
{
    std::cout << "First name     : " << FirstName << std::endl;
    std::cout << "last name      : " << LastName << std::endl;
    std::cout << "Nickname       : " << Nickname << std::endl;
    std::cout << "phone number   : " << PhoneNumber << std::endl;
    std::cout << "Darkest secret : " << DarkestSecret << std::endl;
}

