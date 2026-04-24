#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string DarkestSecret;
    
    public:
        void        SetInfos();
        void        DisplayShortInfos(int index);
        void        DisplayFullInfos();
};

std::string     getValidInput(const std::string& fieldName);
bool            isBlank(const std::string& str);


#endif