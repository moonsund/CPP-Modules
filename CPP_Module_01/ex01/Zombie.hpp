#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie(void);
        Zombie(const std::string& name);
        ~Zombie();

        void setName(const std::string& name);
        void announce(void) const;

    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
