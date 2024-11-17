#ifndef STATKI_H
#define STATKI_H

#define SIZE 10

namespace Statki {

  // Typy statków
  enum TypStatku {  
    CZTEROMASZTOWIEC = 1,
    TROJMASZTOWIEC = 2,
    DWUMASZTOWIEC = 3,
    JEDNOMASZTOWIEC = 4,
    liczbaTypowStatkow
  };

  // Struktura pozycji na planszy
  struct Pozycja{
    int x = 0;
    int y = 0;
  };

  // Struktura statku
  struct Statek{
    int n;
    Pozycja *koordynaty = nullptr;
  };

  // Struktura planszy, która zawiera statki
  struct Plansza{
    Statek *jeden[JEDNOMASZTOWIEC] = {nullptr};
    Statek *dwa[DWUMASZTOWIEC] = {nullptr};
    Statek *trzy[TROJMASZTOWIEC] = {nullptr};
    Statek *cztery[CZTEROMASZTOWIEC] = {nullptr};
  };

  // Funkcja dodająca statek na planszę
  bool dodajStatek(Plansza &plansza, Pozycja pozycja, TypStatku typ);

  // Funkcja czyszcząca planszę
  void wyczyscPlansze(Plansza &plansza);
}

#endif // STATKI_H
