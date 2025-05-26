#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {10, 20, 30};

    vec.push_back(40);        // dodaj na koniec
    vec.pop_back();           // usuń ostatni element

    vec[0] = 100;             // bezpieczne (ale nie sprawdza zakresu)
    std::cout << vec.at(1);  // bezpieczne (sprawdza zakres)

    // Iteracja
    for (auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << ' ';

    // Rozmiar i pojemność
    std::cout << "\nsize: " << vec.size() << " capacity: " << vec.capacity() << '\n';
    vec[100] = 100;
    // vec.at(6) = 100;
}