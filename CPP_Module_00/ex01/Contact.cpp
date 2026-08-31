#include "Contact.hpp"

const std::string& Contact::getFirstName() const {
    return _first_name;
}
const std::string& Contact::getLastName() const {
    return _last_name;
}
const std::string& Contact::getNickName() const {
    return _nick_name;
}
const std::string& Contact::getPhoneNumber() const {
    return _phone_number;
}
const std::string& Contact::getSecret() const {
    return _secret;
}

void Contact::setFirstName(const std::string& first_name) {
	_first_name = first_name;
}
void Contact::setLastName(const std::string& last_name) {
	_last_name = last_name;
}
void Contact::setNickName(const std::string& nick_name) {
	_nick_name = nick_name;
}
void Contact::setPhoneNumber(const std::string& phone_number) {
	_phone_number = phone_number;
}
void Contact::setSecret(const std::string& secret) {
	_secret = secret;
}