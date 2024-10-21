#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player: public GameObject{
public:
    // konstruktor domyslny
    Player() = default;
    // metoda interakcji
    virtual void interact() const override;
    // metoda wypisu zlozonosci
    virtual void printComplexity() const override;
    // metoda zwracajaca wartosc zlozonosci 
    int complexity() const override {return _cmplx;}

private:
    std::string _complexity = "HIGHEST";
    int _cmplx = HIGHEST;
};

#endif // PLAYER_H