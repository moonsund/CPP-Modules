#ifndef AMATERIASOURCE_HPP
#define AMATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <iostream>

class MateriaSource : public IMateriaSource {
    private:
        AMateria* storage_[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        ~MateriaSource();
        void learnMateria(AMateria* materia);
        AMateria* createMateria(const std::string& type);

};

#endif
