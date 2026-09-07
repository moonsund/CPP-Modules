#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iomanip>
#include <iostream>
#include <string>

void printHeader()
{
    std::cout << std::left
              << std::setw(16) << "Class"
              << std::setw(24) << "Name"
              << std::right
              << std::setw(14) << "Hit points"
              << std::setw(16) << "Energy points"
              << std::setw(16) << "Attack damage"
              << std::endl;

    std::cout << std::string(86, '-') << std::endl;
}

void printRow(const std::string& className, const ClapTrap& object)
{
    std::cout << std::left
              << std::setw(16) << className
              << std::setw(24) << object.getName()
              << std::right
              << std::setw(14) << object.getHitPoints()
              << std::setw(16) << object.getEnergyPoints()
              << std::setw(16) << object.getAttackDamage()
              << std::endl;
}

int main(void) {
    ClapTrap clap("Clap");
    std::cout << std::endl;

    ScavTrap scav("Scav");
    std::cout << std::endl;

    FragTrap frag("Frag");
    std::cout << std::endl;

    DiamondTrap diamond("Diamond");
    std::cout << std::endl;

    diamond.whoAmI();
    std::cout << std::endl;

    printHeader();

    printRow("ClapTrap", clap);
    printRow("ScavTrap", scav);
    printRow("FragTrap", frag);
    printRow("DiamondTrap", diamond);
    std::cout << std::endl;
}