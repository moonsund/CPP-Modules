#include "Zombie.hpp"

int main(void) {
    std::cout << "Case 1 'Stack'\n";

    Zombie* dino = newZombie("Dino");
    dino->announce();
    dino->announce();
    delete dino;
    dino = NULL;
        
    std::cout << std::endl;
    std::cout << "Case 2 'Heap'\n";
    randomChump("Dino 2");
}