#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"
#include "string.h"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        ~FragTrap();

        void highFivesGuys(void) const;
};

#endif
