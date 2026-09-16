#include <iostream>

class NumberBox
{
private:
    int* value_;

public:
    NumberBox(int value) : value_(new int(value)) {}

    NumberBox(const NumberBox& other) : value_(new int(*other.value_)) {}

    NumberBox& operator=(const NumberBox& other) {
        if (this != &other) {
            *this->value_ = *other.value_;
        }
        return *this;
    }

    ~NumberBox()
    {
        delete value_;
    }

    int get() const { return *value_; }
    void set(int value) { *value_ = value; }
};



int main() {
    NumberBox first(12);
    NumberBox second(80);

    second = first;
    first.set(90);

    std::cout << first.get() << '\n';
    std::cout << second.get() << '\n';

    second = second;
    std::cout << second.get() << '\n';
    return 0;
}