#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
    public:
        Weapon(const std::string& weapon_type);
        const std::string& getType(void) const;
        void setType(const std::string& new_value);

    private:
        std::string _type;
};

#endif