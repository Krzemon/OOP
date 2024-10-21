// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Prosze zaimplementowac klasy CplxNumber i CplxVector. 
// CplxNumber jest to para liczb, wypisywana w nawiasie
// okraglym. CplxVector natomiast jest to uporządkowany zbior trzech
// CplxNumber. Klasy te obłsugują odpowiednie kowersje między typami.
// Uwaga: rozwiązanie nie może zawierać static_cast<>
// Szczegółowe informacje podane są w funkcji main.
//
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Przy wykonaniu zadania nie wolno korzystać z internetu z wyjątkiem linków podanych wyżej,
// notatek, ani żadnych innych materialow (w tym własnych wczesniej
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

#include"CplxVector.h"
#include <iostream>

int main ()
{
  CplxNumber liczba (1.2, 0.0); // CplxNumber definiuje dwie składowe: Re oraz Im
  liczba.Print();

  // Mamy możliwość konwersji CplxNumber na std::string, 
  // w definicji tej konwersji należy wykorzystać metodę std::to_string(x)
  std::string liczba_str = liczba; // konwersja niejawna
  std::cout << liczba_str << "\n";
  
  CplxVector pierwszy;
  pierwszy.SetY(1.1, 2.1).SetZ(1.3, 2.3);
  pierwszy.Print();
  // zmiana pierwszej wspolrzednej
  pierwszy.SetX(liczba);
  pierwszy.Print();

  double modul_1 = CplxNumber::Abs(pierwszy.X());
  std::cout << "Moduł 1: "<< modul_1 << "\n";

  // Mamy możliwość kowersji liczby zespolonej na double, gdzie zwracany jest moduł liczby zesp.
  // Konwersja ta musi ona być jawna dlatego, poniższa linia po odkowmenotwaniu powinna zwarać błąd:
  // double modul_err = pierwszy.X(); // error: cannot convert ‘CplxNumber’ to ‘double’ in initialization
  double modul_2 = static_cast<double>(pierwszy.X()); // tak już jest OK
  std::cout << "Moduł 2: "<< modul_2 << "\n";

  CplxVector drugi = 1.; // A tutaj konwersja niejawna
  drugi.Print();

}
/* wynik dzialania programu:
(1.2, 0)
(1.200000,0.000000)
[(0.000000,0.000000), (1.100000,2.100000), (1.300000,2.300000)]
[(1.200000,0.000000), (1.100000,2.100000), (1.300000,2.300000)]
Moduł 1: 1.2
Moduł 2: 1.2
[(1.000000,1.000000), (1.000000,1.000000), (1.000000,1.000000)]
*/
