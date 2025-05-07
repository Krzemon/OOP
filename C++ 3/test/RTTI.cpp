#include <iostream>
#include <typeinfo>

struct Animal {
    virtual ~Animal() = default;  // ważne: wirtualny destruktor umożliwia RTTI
};

struct Dog : Animal {
};

int main() {
    Animal* a = new Dog();

    // RTTI: typeid na obiekcie (dereferencja)
    std::cout << "typeid(*a).name() = " << typeid(*a).name() << "\n";

    // RTTI: typeid na wskaźniku (bez dereferencji)
    std::cout << "typeid(a).name() = " << typeid(a).name() << "\n";

    delete a;  // pamiętaj o zwolnieniu pamięci
    return 0;
}