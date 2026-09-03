#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"
#include "string.h"

class FragTrap : public virtual ClapTrap {
    public:
        FragTrap(const std::string& name);
        ~FragTrap();

        void highFivesGuys(void) const;
};

#endif
