#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

static std::string formatField(const std::string& str);
static bool getInput(const std::string& prompt, std::string& value);

PhoneBook::PhoneBook() : _contact_count(0), _index(0) {}

bool PhoneBook::addContact() 
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string secret;

    if (!getInput("Enter first name: ", firstName))
        return false;
    contacts[_index].setFirstName(firstName);
    if (!getInput("Enter last name: ", lastName))
        return false;
    contacts[_index].setLastName(lastName);
    if (!getInput("Enter nick name: ", nickName))
        return false;
    contacts[_index].setNickName(firstName);
    if (!getInput("Enter phone number: ", phoneNumber))
        return false;
    contacts[_index].setPhoneNumber(phoneNumber);
    if (!getInput("Enter secret: ", secret))
        return false;
    contacts[_index].setSecret(secret);
    
    _index = (_index + 1) % 8;
    if (_contact_count < 8)
        _contact_count++;
    
    return true;
}

bool PhoneBook::searchContact() const
{
    if (_contact_count == 0) 
    {
        std::cout << "Phonebook is empty.\n";
        return true;
    }

    std::cout << std::setw(10) << "Index" << " | " 
              << std::setw(10) << "First name" << " | " 
              << std::setw(10) << "Last name" << " | " 
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    
    int start = (_contact_count == 8) ? _index : 0;
    for (int i = 0; i < _contact_count; i++) 
    {
        int realIndex = (start + i) % 8;
        std::cout << std::setw(10) << i + 1 << " | "
                << std::setw(10) << formatField(contacts[realIndex].getFirstName()) << " | "
                << std::setw(10) << formatField(contacts[realIndex].getLastName()) << " | "
                << std::setw(10) << formatField(contacts[realIndex].getNickName()) << std::endl;
    }

    while (true) 
    {
        std::cout << "Enter the index of the entry to display: ";
        std::string input;
        if (!std::getline(std::cin, input)) 
            return false;

        if (input.empty()) 
        {
            std::cout << "No index provided.\n";
            continue ;
        }
        std::stringstream ss(input);
        int number;
        char extra;
        if (!(ss >> number) || (ss >> extra)) 
        {
            std::cout << "Invalid input. Index must be a number.\n";
            continue ;
        }

        if ((number <= 0 || number > _contact_count) && _contact_count > 1) 
        {
            std::cout << "Index range from 1 to " << _contact_count << std::endl;
            continue ;
        }
        if ((number <= 0 || number > _contact_count) && _contact_count == 1) 
        {
            std::cout << "There is only one entry. You can make it!" << std::endl;
            continue ;
        }

        int realIndex = (start + (number - 1)) % 8;

        std::cout << "First name: " << contacts[realIndex].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[realIndex].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[realIndex].getNickName() << std::endl;
        std::cout << "Phone number: " << contacts[realIndex].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[realIndex].getSecret() << std::endl;
        return true;
    }
}

static bool getInput(const std::string& prompt, std::string& value)
{
    while (true)
    {
        std::cout << prompt;

        if (!std::getline(std::cin, value))
            return false;

        if (!value.empty())
            return true;

        std::cout << "Field cannot be empty.\n";
    }
}

static std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + '.';
    else
        return str;
}