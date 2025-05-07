#include "Rational.h"


void Rational::simplify() {
    int gcd;
    for(int gcd=1; gcd<=_q; gcd++) {
        if (this->_q % gcd == 0){
            if (this->_p % gcd == 0) {
                this->_p /= gcd;
                this->_q /= gcd;
            }
        }
    }
}

Rational::Rational(int p, int q) : _p{p}, _q{q} {
    if (q == 0) {
        std::cout << "Nie dzielimy przez zero!!!" << std::endl;
        exit(-1);
    }
    for(int gcd=1; gcd<=_q; gcd++) {
        simplify();
    }
}

Rational::operator double() {
    return static_cast<double>(get_p()) / static_cast<double>(get_q());
}

Rational::operator int() {
    return get_p() / get_q();
}

Rational& Rational::operator ++() {
    for(int i=0; i<this->_q; ++i){
        ++this->_p;
    } 
    return *this;
}

Rational Rational::operator ++(int a){
    Rational ratio(this->_p, this->_q);
    for(int i=0; i<this->_q; ++i){
        this->_p++;
    } 
    return ratio;
}

std::ostream& operator <<(std::ostream& os, const Rational& rational) {
    os << rational.get_p() << "/" << rational.get_q();
    return os;
}