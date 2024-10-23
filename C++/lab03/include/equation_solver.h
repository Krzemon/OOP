#ifndef EQUATION_SOLVER_H
#define EQUATION_SOLVER_H

#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>
#include <complex>
#include <sstream>
#include <string>

// funkcja sprawdzająca, czy podany ciąg znaków jest liczbą
bool isNumber(const std::string& str);

// funkcja obsługująca jeden argument
void handleOneArgument(float a);

// funkcja obsługująca dwa argumenty
void handleTwoArguments(float a, float b);

// funkcja obsługująca trzy argumenty
void handleThreeArguments(float a, float b, float c);

#endif // EQUATION_SOLVER_H