#include "statki.h"
#include <iostream>

namespace Statki {

  bool dodajStatek(Plansza & plansza, Pozycja pozycja, TypStatku typ){
    Statek **tab;
    switch(typ){
      case JEDNOMASZTOWIEC: tab = plansza.jeden; break;
      case DWUMASZTOWIEC: tab = plansza.dwa; break;
      case TROJMASZTOWIEC: tab = plansza.trzy; break;
      case CZTEROMASZTOWIEC: tab = plansza.cztery; break;
      default: return false;
    }

    // Znajdujemy wolne miejsce dla nowego statku
    int j = typ - 1;
    while(j >= 0){
      if(tab[j]) 
        --j;
      else 
        break;
    }
    if(j < 0) 
      return false; // Brak miejsca

    int shipSize = liczbaTypowStatkow - typ;
    Statek *statek = new Statek;
    statek->n = shipSize;
    statek->koordynaty = new Pozycja[shipSize];

    for(int i = 0; i < shipSize; ++i){
      statek->koordynaty[i].x = pozycja.x + i;
      statek->koordynaty[i].y = pozycja.y;
    }
    tab[j] = statek;
    return true;
  }

  void wyczyscPlansze(Plansza &plansza){
    Statek **tab;
    for(int i = 1; i < liczbaTypowStatkow; ++i){
      switch(i){
        case JEDNOMASZTOWIEC: tab = plansza.jeden; break;
        case DWUMASZTOWIEC: tab = plansza.dwa; break;
        case TROJMASZTOWIEC: tab = plansza.trzy; break;
        case CZTEROMASZTOWIEC: tab = plansza.cztery; break;
        default: break;
      }

      for(int j = 0; j < i; ++j){
        Statek *st = tab[j];
        if(st){
          if(st->koordynaty)
            delete[] st->koordynaty;
          delete st;
        }
      }
    }
  }

}
