#include "Cat.hpp"

Cat::Cat() : Animal() {
    type_ = "Cat";
    std::cout << "New cat was born!" <<std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat was copied" <<std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat died " <<std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Cat can meow" <<std::endl;
}