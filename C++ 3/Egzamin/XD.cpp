#include <iostream>

// Abstrakcyjna klasa bazowa
struct B {
    // To NIE jest dobry sposób przeciążania operatora <<
    // Bo działa w stylu: b << std::cout (co jest odwróceniem logiki)
    std::ostream& operator<<(std::ostream& os) const {
        return printOn(os);
    }

protected:
    virtual std::ostream& printOn(std::ostream& os) const = 0;
    virtual ~B() = default;
};

// Konkretna klasa dziedzicząca po B
struct D : public B {
protected:
    std::ostream& printOn(std::ostream& os) const override {
        return os << "Obiekt D" << std::endl;
    }
};

int main() {
    D d;

    // To działa, ale jest NIEintuicyjne:
    // bo musisz pisać d << std::cout zamiast std::cout << d
    d << std::cout;

    return 0;
}
