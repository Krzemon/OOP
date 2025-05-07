#include <iostream>

int main() {
// napisz prostry kod z __PRETTY_FUNCTION__ i "\n"
//     std::cout << __PRETTY_FUNCTION__ << "\n";



// // napisz trudny kod z __PRETTY_FUNCTION__ i "\n" z jakaś klasą
//     class Example {
//     public:
//         void display() const {
//             std::cout << __PRETTY_FUNCTION__ << "\n";
//         }
//     };

//     Example ex;
//     ex.display();
//     return 0;


// napisz najrudniejszy na ŚWIECIE  kod z __PRETTY_FUNCTION__ i "\n" z jakaś klasą
    // This is a complex example with multiple inheritance and virtual functions
    class Base {
    public:
        virtual void show() const {
            std::cout << __PRETTY_FUNCTION__ << "\n";
        }
    };

    class Derived1 : public Base {
    public:
        void show() const override {
            std::cout << __PRETTY_FUNCTION__ << "\n";
        }
    };

    class Derived2 : public Derived1 {
    public:
        void show() const override {
            std::cout << __PRETTY_FUNCTION__ << "\n";
        }
    };

    Derived2 d2;
    d2.show();

    return 0;

}