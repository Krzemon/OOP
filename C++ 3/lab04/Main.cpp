// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się, 
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zdefiniowanie funktora StringProcessor
// który pozwoli dynamicznie dodawać do siebie algorytmy do operaowaniu na napisie
// - odpowiednie interfejsy prosę wywnioskować z treści funkcji main()
//
// Prosze zadbać o dobre zarzadzanie pamiecia.
// Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
// Struktura propramu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materiałów.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab04/
// * archiwum nie powinno zawierać katalogu build/


#include "StringProcessor.h"
#include <iostream>

int main() {
    std::string text = "Ala ma Kota i psa";

    StringProcessor processor;

    // Dodajemy algorytm, który zamienia wszystkie litery na wielkie
    processor.addVoidAlgorithm([](std::string& str) {
        for (char& c : str) {
            c = std::toupper(c);
        }
    });

    // Dodajemy algorytm, który liczy liczbę samogłosek
    processor.addIntAlgorithm([](const std::string& str) -> int {
        int count = 0;
        for (char c : str) {
            if (std::string("AEIOUaeiou").find(c) != std::string::npos) {
                count++;
            }
        }
        return count;
    });

    // Dodajemy algorytm, który odwraca napis
    processor.addVoidAlgorithm([](std::string& str) {
        std::reverse(str.begin(), str.end());
    });

    // Uruchamiamy przetwarzanie napisu za pomocą przeciążonego operatora ()
    processor(text);

    // // Resetujemy przetwarzanie
    processor.reset();

    // // Aktywowanie wbudowanego algorytmu (odwracanie napisu)
    processor.enableAlgorithm("reverse");
    processor(text);


    return 0;
}

/* Wynik działania:
Original string: Ala ma Kota i psa
Result from int algorithms: 7
Result from void algorithms: ASP I ATOK AM ALA
Processor reset. All algorithms removed.
Enabling built-in algorithm: reverse
Original string: ASP I ATOK AM ALA
Result from void algorithms: ALA MA KOTA I PSA
*/
