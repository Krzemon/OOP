#include <iostream>

struct Base {
protected:
    virtual void print() const {
        std::cout << "Wywołano Base::print()" << std::endl;
    }
public:
    void callPrint() const {
        print(); // Wywołuje print() z bieżącej klasy lub pochodnej
    }
};

struct Derived : Base {
protected:
    void print() const override {
        std::cout << "Wywołano Derived::print()" << std::endl;
    }
public:
    void callPrintDerived() const {
        print(); // Wywołuje Derived::print()
        Base::print(); // Wywołuje Base::print()
    }
};

int main() {
    Base base;
    Derived derived;

    base.callPrint();       // Wywołano Base::print()
    derived.callPrint();    // Wywołano Derived::print() (polimorfizm)
    derived.callPrintDerived(); // Wywołano Derived::print(), potem Base::print()

    return 0;
}