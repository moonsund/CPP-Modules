#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain was born!" <<std::endl;
}


Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain was copied!" <<std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
    }
    std::cout << "operator= was used" <<std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain was erased!" <<std::endl;
}

void Brain::setIdea(int ndx, const std::string& idea) {
    if (ndx >= 0 && ndx < 100) {
        ideas[ndx] = idea;
    }
}

const std::string& Brain::getIdea(int ndx) const {
    return ideas[ndx];
}