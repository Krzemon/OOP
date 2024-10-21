#include "Zwierze.h"

Ptak::Ptak(Kraj* kraj) : _kraj(kraj) {}

void Ptak::wyswietlInformacje() const {
  if (_kraj != nullptr) {
    _kraj->wyswietlInformacje();
  } else {
    std::cout << "Nieokreślony obszar";
  }
}

void Ptak::wydajDzwiek() const {
  std::cout << "Ptak wydaje dźwięk!" << std::endl;
}

void Ssak::wyswietlInformacje() const {
}

void Ssak::wydajDzwiek() const {
  std::cout << "Ssak wydaje dźwięk!" << std::endl;
}