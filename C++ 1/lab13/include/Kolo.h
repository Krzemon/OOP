#ifndef KOLO_H
#define KOLO_H

#include "Ksztalt.h"

static double mypi = 3.1415;

class Kolo : public Ksztalt {
private:
    double _r;
public:
    Kolo(int r);
    Kolo(double r);
    void wypisz(std::ostream& os) const;
    double polePow() const {return mypi * _r * _r;}
};

#endif // KOLO_H