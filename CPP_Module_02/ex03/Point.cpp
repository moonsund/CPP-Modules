#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point&) {
    return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const {
    return this->_x;
}

Fixed Point::getY(void) const {
    return this->_y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed AB = (b.getX() - a.getX()) * (point.getY() - a.getY())
             - (b.getY() - a.getY()) * (point.getX() - a.getX());

    Fixed BC = (c.getX() - b.getX()) * (point.getY() - b.getY())
             - (c.getY() - b.getY()) * (point.getX() - b.getX());

    Fixed CA = (a.getX() - c.getX()) * (point.getY() - c.getY())
             - (a.getY() - c.getY()) * (point.getX() - c.getX());

    bool allPositive = AB > 0 && BC > 0 && CA > 0;
    bool allNegative = AB < 0 && BC < 0 && CA < 0;

    return allPositive || allNegative;
}