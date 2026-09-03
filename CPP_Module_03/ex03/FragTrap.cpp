#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 100;
    attackDamage_ = 30;
    std::cout << "Great ClapTrap warrior " << name_ << " was promoted to be a FlagTrap warrior!" <<std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "RIP FlagTrap warrior " << name_ <<std::endl;
}

void FragTrap::highFivesGuys(void) const {
    std::cout << "I salute you!" <<std::endl;
}
