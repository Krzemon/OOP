#include "grafika.h"
#include <iostream>

namespace Grafika {

  void rysujPlansze(Statki::Plansza & plansza) {
    bool grid[SIZE][SIZE] = {{false}};

    Statki::Statek **tab;
    for(int i = 1; i < Statki::liczbaTypowStatkow; ++i) {
      switch(i){
        case Statki::JEDNOMASZTOWIEC: tab = plansza.jeden; break;
        case Statki::DWUMASZTOWIEC: tab = plansza.dwa; break;
        case Statki::TROJMASZTOWIEC: tab = plansza.trzy; break;
        case Statki::CZTEROMASZTOWIEC: tab = plansza.cztery; break;
        default: break;
      }
      for(int j = 0; j < i; ++j) {
        Statki::Statek *st = tab[j];
        if(st) {
          for(int k = 0; k < st->n; ++k)
            grid[st->koordynaty[k].x][st->koordynaty[k].y] = true;
        }
      }
    }

    for(int i = 0; i < SIZE; ++i) {
      for(int j = 0; j < SIZE; ++j)
        std::cout << (grid[i][j] ? " X " : " . ");
      std::cout << std::endl;
    }
  }

}
