/*
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest implementacja rozszerzenie funkcjonalności hierachii klas 
// z uwzględnieniem semantyki przenoszenia na bazie kodu z projektu nr 2:
// - jeśli dotychczas nie zaimplementowałeś klasy Link to należy to wykonać, ale 
//   z zachowaniem cherarchii: Link -> File -> BaseKlas | jakkolwiek klasa bazowa sie nazywa
// - Klasa Link ta reprezentuje zasób w systemie plików ze wskazywaniem na inny plik/katalog
// - Klasa Dir zyskuje nową funkcjonalność: Dir::rm, która w zależności od typu elementu
//   rozpoznawanego po przekazanej nazwie, usuwa ten element, a dla typu Link dodatkowo
//   istnieje opcja usuwania bądź nie wskazywanego elementu.

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab09/
// * archiwum nie powinno zawierać katalogu build/
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

    // Tworzymy podkatalog docs/
    auto docs = make_unique<Dir>("docs");
    auto manual = make_unique<File>("manual.pdf");

    // Dodajemy plik manual.pdf do docs/
    // i zachowujemy wskaźnik do pliku dla linka
    File* manualPtr = manual.get();
    docs->add(std::move(manual));

    // Dodajemy podkatalog do katalogu głównego
    root->add(std::move(docs));

    // Dodajemy link do manual.pdf w katalogu głównym
    root->add(make_unique<Link>("manual_link_1", manualPtr));
    root->add(make_unique<Link>("manual_link_2", manualPtr));

    // Wypisujemy całą strukturę katalogów i plików
    std::cout << *root;
    root->rm("manual_link_1");
    std::cout << *root;
    root->rm("manual_link_2", true); // removeTarget = true
    std::cout << *root;
    root->rm("docs");
    std::cout << *root;

    return 0;
}
/* Zakładany wynik programu:
Dir: data
  Dir: docs
    File: manual.pdf
  [LINK] manual_link_1 -> manual.pdf
  [LINK] manual_link_2 -> manual.pdf
Dir: data
  Dir: docs
    File: manual.pdf
  [LINK] manual_link_2 -> manual.pdf
Dir: data
  Dir: docs
Dir: data
*/
