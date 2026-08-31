#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main() 
{
    PhoneBook phonebook;
    std::string prompt;

    std::cout << "The program only accepts ADD, SEARCH and EXIT.\n";
    while(true)
    {
        std::cout << "Enter a command: \n";
        if (!std::getline(std::cin, prompt)) 
        {
            std::cout << "EOF detected. Exiting.\n";
            break;
        }
        
        if (prompt == "ADD") 
        {
            if (!phonebook.addContact())
            {
                std::cout << "EOF detected. Exiting.\n";
                break;
            }
        }
        else if (prompt == "SEARCH")
        {
            if (!phonebook.searchContact())
            {
                std::cout << "EOF detected. Exiting.\n";
                break;
            }
        }
        else if (prompt == "EXIT")
            break ;

        else
            std::cout << "The program only accepts ADD, SEARCH and EXIT.\n";
    }
    return 0;
}

