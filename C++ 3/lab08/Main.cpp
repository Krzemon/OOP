/*
Rozszerz zadany wcześniej system klas opisujących strukturę systemu plików w postaci drzewiastej. 
Pierwotne rozwiązanie miało umożliwiać tworzenie i reprezentację takich elementów jak katalogi, pliki, z zachowaniem zasad zarządzania pamięcią
i umożliwieniem wypisywania struktury w postaci drzewa (jak na przykładzie poniżej).

Rozszerzenie może polegać na tym, by dodać możliwość rozpoznawania typu elementu systemu plików (np. czy jest to plik, katalog czy link)
i wykonywania operacji specyficznych dla danego typu, na przykład zmiany uprawnień, wypisania szczególnych informacji o pliku (np. rozmiar, data modyfikacji),
albo wykonywania operacji na katalogu (np. zamknięcie katalogu, operacje na zawartości).

Podstawowe rozwiazanie powinno zawierać
1) Dir::printElementsInfo(), która iteruje po elementach katalogu i wykonuje odpowiednią akcję w zależności od typu elementu.
Ma ona wykorzystywać dynamic_cast do identyfikacji typu obiektów. Dla nieobsługiwanego typu wystarczy jak zostanie wydrukowany odpowiedni komunikat.
Metoda z interfejsu klasy abstrakcyjnej, zdefiniowana dla każdego obsługiwanego typu może nazywać się printInfo()

2) Dir::ls() która iterując się po elementach katalogu wypisuje nazwe zasobu oraz jego typ, który rozpoznawany jest poprzez wykorzystanie typeid

*/

#include "Dir.h"
#include "File.h"
#include "Link.h"
#include <iostream>
#include <memory>

int main() {
    using namespace std;

    // Tworzymy główny katalog: data/
    auto root = make_unique<Dir>("data");

    // Dodajemy pliki do katalogu data/
    root->add(make_unique<File>("notes.txt"));
    root->add(make_unique<File>("readme.md"));

    // Tworzymy podkatalog img/
    auto img = make_unique<Dir>("img");
    img->add(make_unique<File>("logo.png"));
    img->add(make_unique<File>("screenshot.jpg"));

    // Tworzymy podkatalog docs/
    auto docs = make_unique<Dir>("docs");
    auto manual = make_unique<File>("manual.pdf");

    // Dodajemy plik manual.pdf do docs/
    // i zachowujemy wskaźnik do pliku dla linka
    File* manualPtr = manual.get();
    docs->add(std::move(manual));

    // Dodajemy podkatalogi do katalogu głównego
    root->add(std::move(img));
    root->add(std::move(docs));

    // Dodajemy link do manual.pdf w katalogu głównym
    root->add(make_unique<Link>("manual_link", manualPtr));

    // Wypisujemy całą strukturę katalogów i plików
    std::cout << *root;

    // Procesowanie elementów katalogu przy użyciu dynamic_cast
    cout << "\n--- PrintingElements ---" << endl;
    root->printElementsInfo(); // Wywołanie metody do dynamic_cast
    root->ls();                // Wywołanie metody do typeid

    return 0;
}
