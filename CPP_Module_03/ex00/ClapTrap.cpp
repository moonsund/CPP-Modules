#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Great warrior " << _name << " was born!" <<std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "RIP " << _name <<std::endl;
}

std::string ClapTrap::getName(void) const {
    return _name;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return _attackDamage;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints = _energyPoints - 1;
        std::cout << "Warrior " 
                  << _name 
                  << " attacks " 
                  << target 
                  << ", causing " 
                  << _attackDamage 
                  << " point of damage!" 
                  <<std::endl;
    }
    else {
        std::cout << "Can't attack - not enough energy left." <<std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints < amount) {
        _hitPoints = 0;
    }
    else {
        _hitPoints = _hitPoints - amount;
    }
    std::cout << "Warrior " 
              << _name 
              << " was attacked, causing " 
              << amount 
              << " point of damage!" 
              <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _energyPoints = _energyPoints - 1;
        _hitPoints = _hitPoints + amount;
        std::cout << "Warrior " 
                  << _name 
                  << " heals himself, causing regaining of " 
                  << amount 
                  << " hit points!" 
                  << std::endl;
    }
    else {
        std::cout << "Can't heal - not enough energy left." <<std::endl;
    }
}