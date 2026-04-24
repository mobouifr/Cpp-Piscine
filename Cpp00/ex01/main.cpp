#include "PhoneBook.hpp"
#include <cstdlib>

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter commmand (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, command);
    
        if (command == "EXIT")
            break ;

        else if (command == "ADD")
            phonebook.AddNewContact();

        else if (command == "SEARCH")
            phonebook.SearchContact();
            
        else if (std::cin.eof()) 
        {
            std::cout << "\nInput cancelled. Exiting..." << std::endl;
            exit(1);
        }

        else
            std::cout << "Invalid command." << std::endl;

    }
    return 0;
}