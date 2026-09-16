#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type_(type) {}

AMateria::AMateria(const AMateria& other) {
    type_ = other.type_;
}

AMateria& AMateria::operator=(const AMateria& other) {
    (void)other;
    return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { //Returns the materia type
    return type_;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}