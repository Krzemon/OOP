// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Celem zadania jest implementacja klasy Car która z konieczności musi spełniać regułę 
// Rule of Five - czyli klasa zarządza dynamicznymi zasobami. W tym przypadku
// jest to po prostu atrybut mileage przechowywany jako zmienna wskaźnikowa.
// Kolejne atrybuty klasy zostały opisane w ramach funkcji main()
// 
// UWAGA: Wywoływanie danego typu konstruktora lub operatora można testować implementując
// je jako "głośne".
//
// Przy wykonaniu zadania nie wolno korzystać z internetu notatek, 
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz CMakeLists.txt, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "Car.h"

int main() {
  // Utwórz obiekt klasy Car
  const char* brand = "Toyota";
  int year = 2022;
  int mileage = 15000;
  Car toyota(brand, year, mileage); // UWAGA: paramter year jest przechowywany
                                    // jako zmienna wskaźnikowa, czyli wymaga dynamicznej alokacji pamięci.
                                    // Należy to wykonać wykorzystując operator new (pracujemy bez sprytnych wskaźników!)
                                    // W innym przypadku => zadanie nie na temat => 0 punktów.
  toyota.displayInfo();

  // Utwórz kopię obiektu, wywołanie konstruktora kopiujacego
  Car toyotaCpy = toyota;
  toyota.displayInfo();
  toyotaCpy.displayInfo();

  // Utwórz obiekt przenoszący, wywołanie konstruktora przenoszącego
  Car toyotaMv = std::move(toyota);
  toyota.displayInfo();
  toyotaMv.displayInfo();

  // Utwórz kolejny obiekt klasy Car
  Car honda("Honda", 2021, 20000);
  honda.displayInfo();

  // Przypisz inny obiekt, wywołanie operatora przypisania przenoszącego
  toyotaMv = std::move(honda);
  honda.displayInfo();
  toyotaMv.displayInfo();

  return 0;
}

/* wynik dzialania
Brand: Toyota, Year: 2022, Mileage: 15000 km
Brand: Toyota, Year: 2022, Mileage: 15000 km
Brand: Toyota, Year: 2022, Mileage: 15000 km
Brand: -None-, Year: -None-, Mileage: -None-
Brand: Toyota, Year: 2022, Mileage: 15000 km
Brand: Honda, Year: 2021, Mileage: 20000 km
Brand: -None-, Year: -None-, Mileage: -None-
Brand: Honda, Year: 2021, Mileage: 20000 km
*/
