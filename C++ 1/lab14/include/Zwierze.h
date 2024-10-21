#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Obszar.h"

class Zwierze {
public:
  virtual void wydajDzwiek() const = 0;
  virtual void wyswietlInformacje() const = 0;
};

class Ptak : public Zwierze {
public:
  Ptak(Kraj* kraj);
  void wydajDzwiek() const override;
  void wyswietlInformacje() const override;
private:
  Kraj* _kraj;
};

class Ssak : public Zwierze {
public:
  void wydajDzwiek() const override;
  void wyswietlInformacje() const override;
};

#endif // ZWIERZE_H