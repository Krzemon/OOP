#include "CplxVector.h"
#include <sstream>


int CplxNumber::DisplayPrecision = 1;

CplxNumber::CplxNumber() : re_(0.0), im_(0.0) {
    DisplayPrecision = 6;
}

CplxNumber::CplxNumber(double re, double im) : re_(re), im_(im) {}

void CplxNumber::Print() const {
    std::cout << std::fixed << std::setprecision(DisplayPrecision);
    std::cout << "(" << re_ << ", " << im_ << ")" << std::endl;
}

double CplxNumber::Abs(const CplxNumber& cplx_num) {
    return sqrt(cplx_num.GetRe() * cplx_num.GetRe() + cplx_num.GetIm() * cplx_num.GetIm());
}

CplxNumber::operator std::string() const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(6);
    out << "(" << re_ << ", " << im_ << ")";
    return out.str();
}

CplxVector::CplxVector() {
    cplxVec_.resize(3, CplxNumber(0.0, 0.0));
}


CplxVector::CplxVector(double value) {
    // Inicjalizuj wszystkie elementy wektora wartością 'value'
    cplxVec_.resize(3, CplxNumber(value, value));
}

// CplxVector::CplxVector(double xy) {
//     cplxVec_.resize(3, CplxNumber(xy, xy));
// }

CplxVector& CplxVector::SetX(const CplxNumber& num) {
    cplxVec_[0] = num;
    return *this;
}

CplxVector& CplxVector::SetY(double re, double im) {
    cplxVec_[1] = CplxNumber(re, im);
    return *this;
}

CplxVector& CplxVector::SetZ(double re, double im) {
    cplxVec_[2] = CplxNumber(re, im);
    return *this;
}

CplxNumber CplxVector::X() const {
    return cplxVec_[0];
}

void CplxVector::Print() const {
    std::cout << "[";
    for (const auto& num : cplxVec_) {
        std::cout << static_cast<std::string>(num) << ", ";
    }
    std::cout << "\b\b]" << std::endl;
}
