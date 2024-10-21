#ifndef OBSZAR_H
#define OBSZAR_H

#include <iostream>

class Zwierze;  // Forward declaration

class Obszar {
public:
  virtual void wyswietlInformacje() const = 0;
};

class Kontynent : public Obszar {
public:
  void wyswietlInformacje() const override;
};

class Kraj : public Obszar {
public:
  void wyswietlInformacje() const override;
};

#endif // OBSZAR_H