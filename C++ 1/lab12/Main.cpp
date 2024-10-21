// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o implementację kilku klas zwiazanych relacja
// dziedziczenia.  Klasy te opisuja elementarne ksztalty. Kazdy ksztalt
// posiada jakies polimorficzne metody i konieczna infrastrukture.
 
//  UWAGA: Przed rozpoczęciem pisania proszę przeczytać zadanie do końca.
//  UWAGA: W tym zadaniu: PI to 3.1415.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab12/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Kwadrat.h"
#include "Kolo.h"

int main() {
  Kwadrat k(4);
  const Kolo ko(3);

  wypisz(k); // ma wypisac: Kwadrat o boku: 4
  wypisz(ko);// ma wypisac: Kolo o promieniu: 3
  
  Ksztalt* b = new Kolo(7);
  wypisz(*b);
  delete b;
  
  const Ksztalt* wszystkie[] = {&k, &k, &ko, &ko}; // obiekty powtorzone celowo
  for ( int idx = 0; idx < sizeof(wszystkie)/sizeof(Ksztalt*); ++idx ) {
    const Ksztalt* k = wszystkie[idx];
    wypisz(*k); 
    std::cout << "  Pole powierzchni: " << k->polePow() << std::endl;
  }  
}
/* wynik dzialania programu:
Kwadrat o boku: 4
Kolo o promieniu: 3
Kolo o promieniu: 7
Kwadrat o boku: 4
  Pole powierzchni: 16
Kwadrat o boku: 4
  Pole powierzchni: 16
Kolo o promieniu: 3
  Pole powierzchni: 28.2735
Kolo o promieniu: 3
  Pole powierzchni: 28.2735
*/
