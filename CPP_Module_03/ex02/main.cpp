#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
}

int main(void) {
    ClapTrap yorick("Yorick");
    displayCurrent(yorick);
    ScavTrap arminius("Arminius");
    displayCurrent(arminius);
    FragTrap julius("Julius");
    displayCurrent(julius);

    yorick.attack("Arminius");
    arminius.attack("Yorick");
    julius.attack("Arminius");
    julius.highFivesGuys();
    arminius.guardGate();
}