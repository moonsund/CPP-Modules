#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _rawValue;
        static const int _fractionalBits = 8;

    public:
        Fixed();    // default constructor
        Fixed(const Fixed& other);  // copy constructor
        Fixed& operator=(const Fixed& other);   // assignment operator
        ~Fixed();   // destructor
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
