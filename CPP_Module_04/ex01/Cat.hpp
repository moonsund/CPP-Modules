#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* catBrain_;

    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        ~Cat();

        void makeSound(void) const;
        void setIdea(int ndx, const std::string& idea);
        const std::string& getIdea(int ndx) const;
};

#endif