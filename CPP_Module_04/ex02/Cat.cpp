#include "Cat.hpp"

Cat::Cat() : Animal() {
    type_ = "Cat";
    catBrain_ = new Brain;
    std::cout << "New cat was born!" <<std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    catBrain_ = new Brain(*other.catBrain_);
    std::cout << "Cat was copied" <<std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.catBrain_);
        delete catBrain_;
        catBrain_ = newBrain;
    }
    std::cout << "cat's operator= was used" <<std::endl;
    return *this;
}

Cat::~Cat() {
    delete catBrain_;
    std::cout << "Cat died " <<std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Cat meows" <<std::endl;
}

void Cat::setIdea(int ndx, const std::string& idea) {
    if (ndx >= 0 && ndx < 100) {
        catBrain_->setIdea(ndx, idea);
    }
}

const std::string& Cat::getIdea(int ndx) const {
    return catBrain_->getIdea(ndx);
}