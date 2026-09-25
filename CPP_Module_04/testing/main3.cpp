#include <iostream>
#include <string>

class IDocument {
    protected:
        std::string type_;
        std::string data_;

    public:
        IDocument(const std::string& type, const std::string& data)
            : type_(type), data_(data) {};
        virtual ~IDocument() {}
        virtual const std::string& getType() const = 0;
        virtual IDocument* clone() const = 0;
        virtual void print() const = 0;
};


class Catalog {
    private:
        IDocument* documents_[3];

    public:
        Catalog() {
            for (int i = 0; i < 3; i++) {
                documents_[i] = 0;
            }
        };

        ~Catalog() {
            for (int i = 0; i < 3; i++) {
                if (documents_[i] != 0) {
                    delete documents_[i];
                    documents_[i] = 0;
                }
            }
            std::cout << "Catalog was erased" << std::endl;
        };

        bool accept(const IDocument& sample) {
            for (int i = 0; i < 3; i++) {
                if (documents_[i] == 0) {
                    documents_[i] = sample.clone();
                    return true;
                }
            }
            return false;
        }

        IDocument* create(const std::string& type) const {
            for (int i = 0; i < 3; i++) {
                if (documents_[i] != 0 && documents_[i]->getType() == type) {
                    return documents_[i]->clone();
                }
            }
            return 0;
        }

        void printDoc(int index) {
            documents_[index]->print();
        }
};


class Letter : public IDocument {
    public:
        Letter(const std::string& data) : IDocument("letter", data) {};

        Letter(const Letter& other) : IDocument(other) {};
       
        ~Letter() {
            std::cout << type_ << " was destroyed" << std::endl;
        };

        IDocument* clone() const {
            IDocument* copy = new Letter(*this);
            std::cout << "Letter was copied" << std::endl;
            return copy;
        };

        void print() const {
            std::cout << "Data: " << data_ << std::endl;
        }

        const std::string& getType() const {
            return type_;
        }

};

int main() {
    Letter first("first Letter");
    Letter& ref1 = first; 
    Letter second("second Letter");
    Letter& ref2 = second; 
    Catalog catalog;
    if (catalog.accept(ref1)) {
        std::cout << "the document was accepted" << std::endl;
    }
    IDocument* copy = catalog.create("letter");
    copy->print();
    delete copy;
    catalog.printDoc(0);






    return 0;
}