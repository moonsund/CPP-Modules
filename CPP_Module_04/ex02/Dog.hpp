#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* dogBrain_;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        void makeSound(void) const;
        void setIdea(int ndx, const std::string& idea);
        const std::string& getIdea(int ndx) const;
};

#endif