#include "Harl.hpp"
#include <iostream>


int main(int ac, char** av) {
    if (ac != 2) {
        std::cout << "USAGE: ./harlFilter <level>" << std::endl;
        return 1;
    }

    std::string levels[] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"
        };

    Harl harl;
    void (Harl::*ptr)(size_t) = &Harl::complain;

    size_t level_index = -1;

    for (size_t i = 0; i < 4; i++) {
        if (levels[i] == av[1]) {
            level_index = i;
            break;
        };
    };

    switch (level_index) {
        case 0:
            (harl.*ptr)(level_index);
            break;
        case 1:
            (harl.*ptr)(level_index);
            break;
        case 2:
            (harl.*ptr)(level_index);
            break;
        case 3:
            (harl.*ptr)(level_index);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
