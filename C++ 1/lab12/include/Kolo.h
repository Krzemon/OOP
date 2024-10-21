#ifndef KOLO_H
#define KOLO_H

#include "Ksztalt.h"

class Kolo : public Ksztalt {
public:
    Kolo(double promien);
    double polePow() const;
    void wypisz(std::ostream& os) const;
private:
    double promien_;
};

#endif
