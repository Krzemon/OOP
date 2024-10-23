#include <string>
#include <iostream>
#include "Sorter.h"
#include "Complex.h"

int main() {
    Sorter<int> ints(8);
    ints.add({ 5, 6, 4, 3, 6, 7, 2, 1 });
    ints.print();
    ints.sort();
    ints.print();

    const Sorter<int> ints2 = ints;
    ints2.print();

    Sorter<int> ints3 = std::move(ints);
    ints3.print();

    Sorter<std::string> strings(6);
    strings.add({ "e", "a", "d", "c", "f", "b" });
    strings.print();
    strings.sort();
    strings.print();

    Sorter<Complex> complexNums(5);
    complexNums.add({ Complex(2,1), Complex(1,1), Complex(1,9), Complex(0,1), Complex(-2,1) });
    complexNums.print();
    complexNums.sort();
    complexNums.print();

    return 0;
}
