#include "ICharacter.hpp"

ICharacter::ICharacter() {}

ICharacter::ICharacter(const ICharacter& other) {
    (void)other;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
    (void)other;
    return *this;
}

ICharacter::~ICharacter() {}

