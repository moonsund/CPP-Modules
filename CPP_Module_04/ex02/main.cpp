#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

void letAnimalSpeak(const Animal& animal) {
    animal.makeSound();
}

int main(void) {
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cat();
    animals[3] = new Dog();
    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        letAnimalSpeak(*animals[i]);
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    return 0;
}