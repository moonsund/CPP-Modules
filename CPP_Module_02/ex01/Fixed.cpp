#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _rawValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)  {
    std::cout << "Int constructor called" << std::endl;
    _rawValue = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    _rawValue = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    _rawValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            _rawValue = other.getRawBits();
        }
        return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawValue;
}

void Fixed::setRawBits(int const rawValue) {
    _rawValue = rawValue;
}

float Fixed::toFloat(void) const {
    return (float)_rawValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawValue / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& value) {
    output << value.toFloat();
    return output;
}
