#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape {
private:
    std::string _name; 
    int _a, _b;
public:
    Rectangle(std::string str, int a, int b);
    float Area() const override;
    Rectangle& operator *(int m);

    std::string getName() const override;
    int getA() const;
    int getB() const;
};

std::ostream& operator <<(std::ostream& os, const Rectangle& rectangle);

#endif // RECTANGLE_H