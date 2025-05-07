// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zdefiniowanie klasy Rational która reprezentuje liczby wymierne 
// w postaci ułamka p/q, gdzie p to licznik, a q to mianownik (z q ≠ 0). 
// Klasa powinna wspierać podstawowe operacje oraz konwersje:
// * Niejawna konwersja umożliwiająca rzutowanie Rational na double;
// * Jawna konwersja pozwalająca na rzutowanie Rational na int.
// * Operatory inkrementacji: 
//   - Pre-inkrementacja (++r) – zwiększa wartość o 1 (czyli dodaje denominator do numerator).
//   - Post-inkrementacja (r++) – działa tak samo, ale zwraca starą wartość.
// * Operator wyjścia << Powinien umożliwiać wypisywanie Rational w postaci p/q.
// * Dodatkowym atutem będzie implementacja prywatnej metody simplify() 
//   – upraszczająca ułamek do najprostszej postaci.
//   - działa to poprzez znalezienie największego wspólnego dzielnika (GCD – Greatest Common Divisor)
//     licznika i mianownika, a następnie podzielenie obu tych wartości przez GCD.
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Pliku Main.cpp, nie wolno modyfikowac.
// Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materiałów.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab02/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include <iomanip>
#include "Rational.h"

int main() {
    std::cout << std::setprecision(2);
    Rational r1(3, 4); // Standard instantiation
    // Rational r2 = 5; // ERROR: conversion from ‘int’ to non-scalar type ‘Rational’ requested
    Rational r3(7, 2);
    
    std::cout << r1 << std::endl;
    std::cout << r3 << std::endl;
    
    double d = r1; // Implicit conversion to double
    int i = static_cast<int>(r3); // Explicit conversion to int
    
    std::cout << "Converted to double: " << d << std::endl;
    std::cout << "Converted to int: " << i << std::endl;

    std::cout << "Before prefix increment: ";
    std::cout << r1 << std::endl;
    std::cout << "After prefix increment: ";
    std::cout << ++(++r1) << std::endl;

    std::cout << "Before postfix increment: ";
    std::cout << r3 << std::endl;
    Rational r3_old = r3++;
    std::cout << "After postfix increment (old value): ";
    std::cout << r3_old << std::endl;
    std::cout << "After postfix increment (new value): ";
    std::cout << r3 << std::endl;
    
    return 0;
}

/* wynik
3/4
7/2
Converted to double: 0.75
Converted to int: 3
Before prefix increment: 3/4
After prefix increment: 11/4
Before postfix increment: 7/2
After postfix increment (old value): 7/2
After postfix increment (new value): 9/2
 */

