#ifndef CAR_H
#define CAR_H
#include <utility>
#include <iostream>

class Car {
public:
    Car() = default;
    Car(const char* brand, int year, int mileage);  // konstruktor
    Car(const Car& other);                          // Konstruktor kopiujący
    Car(Car&& other);                               // Konstruktor przenoszący
    Car& operator=(const Car& other);               // Operator przypisania kopiującego
    Car& operator=(Car&& other);                    // Operator przypisania przenoszącego
    ~Car();                                         // Destruktor

    void displayInfo() const;                       // Metoda wyswietlajaca informacje o samochodzie

private:
    char* brand;                                     // Marka samochodu
    int* year;                                       // Wskaznik na rok produkcji
    int mileage;                                     // Przebieg wskaźnika
};

#endif // CAR_H
