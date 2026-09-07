#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main(void) {
    Animal* animals[2];

    animals[0] = new Dog();
    animals[1] = new Cat();
    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}