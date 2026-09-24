#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#include <string>

class Character : public ICharacter {
    private:
        std::string name_;
        AMateria* inventory_[4];
    
    public:
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        const std::string& getName() const;
        void equip(AMateria* materia);
        void unequip(int index);
        void use(int index, ICharacter& target);
};

#endif