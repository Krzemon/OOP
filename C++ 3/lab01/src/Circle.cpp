#include "Circle.h"
#include <cmath>

/**
 * konstruktor argumentowy
 */
Circle::Circle(std::string name, int r): _name(name), _r(r) {}

/**
 * metoda zwracajaca pole prostokata
 */
float Circle::Area() const {
    return _r*_r*M_PI;
}

/**
 * przeciazony operator + (w klasie Circle)
 */
Circle& Circle::operator +(const Circle& circle) const {
    return Circle("Combined", this->getR() + circle.getR());
}

/**
 * gettery
 */
std::string Circle::getName() const {
    return _name;
}

int Circle::getR() const {
    return _r;
}


/**
 * przeciazony operator ostream (poza klasą)
 */
std::ostream& operator <<(std::ostream& os, const Circle& circle) {
    os << "Circle: " << circle.getName() << " (radius=" << circle.getR() << ")";
    return os;
}