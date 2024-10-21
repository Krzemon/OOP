#ifndef TROJKAT_H
#define TROJKAT_H

#include "Ksztalt.h"
#include <cmath>

class Trojkat : public Ksztalt {
private:
    double _a;
    double _b;
    double _c;
public:
    Trojkat(int a, int b, int c);
    Trojkat(double a, double b,double c);
    void wypisz(std::ostream& os) const;
    double polePow() const;
};
#endif // TROJKAT_H