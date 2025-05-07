// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się, 
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zdefiniowanie struktury organizacji w firmie:
// Company -> Department -> Employee
// - Company przechowuje tablice Department
// - Department przechowuje tablice Employee
// - odpowiednie interfejsy proszę wywnioskować z treści funkcji main()
// - każda klasa powinna być zdefiniowana w osobnym pliku (.h, .cpp)
// UWAGA: Nie można korzystać z std::vector, std::array
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
// * archiwum powinno zawierać katalog z zadaniem, np. lab03/
// * archiwum nie powinno zawierać katalogu build/

#include "Employee.h"
#include "Department.h"
#include "Company.h"
#include <iostream>

int main() {
    // Dla ułatwienia, tworząc nową firmę z góry określamy liczbę działów
    // możliwych w firmie
    Company myCompany("TechCorp", 3);

    // Analogicznie, działy tworzymy określając maksymalną liczbę pracowników
    // możliwych do dodania w każdym z nich
    Department d1("IT",10);
    Department d2("HR",10);
    myCompany.addDepartment(d1);
    myCompany.addDepartment(d2);
    
    Employee e0("Nobody");
    
    // Albo, pracownicy są przypisani do działu w momencie ich tworzenia
    Employee e1("Alice", &d1);  // Alice jest przypisana do IT
    Employee e2("Bob", &d1);    // Bob jest przypisany do IT
    Employee e3("Charlie", &d2);  // Charlie jest przypisany do HR

    myCompany.printDepartments();

    const Department& constDept = d1;
    constDept[0].printInfo();         // Dostep do pracownika w IT
    d1[0] = Employee("Robert", &d1);  // zastąpienie Alice w IT
    constDept[0].printInfo();

// Flaga zdefiniowana na poziomie CMakeLists.txt
// w celu testowania błędu kompilacji:
// cmake -DENABLE_ERROR_TEST=ON ..
#ifdef ENABLE_ERROR_TEST 
    d2.addEmployee("Anna");
#endif

    return 0;
}

/* Wynik działania programu:
Company: TechCorp departments:
- IT
- HR
Employee: Alice (Department: IT)
Employee: Robert (Department: IT)
*/
