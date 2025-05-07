#include <iostream>
#include <typeinfo>

struct Animal {
    virtual ~Animal() = default;  // Wymagane dla RTTI
};

struct Dog : Animal {
    void bark() { std::cout << "Woof!\n"; }
};

struct Cat : Animal {
    void meow() { std::cout << "Meow!\n"; }
};

void makeSound(Animal* animal) {
    if (Dog* dog = dynamic_cast<Dog*>(animal)) {
        dog->bark();
    }
    else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
        cat->meow();
    }
    else {
        std::cout << "Unknown animal type: " << typeid(*animal).name() << "\n";
    }
}

// Przykład użycia:
int main() {
    Dog dog;
    Cat cat;
    Animal* animals[] = { &dog, &cat };

    for (Animal* animal : animals) {
        makeSound(animal);
    }

    return 0;
}
