#include "statki.h"
#include "grafika.h"
#include <iostream>

int main() {
  Statki::Plansza mojaGra;

  Statki::Pozycja pozycja; 

  pozycja.x = 0; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 4; pozycja.y = 4;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 6; pozycja.y = 6;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);
  pozycja.x = 8; pozycja.y = 8;
  Statki::dodajStatek(mojaGra, pozycja, Statki::JEDNOMASZTOWIEC);

  pozycja.x = 8; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);
  pozycja.x = 5; pozycja.y = 0;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);
  pozycja.x = 0; pozycja.y = 8;
  Statki::dodajStatek(mojaGra, pozycja, Statki::DWUMASZTOWIEC);

  pozycja.x = 2; pozycja.y = 2;
  Statki::dodajStatek(mojaGra, pozycja, Statki::TROJMASZTOWIEC);
  pozycja.x = 7; pozycja.y = 2;
  Statki::dodajStatek(mojaGra, pozycja, Statki::TROJMASZTOWIEC);

  pozycja.x = 0; pozycja.y = 6;
  Statki::dodajStatek(mojaGra, pozycja, Statki::CZTEROMASZTOWIEC);

  Grafika::rysujPlansze(mojaGra);

  Statki::wyczyscPlansze(mojaGra);

  return 0;
}
