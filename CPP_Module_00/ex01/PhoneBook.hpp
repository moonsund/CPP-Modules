#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook 
{
    private:
        Contact contacts[8];
        int		_contact_count;
		int		_index;
        
    public:
        PhoneBook();

        bool addContact();
        bool searchContact() const;
        
};

#endif