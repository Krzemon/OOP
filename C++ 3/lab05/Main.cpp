// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał się,
// a wynik jego dzialania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest rozszerzenie kodu źródłowego projektu z implementacją struktury
// organizacyjnej firmy, gdzie dane powinny być przechowywane w listach dwukierunkowych, 
// bez użycia kontenerów STL, takich jak `std::vector` czy `std::list`
// https://upel.agh.edu.pl/pluginfile.php/476860/mod_resource/content/4/Main.cpp
// Założenia do ogólnej struktury projektu
// - EmployeeNode powinien być zdefiniowany w tym samym pliku co klasa Employee
// - DepartmentNode powinien być zdefiniowany w tym samym pliku co klasa Department
// 
// Zadaniem w ramach Lab05 są tematy:
// - niejawna konwersja typów
// - różne opertory, operator przypisania kopiującego
// - niestandardowy konstruktor kopiujący 
// UWAGA: co potrzebne proszę wywnioskować z treści funkcji main

// Jeśli wystarczy czasu, proszę przeanalizować ostatnią cześć
// rozróżniającą T(){} od kontruktora trywialnego

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab05/
// * archiwum nie powinno zawierać katalogu build/

#include "Company.h"
#include "Department.h"
#include "Employee.h"
#include <type_traits>

class Faculty {};

class MedFaculty  {
public:
    MedFaculty(){} // Brak domyślnego konstruktora?
};

class ITFaculty  {
public:
    ITFaculty(int id) {} // Brak domyślnego konstruktora
};

int main() {
    // Tworzymy firmę
    Company myCompany("University");

    // Tworzymy i dodajemy działy do firmy
    myCompany.addDepartment("WFiIS");   // Uwaga: tutaj należy skorzystać z niejawnej konwersji
    myCompany.addDepartment("WIMiIP");
    myCompany.addDepartment("WIMiR");

    Department& wfis = myCompany["WFiIS"];
    const Department& wimir = myCompany["WIMiR"];

    // Dodajemy pracowników
    Employee e1("Alice", &wfis);
    Employee e2("Bob", &(myCompany["WIMiIP"]));

    // Wypisujemy działy firmy
    std::cout << myCompany << std::endl; // Uwaga: tutaj należy skorzystać z wcześniejszej metody printDepartments

    // Wypisujemy działy firmy bez pracowników
    myCompany.printEmptyDepartments(); 
    
    e1.printInfo();
    Employee e3 = wfis[0]; // UWAGA: założenie e3 NIE należy do WFiIS
    e3.printInfo();

    auto printMsgDefaultConstructible = [](const std::string& className, bool isDefaultConstr) {
        std::cout << "Is " << className << " default constructible? " 
                  << std::boolalpha << isDefaultConstr << std::endl;
    };

    printMsgDefaultConstructible("Faculty", std::is_trivially_default_constructible<Faculty>::value);
    printMsgDefaultConstructible("ITFaculty", std::is_trivially_default_constructible<ITFaculty>::value);
    printMsgDefaultConstructible("MedFaculty", std::is_trivially_default_constructible<MedFaculty>::value);
    printMsgDefaultConstructible("MedFaculty", std::is_default_constructible<MedFaculty>::value); // jaka jest różnica wzgledem is_trivially_default_constructible?

    return 0;
}

/* wynik działania:
Company: University departments: WFiIS, WIMiIP, WIMiR,
Company: University departments (empty): WIMiR,
Employee: Alice (Department: WFiIS)
Employee: Alice
Is Faculty default constructible? true
Is ITFaculty default constructible? false
Is MedFaculty default constructible? false
Is MedFaculty default constructible? true
*/
