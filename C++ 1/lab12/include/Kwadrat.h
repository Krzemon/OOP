#ifndef KWADRAT_H
#define KWADRAT_H

#include "Ksztalt.h"

class Kwadrat : public Ksztalt {
public:
    Kwadrat(double bok);
    double polePow() const;
    void wypisz(std::ostream& os) const;
private:
    double bok_;
};

#endif
