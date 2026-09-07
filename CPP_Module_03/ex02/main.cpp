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
    ClapTrap clap("Clap");
    displayCurrent(clap);
    std::cout << std::endl;

    ScavTrap scav("Scav");
    displayCurrent(scav);
    std::cout << std::endl;

    FragTrap frag("Frag");
    displayCurrent(frag);

    clap.attack("Scav");
    scav.attack("Clap");
    frag.attack("Scav");
    std::cout << std::endl;
    frag.highFivesGuys();
    scav.guardGate();
    std::cout << std::endl;
}