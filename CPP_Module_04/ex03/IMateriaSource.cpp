#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
    (void)other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
    (void)other;
    return *this;
}

IMateriaSource::~IMateriaSource() {}