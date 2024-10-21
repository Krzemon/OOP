#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy: public GameObject{
public:
    // konstruktor domyslny
    Enemy() = default;
    // metoda interakcji
    virtual void interact() const override;
    // metoda wypisu zlozonosci
    virtual void printComplexity() const override;
    // metoda zwracajaca wartosc zlozonosci 
    int complexity() const override {return _cmplx;}

private:
    std::string _complexity = "MEDIUM";
    int _cmplx = MID;
};

#endif // ENEMY_H