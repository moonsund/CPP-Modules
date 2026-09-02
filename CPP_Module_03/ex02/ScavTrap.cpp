#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints_ = 100;
    energyPoints_ = 50;
    attackDamage_ = 20;
    std::cout << "Great ClapTrap warrior " << name_ << " was promoted to be a ScavTrap warrior!" <<std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "RIP ScavTrap warrior " << name_ <<std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (hitPoints_ > 0 && energyPoints_ > 0) {
        energyPoints_ = energyPoints_ - 1;
        std::cout << "ScavTrap warrior " 
                  << name_ 
                  << " attacks " 
                  << target 
                  << ", causing " 
                  << attackDamage_ 
                  << " point of damage!" 
                  <<std::endl;
    }
    else {
        std::cout << "Can't attack - not enough energy left." <<std::endl;
    }
}

void ScavTrap::guardGate(void) const {
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
