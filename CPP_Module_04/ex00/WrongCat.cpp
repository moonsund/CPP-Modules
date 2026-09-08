#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    type_ = "Wrong Cat";
    std::cout << "New wrong cat was born!" <<std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "Wrong cat was copied" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Wrong cat died " <<std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "Wrong cat can meow" <<std::endl;
}