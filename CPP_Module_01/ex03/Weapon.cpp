#include "Weapon.hpp"

Weapon::Weapon(const std::string& weapon_type) : _type(weapon_type) {};

const std::string& Weapon::getType(void) const {
    return _type;
}

void Weapon::setType(const std::string& new_value) {
    _type = new_value;
}
