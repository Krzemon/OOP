#include "Kolo.h"

Kolo::Kolo(int r) : _r(static_cast<double>(r)) {}

Kolo::Kolo(double r) : _r(r) {}

void Kolo::wypisz(std::ostream& os) const {
    os << "Kolo o promieniu: " << _r << std::endl;
}
