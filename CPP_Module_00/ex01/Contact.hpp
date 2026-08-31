#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{    
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _secret;

	public:
	    const std::string& getFirstName() const; 
        const std::string& getLastName() const; 
        const std::string& getNickName() const; 
        const std::string& getPhoneNumber() const; 
        const std::string& getSecret() const;

		void setFirstName(const std::string& first_name); 
        void setLastName(const std::string& last_name); 
        void setNickName(const std::string& nick_name); 
        void setPhoneNumber(const std::string& phone_number); 
        void setSecret(const std::string& secret);
};

#endif