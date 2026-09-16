#include <iostream>

class ILabel {
    public:
        virtual ~ILabel() { std::cout << "~ilabel\n"; };
        virtual void print() const =0;
        virtual ILabel* clone() const =0;
        virtual void setPrice(int price) =0;
};

class PriceLabel : public ILabel {
    protected:
        int price_;
    
    public:
        PriceLabel(int price) {
            price_ = price;
        }

        ~PriceLabel() { std::cout << "~pricelabel\n"; }
        
        void print() const {
            std::cout << price_ << std::endl;
        }

        ILabel* clone() const {
            ILabel* copy = new PriceLabel(*this);
            return copy;
        }

        void setPrice(int price) {
            price_ = price;
        }
};


int main() {
    const ILabel& first = PriceLabel(10);
    first.print();
    ILabel* second = first.clone();
    second->print();
    second->setPrice(100);
    first.print();
    second->print();
    delete second;
    return 0;
}