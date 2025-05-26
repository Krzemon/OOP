#include <iostream>

struct Base {
    virtual void virtualPrint() const {
        std::cout << "Base::virtualPrint()" << std::endl;
    }
    void nonVirtualPrint() const {
        std::cout << "Base::nonVirtualPrint()" << std::endl;
    }
};

struct Derived1 : Base {
    void virtualPrint() const override {
        std::cout << "Derived1::virtualPrint()" << std::endl;
    }
    void nonVirtualPrint() const {
        std::cout << "Derived1::nonVirtualPrint()" << std::endl;
    }
};

struct Derived2 : Base {
    // Brak nadpisywania, dziedziczy virtualPrint i nonVirtualPrint
};

void callPrint(const Base& obj) {
    obj.virtualPrint();    // Późne wiązanie
    obj.nonVirtualPrint(); // Wczesne wiązanie
}

int main() {
    Base base;
    Derived1 derived1;
    Derived2 derived2;

    std::cout << "Wywołania przez referencję do Base:" << std::endl;
    callPrint(base);    // Base::virtualPrint(), Base::nonVirtualPrint()
    callPrint(derived1); // Derived1::virtualPrint(), Base::nonVirtualPrint()
    callPrint(derived2); // Base::virtualPrint(), Base::nonVirtualPrint()

    std::cout << "\nWywołania bezpośrednie:" << std::endl;
    base.virtualPrint();    // Base::virtualPrint()
    base.nonVirtualPrint(); // Base::nonVirtualPrint()
    derived1.virtualPrint();    // Derived1::virtualPrint()
    derived1.nonVirtualPrint(); // Derived1::nonVirtualPrint()
    derived2.virtualPrint();    // Base::virtualPrint()
    derived2.nonVirtualPrint(); // Base::nonVirtualPrint()

    return 0;
}


// Wywołania przez referencję do Base:
// Base::virtualPrint()
// Base::nonVirtualPrint()
// Derived1::virtualPrint()
// Base::nonVirtualPrint()
// Base::virtualPrint()
// Base::nonVirtualPrint()

// Wywołania bezpośrednie:
// Base::virtualPrint()
// Base::nonVirtualPrint()
// Derived1::virtualPrint()
// Derived1::nonVirtualPrint()
// Base::virtualPrint()
// Base::nonVirtualPrint()

// Wyjaśnienie wyniku:

// Metoda wirtualna (virtualPrint):
// W callPrint: Późne wiązanie. Dla derived1 wywołuje Derived1::virtualPrint() (nadpisywanie), dla derived2 wywołuje Base::virtualPrint() (dziedziczenie).
// Bezpośrednio: Wybór metody zależy od typu obiektu, ale wciąż używa vtable dla metod wirtualnych.
// Metoda niewirtualna (nonVirtualPrint):
// W callPrint: Wczesne wiązanie. Zawsze wywołuje Base::nonVirtualPrint(), bo referencja jest typu Base.
// Bezpośrednio: Wywołuje metodę zgodną z typem obiektu (Derived1::nonVirtualPrint() dla derived1, Base::nonVirtualPrint() dla derived2).