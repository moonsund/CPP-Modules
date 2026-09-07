#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    ScavTrap scav("Scav");
    displayCurrent(scav);
    std::cout << std::endl;


    clap.attack("Scav");
    scav.attack("Clap");
    scav.guardGate();
    std::cout << std::endl;
}