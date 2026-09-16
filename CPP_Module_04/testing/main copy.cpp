#include <iostream>

class Exhibition {
    private:
        IExhibit* exhibit_;

    public:
        Exhibition() {};
        Exhibition(const Exhibition* other) {};
        ~Exhibition() {};
};

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

class Painting : public IExhibit {
    public:
        Painting(std::string name) : IExhibit(name) {};
        ~Painting() {};
        IExhibit* clone() const {};
        
        void show() const {
            std::cout << "Painting " << name_ << " is on display" << std::endl;
        }
};



int main() {

    
    return 0;
}