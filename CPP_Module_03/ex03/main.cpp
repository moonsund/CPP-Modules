#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

void displayCurrent(ClapTrap& name) {
    std::cout << "Name: " 
               << name.getName() 
               << ". Hit points: " 
               << name.getHitPoints()
               << ". Energy points: "
               << name.getEnergyPoints()
               << ". Attack damage: "
               << name.getAttackDamage()
               << std::endl;
    std::cout << std::endl;
}

int main(void) {
    ClapTrap yorick("Yorick");
    displayCurrent(yorick);

    ScavTrap arminius("Arminius");
    displayCurrent(arminius);

    FragTrap julius("Julius");
    displayCurrent(julius);

    DiamondTrap neron("Neron");
    displayCurrent(neron);

    neron.whoAmI();
    std::cout << std::endl;
}