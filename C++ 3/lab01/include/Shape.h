#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    virtual std::string getName() const = 0;
    virtual float Area() const = 0;
};

#endif // SHAPE_H