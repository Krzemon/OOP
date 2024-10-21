#ifndef LINE_H
#define LINE_H

#include <iostream>

class LPrint;
class LArray;

class Line{
friend class LPrint;    
public:
    Line();
    Line(double a, double b);
    Line(double num);
    Line(int num);

    double operator()(double x) const;

    double X0() const;

private:
    double _a;
    double _b;
};

class LPrint{
public:
    LPrint();
    void operator()(const Line& line) const;
    void operator()(const LArray& line_arr) const;
};

class LArray {
    friend class LPrint;    
public:
    LArray(unsigned size);
    ~LArray();

    Line operator[](unsigned idx) const;
    
    LArray& Add(const Line& line);

private:
    unsigned _size;
    unsigned _n_lines;
    Line* _line_arr;
};

#endif //LINE_H