#include "Kwadrat.h"

Kwadrat::Kwadrat(double bok) : bok_(bok) {}

double Kwadrat::polePow() const {
    return bok_ * bok_;
}

void Kwadrat::wypisz(std::ostream& os) const {
    os << "Kwadrat o boku: " << bok_ << std::endl;
}
