#include "Trojkat.h"

Trojkat::Trojkat(int a, int b,int c) : _a(static_cast<double>(a)), _b(static_cast<double>(b)), _c(static_cast<double>(c)) {}

Trojkat::Trojkat(double a, double b,double c) : _a(a), _b(b), _c(c) {}


double Trojkat::polePow() const {
    double x = (_a + _b + _c) / 2; 
    return sqrt(x * (x - _a) * (x - _b) * (x - _c));
}

void Trojkat::wypisz(std::ostream& os) const {
    os << "Trojkat bokach: " << _a << " " << _b << " " << _c << std::endl;
}
