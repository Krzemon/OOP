#ifndef CPLXNUMBER_H
#define CPLXNUMBER_H

#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

class CplxVector;

class CplxNumber {
public:
    CplxNumber();
    CplxNumber(double re, double im);

    static int DisplayPrecision;
    void Print() const;
    static double Abs(const CplxNumber& cplx_num);  // Statyczna metoda Abs

    double GetRe() const { return this->re_; }
    double GetIm() const { return this->im_; }
    operator std::string() const;
    operator double() const { return Abs(*this); }

private:
    friend class CplxVector;

    double re_;
    double im_;
};

class CplxVector {
public:
    CplxVector();
    CplxVector(double value);  // Dodany konstruktor przyjmujący double
    // explicit CplxVector(double xy);

    CplxVector& SetX(const CplxNumber& num);
    CplxVector& SetY(double re, double im);
    CplxVector& SetZ(double re, double im);

    CplxNumber X() const;
    void Print() const;

private:
    std::vector<CplxNumber> cplxVec_;
};

#endif // CPLXNUMBER_H
