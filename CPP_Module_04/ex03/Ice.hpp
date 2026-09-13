#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    private:
        std::string type_;


    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        ~Ice();

        const std::string& getType() const; //Returns the materia type
        AMateria* clone() const;
};



#endif