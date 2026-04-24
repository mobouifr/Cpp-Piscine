#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact contacts[8];
        int CurrentIndex;
        int TotalContacts;

    public:
        PhoneBook();
        void    AddNewContact();
        void    SearchContact();
};

bool isNumeric(const std::string& str);

#endif