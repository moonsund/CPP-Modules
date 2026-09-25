#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
    for (int i = 0; i < 4; i++) {
        storage_[i] = 0;
    }
    std::cout << "MateriaSource was created" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other) {
    for (int i = 0; i < 4; i++) {
        if (other.storage_[i] != 0)
            storage_[i] = other.storage_[i]->clone();
        else
            storage_[i] = 0;
    }
};

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (other.storage_[i] != 0) {
                AMateria* tmp = other.storage_[i]->clone();
                if (storage_[i] != 0) {
                    delete storage_[i];
                }
                storage_[i] = tmp;
            }
            else {
                if (storage_[i] != 0) {
                    delete storage_[i];
                }
                storage_[i] = 0;
            }
        }
    }
    return *this;
};

MateriaSource::~MateriaSource() {
    int materiaCount = 0;
    for (int i = 0; i < 4; i++) {
        if (storage_[i] != 0) {
            delete storage_[i];
            storage_[i] = 0;
            materiaCount++;
        }
    }
    std::cout << "MateriaSource destroyed: " << materiaCount << " stored objects deleted" << std::endl;
};

void MateriaSource::learnMateria(AMateria* materia) {
    if (materia == 0) {
        std::cout << "Null pointer ignored" << std::endl;
        return ;
    }
        
    for (int i = 0; i < 4; i++) {
        if (storage_[i] == materia) {
            std::cout << "Pointer already stored in slot " << i << "; ignored" << std::endl;
            return ;
        }
            
    }
    for (int i = 0; i < 4; i++) {
        if (storage_[i] == 0) {
            storage_[i] = materia;
            std::cout << "Materia " << materia->getType() << " stored in slot # " << i << std::endl;
            return ;
        }
    }
    std::cout << "Storage full; deleting incoming materia: " << materia->getType() << std::endl;
    delete materia;
};

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (storage_[i] != 0 && storage_[i]->getType() == type) {
            AMateria* clone = storage_[i]->clone();
            std::cout << "Materia cloned: " << type << std::endl;
            return clone;
        }
    }
    std::cout << "Unknown materia type: " << type << std::endl;
    return 0;
};
