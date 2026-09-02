#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
    std::cout << "Great ClapTrap warrior " << name_ << " was born!" <<std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "RIP ClapTrap warrior " << name_ <<std::endl;
}

std::string ClapTrap::getName(void) const {
    return name_;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return hitPoints_;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return energyPoints_;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return attackDamage_;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints_ > 0 && energyPoints_ > 0) {
        energyPoints_ = energyPoints_ - 1;
        std::cout << "ClapTrap warrior " 
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

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints_ < amount) {
        hitPoints_ = 0;
    }
    else {
        hitPoints_ = hitPoints_ - amount;
    }
    std::cout << "ClapTrap warrior " 
              << name_ 
              << " was attacked, causing " 
              << amount 
              << " point of damage!" 
              <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints_ > 0 && energyPoints_ > 0) {
        energyPoints_ = energyPoints_ - 1;
        hitPoints_ = hitPoints_ + amount;
        std::cout << "ClapTrap warrior " 
                  << name_ 
                  << " heals himself, causing regaining of " 
                  << amount 
                  << " hit points!" 
                  << std::endl;
    }
    else {
        std::cout << "Can't heal - not enough energy left." <<std::endl;
    }
}