#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main(void) {
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cat();
    animals[3] = new Dog();
    std::cout << std::endl;

    Cat first;
    first.makeSound();
    first.setIdea(0, "I love milk");
    Cat second(first);
    second.makeSound();
    std::cout << second.getIdea(0) << std::endl;

    std::cout << animals[0]->getType() << " " << std::endl; 
    std::cout << animals[1]->getType() << " " << std::endl;

    std::cout << std::endl;

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }

    std::cout << std::endl;

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    return 0;
}