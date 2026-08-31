#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(const std::string& name) {
    _name = name;    
}

void Zombie::announce(void) const {
    std::cout <<_name << " was born\n";
}

void Zombie::setName(const std::string& name) {
    _name = name;
}

Zombie::~Zombie(void) {
    std::cout <<_name << " died" << std::endl;
}
