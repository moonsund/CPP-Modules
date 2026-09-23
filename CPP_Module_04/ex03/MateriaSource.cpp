#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    for (int i = 0; i < 4; i++) {
        storage_[i] = 0;
    }
};

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {
    for (int i = 0; i < 4; i++) {
        if (other.storage_[i] != 0)
            storage_[i] = other.storage_[i]->clone();
    }
};

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (storage_[i] != 0) {
                delete storage_[i];
                storage_[i] = 0;
            }
            if (other.storage_[i] != 0)
                storage_[i] = other.storage_[i]->clone();
        }
    }
    return *this;
};

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (storage_[i] != 0) {
            delete storage_[i];
            storage_[i] = 0;
        }
    }
};

void MateriaSource::learnMateria(AMateria* materia) {
    if (materia == 0)
        return ;
    for (int i = 0; i < 4; i++) {
        if (storage_[i] == 0) {
            storage_[i] = materia->clone();
            return ;
        }
    }
};

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (storage_[i]->getType() == type) {
            AMateria* clone = storage_[i]->clone();
            return clone;
        }
    }
};