#include "Kolo.h"

Kolo::Kolo(double promien) : promien_(promien) {}

double Kolo::polePow() const {
    return 3.1415 * promien_ * promien_;
}

void Kolo::wypisz(std::ostream& os) const {
    os << "Kolo o promieniu: " << promien_ << std::endl;
}
