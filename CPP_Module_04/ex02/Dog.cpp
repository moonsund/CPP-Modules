#include "Dog.hpp"

Dog::Dog() : Animal() {
    type_ = "Dog";
    dogBrain_ = new Brain();
    std::cout << "New dog was born!" <<std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    dogBrain_ = new Brain(*other.dogBrain_);
    std::cout << "Dog was copied" <<std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.dogBrain_);
        delete dogBrain_;
        dogBrain_ = newBrain; 
    }
    std::cout << "cat's operator= was used" <<std::endl;
    return *this;
}

Dog::~Dog() {
    delete dogBrain_;
    std::cout << "Dog died " <<std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Dog barks" <<std::endl;
}

void Dog::setIdea(int ndx, const std::string& idea) {
    if (ndx >= 0 && ndx < 100) {
        dogBrain_->setIdea(ndx, idea);
    }
}

const std::string& Dog::getIdea(int ndx) const {
    return dogBrain_->getIdea(ndx);
}