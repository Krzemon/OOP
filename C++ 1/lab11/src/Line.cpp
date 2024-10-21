#include "Line.h"

Line::Line(): Line(1.0,1.0) {}
Line::Line(double a, double b): _a(a), _b(b) {}
Line::Line(double num): Line(num, num) {}
Line::Line(int num): Line(static_cast<double>(num), static_cast<double>(num)){}

double Line::operator()(double x) const {return _a * x + _b;}

double Line::X0() const {
    if(_a < 1e-9){
        std::cerr << "Nie ma przeciecia. Zwracane zero" << std::endl;
        return 0;
    }
    return -_b/_a;
}

LPrint::LPrint() {}

void LPrint::operator()(const Line& line) const {
    std::cout << "y = " << line._a << "* x + "<< line._b << "\tx0 = " << line.X0() << std::endl;  
}

void LPrint::operator()(const LArray& line_arr) const {
    for(unsigned i=0; i < line_arr._n_lines; i++ ){
        Line line = line_arr[i];
        std::cout << "[" << i  << "] ";
        (*this)(line);
    }
}

LArray::LArray(unsigned size): _size(size), _n_lines(0), _line_arr(new Line[size]) {}

LArray::~LArray() {
    delete [] _line_arr;
}

Line LArray::operator[](unsigned idx) const{
    return _line_arr[idx];
}

LArray& LArray::Add(const Line& line){ 
    if(_n_lines == _size){
        std::cerr << "Nie ma juz miejsca" << std::endl;
    }
    else{
        _line_arr[_n_lines] = line;
        _n_lines++;
    }

    return *this;
}


