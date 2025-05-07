#include "Rectangle.h"

/**
 * konstruktor argumentowy
 */
Rectangle::Rectangle(std::string name, int a, int b): _name(name), _a(a), _b(b) {}

/**
 * metoda zwracajaca pole prostokata
 */
float Rectangle::Area() const {
    return _a*_b;
}

/**
 * przeciazony operator * (w klasie Rectangle)
 */
Rectangle& Rectangle::operator *(int m){
    _a *= 2;
    _b *= 2;
    return *this;
}

/**
 * gettery
 */
std::string Rectangle::getName() const {
    return _name;
}

int Rectangle::getA() const {
    return _a;
}

int Rectangle::getB() const {
    return _b;
}

/**
 * przeciazony operator ostream (poza klasą)
 */
std::ostream& operator <<(std::ostream& os, const Rectangle& rectangle) {
    os << "Rectangle: " << rectangle.getName() << " (width=" << rectangle.getA() << ", height=" << rectangle.getB() << ")";
    return os;
}