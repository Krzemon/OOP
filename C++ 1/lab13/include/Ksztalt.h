#ifndef KSZTALT_H
#define KSZTALT_H

#include <iostream>

class Ksztalt {
public:
    virtual double polePow() const = 0;
    virtual void wypisz(std::ostream& os) const = 0;
};

void wypisz(const Ksztalt& ksztalt);

#endif // KSZTALT_H