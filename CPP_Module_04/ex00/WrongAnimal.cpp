#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("default wrong animal") {
    std::cout << "Wrong animal was born!" <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_) {
    std::cout << "Wrong animal was copied" <<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type_ = other.type_;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong animal died" <<std::endl;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Any wrong animal can make a sound" <<std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->type_;
}