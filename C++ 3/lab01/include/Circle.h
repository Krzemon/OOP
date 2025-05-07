#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape {
private:
    std::string _name;
    int _r;
public:
    Circle(std::string str, int r);
    float Area() const override;
    Circle operator +(const Circle& circle) const;


    std::string getName() const override;
    int getR() const;
};

std::ostream& operator <<(std::ostream& os, const Circle& circle);

#endif // CIRCLE_H

