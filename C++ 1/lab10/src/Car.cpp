#include "Car.h"
#include <iostream>
#include <cstring>


Car::Car(const char* brand, int year, int mileage) : mileage(mileage) {
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->year = new int(year);
}

Car::Car(const Car& other) : mileage(other.mileage) {
    brand = new char[strlen(other.brand) + 1];
    strcpy(brand, other.brand);
    year = new int(*other.year);
}


Car::Car(Car&& other) : brand(other.brand), year(other.year), mileage(other.mileage) {
    other.brand = nullptr;
    other.year = nullptr;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        delete[] brand;
        delete year;

        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
        year = other.year;
        year = new int(*other.year);
    }
    return *this;
}

Car& Car::operator=(Car&& other) {
    if (this != &other) {
        delete[] brand;
        delete year;

        brand = other.brand;
        year = other.year;
        mileage = other.mileage;


        other.brand = nullptr;
        other.year = nullptr;
    }
    return *this;
}

Car::~Car() {
    delete[] brand;
    delete year;
}

void Car::displayInfo() const {
    if (brand != nullptr) {
        std::cout << "Brand: " << brand << ", Year: " << *year << ", Mileage: " << mileage << " km\n";
    } else {
        std::cout << "Brand: -None-, Year: -None-, Mileage: -None-\n";
    }
}
