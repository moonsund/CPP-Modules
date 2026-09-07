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
    ClapTrap clap("Clap");
    displayCurrent(clap);
    std::cout << std::endl;

    clap.takeDamage(5);
    displayCurrent(clap);
    std::cout << std::endl;
    
    clap.beRepaired(5);
    displayCurrent(clap);
    std::cout << std::endl;

    for (int i = 0; i < 9; i++) {
        clap.attack("Arminius");
    }
    displayCurrent(clap);
    clap.attack("Arminius");
    std::cout << std::endl;
}