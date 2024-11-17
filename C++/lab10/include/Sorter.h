#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <algorithm>
#include <initializer_list>

template <typename T>
class Sorter {
private:
    T* data;
    int capacity;
    int size;

public:
    Sorter(int capacity);
    Sorter(const Sorter<T>& other);
    Sorter(Sorter<T>&& other) noexcept; 
    ~Sorter();

    void add(std::initializer_list<T> list);
    void sort();
    void print() const;
};

template <typename T>
Sorter<T>::Sorter(int capacity) : capacity(capacity), size(0) {
    data = new T[capacity];
    std::cout << "Default constructor\n";
}

template <typename T>
Sorter<T>::Sorter(const Sorter<T>& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    std::cout << "Copy constructor\n";
}

template <typename T>
Sorter<T>::Sorter(Sorter<T>&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
    std::cout << "Move constructor\n";
}

template <typename T>
Sorter<T>::~Sorter() {
    delete[] data;
}

template <typename T>
void Sorter<T>::add(std::initializer_list<T> list) {
    for (auto& elem : list) {
        if (size < capacity) {
            data[size++] = elem;
        }
    }
}

template <typename T>
void Sorter<T>::sort() {
    std::sort(data, data + size);
}

template <typename T>
void Sorter<T>::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << "  ";
    }
    std::cout << std::endl;
}

#endif
