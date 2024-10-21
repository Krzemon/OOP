// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o implementację kilku klas ziwaznych relacja
// dziedziczenia.  Klasy te opisuja elementarne ksztalty. Kazdy ksztalk
// posiada jakies polimorficzne metody i konieczna infrastrukture.
 
//  UWAGA: Przed rozpoczęciem pisania proszę przeczytać zadanie do końca.
//  UWAGA: W tym zadaniu: PI to 3.1415. Wzór na pole trójkąta: sqrt( x(x-a)(x-b)(x-c) ) 
//  gdzie "x" to polowa obwodu trójkata.

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
#include "Kolo.h"
#include "Trojkat.h"

int main() {
  Trojkat t(3,2,4);
  const Kolo ko(3);

  wypisz(t); // ma sypisac: Trojkat o bokach: 3 2 4
  wypisz(ko);// ma wypisac: Kolo o promieniu: 3
  
  Ksztalt* b = new Kolo(7);
  wypisz(*b);
  delete b;
  
  const Ksztalt* wszystkie[] = {&ko, &t, &ko}; // obiekty powtorzone celowo
  for ( int idx = 0; idx < sizeof(wszystkie)/sizeof(Ksztalt*); ++idx ) {
    const Ksztalt* k = wszystkie[idx];
    k->wypisz(std::cout); 
    std::cout << "  Pole powierzchni: " << k->polePow() << std::endl;
  }  
}
/* wynik dzialania programu:
Trojkat bokach: 3 2 4
Kolo o promieniu: 3
Kolo o promieniu: 7
Kolo o promieniu: 3
  Pole powierzchni: 28.2735
Trojkat bokach: 3 2 4
  Pole powierzchni: 2.90474
Kolo o promieniu: 3
  Pole powierzchni: 28.2735
*/
