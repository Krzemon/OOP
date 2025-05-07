// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest implementacja hierachii klas z uwzględnieniem 
// semantyki przenoszenia oraz interfejsem opartym o metody wirtualne.
// - Kontynuacja tematyki z poprzedniego tygodnia,
// - Klasa bazowa Department z założenia ma być abstrakcyjna,
// - Należy zapewnić brak możliwości dziedziczenia po klasie ScienceDepartment
// - Ważne by pamiętać o standardach OOP, zasadzie D.R.Y, itp.

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab07/
// * archiwum nie powinno zawierać katalogu build/

#include "University.h"
#include "Department.h"
#include "ScienceDepartment.h"
#include <memory>

int main() {
    std::cout << "--- Original ---\n";
    auto depart_a = std::make_unique<ScienceDepartment>("A");
    depart_a->add_divisions({"Physics", "Chemistry"});
    University uni1;
    uni1.info();
    uni1.add(std::move(depart_a));
    uni1.add(std::make_unique<ScienceDepartment>("B"));
    uni1.info();
    
    std::cout << "\n--- Move semantics---\n";
    std::unique_ptr<Department> e_depart = uni1.pop_back_department(); // wyjęcie ostatniego elementu
    e_depart->info();
    uni1 = std::move(uni1);
    University uni2;
    uni2 = std::move(uni1);

    std::cout << "\n--- Info ---\n";
    uni1.info();
    uni2.info();

    return 0;
}

/* wynik działania programu:
--- Original ---
[INFO]:: University created.
[INFO]:: No departments assigned.
[INFO]:: University departments:
        [0] [Science]: 'A' [divisions]: Physics Chemistry
        [1] [Science]: 'B' [divisions]: None

--- Move semantics---
[Science]: 'B' [divisions]: None
[INFO]:: University move assignment.
[INFO]:: University created.
[INFO]:: University move assignment.

--- Info ---
[INFO]:: No departments assigned.
[INFO]:: University departments:
        [0] [Science]: 'A' [divisions]: Physics Chemistry
[INFO]:: University destroyed.
[INFO]:: University destroyed.


*/