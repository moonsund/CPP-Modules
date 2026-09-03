#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name) {
        hitPoints_ = 100;
        energyPoints_ = 50;
        attackDamage_ = 30;
        std::cout << "Great FragTrap and ScavTrap warriors "
                << name_ 
                << " were merged into a DiamondTrap warrior!" <<std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "RIP DiamondTrap warrior " << name_ <<std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My ClapTrap name is " << ClapTrap::name_ << " My DiamondTrap name is " << name_ <<std::endl;
}