#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void) {
    Animal* animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();
    Animal* meta = new Animal();
    WrongAnimal* wrongAnimal = new WrongCat();
    std::cout << std::endl;

    std::cout << animals[0]->getType() << " " << std::endl; 
    std::cout << animals[1]->getType() << " " << std::endl;
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }
    wrongAnimal->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }
    delete wrongAnimal;
    delete meta;

    return 0;
}