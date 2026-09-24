#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name) : ICharacter(), name_(name) {
    for (int i = 0; i < 4; i++) {
        inventory_[i] = 0;
    }
};

Character::Character(const Character& other) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory_[i] != 0)
            inventory_[i] = other.inventory_[i]->clone();
        else
            inventory_[i] = 0;
    }
};

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (other.inventory_[i] != 0) {
                AMateria* tmp =  other.inventory_[i]->clone();
                if (inventory_[i] != 0) {
                    delete inventory_[i];
                }
                inventory_[i] = tmp;
            }
            else {
                if (inventory_[i] != 0) {
                    delete inventory_[i];
                }
                inventory_[i] = 0;
            }
        }
    }
    return *this;
};

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory_[i] != 0) {
            delete inventory_[i];
            inventory_[i] = 0;
        }
    }
};

const std::string& Character::getName() const {
    return name_;
}

void Character::equip(AMateria* materia) {
    if (materia == 0)
        return ;
    for (int i = 0; i < 4; i++) {
        if (inventory_[i] == 0) {
            inventory_[i] = materia->clone();
            return ;
        }
    }
};

void Character::unequip(int index) {
    if (index < 0 || index > 3)
        return ;
    inventory_[index] = 0;
    return ;
};

void Character::use(int index, ICharacter& target) {
    if (index < 0 || index > 3)
        return ;
    inventory_[index]->use(target);
    return ;
}
