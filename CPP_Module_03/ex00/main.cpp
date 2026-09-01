#include "ClapTrap.hpp"

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

    yorick.takeDamage(5);
    displayCurrent(yorick);
    yorick.beRepaired(5);
    displayCurrent(yorick);

    for (int i = 0; i < 9; i++) {
        yorick.attack("Arminius");
    }
    displayCurrent(yorick);
    yorick.attack("Arminius");
}