#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name) : ICharacter(), name_(name) {
    for (int i = 0; i < 4; i++) {
        inventory_[i] = 0;
    }
    std::cout << "Character " << name << " was created" << std::endl;
};

Character::Character(const Character& other) : name_(other.name_) {
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
        name_ = other.name_; 
    }
    return *this;
};

Character::~Character() {
    int materiaCount = 0;
    for (int i = 0; i < 4; i++) {
        if (inventory_[i] != 0) {
            delete inventory_[i];
            inventory_[i] = 0;
            materiaCount++;
        }
    }
    std::cout << "Character " << name_ << " destroyed: " << materiaCount << " stored objects deleted" << std::endl;
};

const std::string& Character::getName() const {
    return name_;
}

void Character::equip(AMateria* materia) {
    if (materia == 0) {
        std::cout << "Null pointer ignored" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (inventory_[i] == materia) {
            std::cout << "Pointer already stored in slot " << i << "; ignored" << std::endl;
            return ;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (inventory_[i] == 0) {
            inventory_[i] = materia;
            std::cout << "Materia " << materia->getType() << " stored in slot # " << i << std::endl;
            return ;
        }
    }
    std::cout << "[Character] Inventory full; materia not equipped\n";
};

void Character::unequip(int index) {
    if (index < 0 || index > 3)
        return ;
    if (inventory_[index] != 0)
        std::cout << "Character unequipped Materia " << inventory_[index]->getType() << " from slot # " << index << std::endl;
    inventory_[index] = 0;
    return ;
};

void Character::use(int index, ICharacter& target) {
    if (index < 0 || index > 3)
        return ;
    if (inventory_[index] != 0)
        inventory_[index]->use(target);
    return ;
}

AMateria* Character::getMateriaAddress(int index) const {
    if (index < 0 || index > 3)
        return 0;
    return inventory_[index];
}
