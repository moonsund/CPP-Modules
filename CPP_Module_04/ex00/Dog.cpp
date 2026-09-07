#include "Dog.hpp"

Dog::Dog() : Animal() {
    type_ = "Dog";
    std::cout << "New dog was born!" <<std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog was copied" <<std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other) {
       Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog died " <<std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Dog can bark" <<std::endl;
}