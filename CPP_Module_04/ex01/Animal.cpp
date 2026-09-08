#include "Animal.hpp"

Animal::Animal() : type_("default animal") {
    std::cout << "Animal was born!" <<std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_) {}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type_ = other.type_;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal died" <<std::endl;
}

std::string Animal::getType(void) const {
    return this->type_;
}

void Animal::makeSound(void) const {
    std::cout << "Any animal can make a sound" <<std::endl;
}