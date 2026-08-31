#include "Fixed.hpp"
#include <cmath>
#include <stdexcept>

Fixed::Fixed() : _rawValue(0) {}

Fixed::Fixed(const int number)  {
    _rawValue = number * (1 << _fractionalBits);
}

Fixed::Fixed(const float number) {
    _rawValue = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    _rawValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _rawValue = other.getRawBits();
    }
    return *this;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->_rawValue + other.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->_rawValue - other.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed res;
    long result = (this->_rawValue * other.getRawBits()) / (1 << _fractionalBits);
    res.setRawBits(result);
    return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.getRawBits() == 0) {
        throw std::domain_error("Fixed: division by zero");
    }
    long result = (this->_rawValue * (1 << _fractionalBits)) / other.getRawBits();
    Fixed res;    
    res.setRawBits(result);
    
   return res;
}

Fixed& Fixed::operator++() {
    this->setRawBits(this->_rawValue + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed res(*this);
    this->setRawBits(this->_rawValue + 1);
    return res;
}

Fixed& Fixed::operator--() {
    this->setRawBits(this->_rawValue - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed res(*this);
    this->setRawBits(this->_rawValue - 1);
    return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() <= b.getRawBits()) 
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() <= b.getRawBits()) 
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() >= b.getRawBits()) 
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() >= b.getRawBits()) 
        return a;
    return b;
}

Fixed::~Fixed() {};

int Fixed::getRawBits(void) const {
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
