#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _rawValue;
        static const int _fractionalBits = 8;

    public:
        Fixed();    // default constructor
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed& other);  // copy constructor
        Fixed& operator=(const Fixed& other);   // assignment operator
        ~Fixed();   // destructor
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& value);

#endif
