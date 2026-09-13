#include "Ice.hpp"

Ice::Ice() : AMateria("ice"), type_("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {
    type_ = other.type_;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}
        
Ice::~Ice() {}



AMateria* Ice::clone() const {
    return new Ice(*this);
}