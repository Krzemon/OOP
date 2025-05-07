#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    int _p,_q; 

    // upraszcza ulamek do prostej postaci
    void simplify();

public:
    explicit Rational(int p, int q);

    // gettery
    int get_p() const {
        return this->_p;
    }
    int get_q() const {
        return this->_q;
    }

    // operator rzutowania Rational na double 
    operator double();
    // operator rzutowania Rational na int 
    explicit operator int();
    // operator pre-inkrementacji
    Rational& operator ++();
    // operator post-inkrementacji
    Rational operator ++(int a);

};

// operator wyjscia
std::ostream& operator <<(std::ostream& os, const Rational& rational);

#endif // RATIONAL_H 