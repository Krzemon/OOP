// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest implementacja hierachii klas z uwzględnieniem 
// semantyki przenoszenia oraz interfejsem opartym o metody wirtualne.
// Hierarchia klas:
// Department – klasa bazowa
// ScienceDepartment – konkretna implementacja Department, nadpisuje odpowiednie metody
// University – zawiera kolekcję std::unique_ptr<Department>, obsługuje:
// dodawanie działów (add()), wyświetlanie info oraz przenoszenie działów.

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab06/
// * archiwum nie powinno zawierać katalogu build/

#include "University.h"
#include "Department.h"
#include "ScienceDepartment.h"
#include <memory>

int main() {
    std::cout << "--- Original ---\n";
    University uni1;
    uni1.info();
    uni1.add(std::make_unique<ScienceDepartment>());
    uni1.info();

    std::cout << "\n--- Move ---\n";
    University uni2;
    uni2 = std::move(uni1);

    std::cout << "\n--- Info ---\n";
    uni1.info();
    uni2.info();

    return 0;
}

/* wynik działania programu:
--- Original ---
University created.
No departments assigned.
Department Science created.
ScienceDepartment created.
Department added to University.
Science Department (Physics, Chemistry, Biology)

--- Move ---
University created.
University move assignment.

--- Info ---
No departments assigned.
Science Department (Physics, Chemistry, Biology)
University destroyed.
ScienceDepartment destroyed.
Department Science destroyed.
University destroyed.
*/