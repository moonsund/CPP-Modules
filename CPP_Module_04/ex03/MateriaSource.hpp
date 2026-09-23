#ifndef AMATERIASOURCE_HPP
#define AMATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
    private:
        AMateria* storage_[4];

    public:
        MateriaSource();
        MateriaSource(const IMateriaSource& other);
        MateriaSource& operator=(const IMateriaSource& other);
        ~MateriaSource() {}
        void learnMateria(AMateria* materia) = 0;
        AMateria* createMateria(const std::string& type) = 0;

};

#endif
