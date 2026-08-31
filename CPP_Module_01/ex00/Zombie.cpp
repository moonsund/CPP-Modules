#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
    _name = name;
}

void Zombie::announce(void) const {
        std::cout <<_name << ": BraiiiiiiinnnzzzZ...\n";
    }

Zombie::~Zombie() {
        std::cout <<_name << " is destroyed" << std::endl;
}