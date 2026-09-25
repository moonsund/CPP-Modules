#include <iostream>
#include <string>

class IExhibit {
    protected:
        std::string name_;

    public:
        IExhibit(std::string name) : name_(name) {}
        IExhibit() {};
        virtual ~IExhibit() {};
        virtual IExhibit* clone() const = 0;
        const std::string& getName() const {return name_;};
        virtual void show() const = 0;
};


class Exhibition {
    private:
        IExhibit* exhibit_[3];

    public:
        Exhibition() {
            for (int i = 0; i < 3; i++) {
                exhibit_[i] = 0;
            }
        };

        // Exhibition(IExhibit* exhibit) : exhibit_(exhibit) {};

        // Exhibition(const Exhibition& other) {
        //     if (other.exhibit_ == 0) {
        //         this->exhibit_ = 0;
        //     }
        //     else {
        //         IExhibit* tmp = other.exhibit_->clone();
        //         this->exhibit_ = tmp;
        //     }
        // };

        ~Exhibition() {
            for (int i = 0; i < 3; i++) {
                if (exhibit_[i] != 0) {
                    delete exhibit_[i];
                    exhibit_[i] = 0;
                }
            }
            std::cout << "Exhibition was closed" << std::endl;
        };

        bool add(IExhibit* exhibit) {
            if (exhibit == 0)
                return false;
            for (int i = 0; i < 3; i++) {
                if (exhibit_[i] == 0) {
                    exhibit_[i] = exhibit;
                    return true;
                }
            }
            return false;
        }

        IExhibit* release(int index) {
            if (index < 0 || index > 2) {
                std::cout << "incorrect index" << std::endl;
                return 0;
            }
            if (exhibit_[index] != 0) {
                IExhibit* tmp = exhibit_[index];
                exhibit_[index] = 0;
                return tmp;
            }
            return 0;
        }
        
        void show(int index) const {
            if (index < 0 || index > 2) {
                std::cout << "incorrect index" << std::endl;
                return ;
            }
            if (exhibit_[index] == 0) {
                std::cout << "Empty" << std::endl;
            }
            else {
                exhibit_[index]->show();
            }
        }
};


class Painting : public IExhibit {
    public:
        Painting(std::string name) : IExhibit(name) {};
        Painting(const Painting& other) : IExhibit(other) {};
        ~Painting() {
            std::cout << "Painting " << name_ << " was destroyed" << std::endl;
        };

        IExhibit* clone() const {
            IExhibit* copy = new Painting(*this);
            std::cout << "Painting was copied" << std::endl;
            return copy;
        };

        void show() const {
            std::cout << "Painting " << name_ << " is on display" << std::endl;
        }
};

int main() {
    Painting* first = new Painting("Mone");
    Painting* second = new Painting("Dali");
    Painting* third = new Painting("Van Gog");
    Painting* fourth = new Painting("Mane");
    Exhibition exhibition;
    exhibition.add(first);
    exhibition.add(second);
    exhibition.add(third);
    
    if (!exhibition.add(fourth)) {
        std::cout << "exhibition is full" << std::endl;
        delete fourth;
        fourth = 0;
    }

    exhibition.show(1);
    exhibition.release(1);
    exhibition.show(1);

    second->show();
    delete second;
    second = 0;
    Painting* fifth = new Painting("Mane");
    exhibition.add(fifth);
    exhibition.show(1);
    std::cout << "exhibition is full" << std::endl;

    exhibition.show(4);
    exhibition.release(-1);


    return 0;
}