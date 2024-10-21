#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPC: public GameObject{
public:
    // konstruktor domyslny
    NPC() = default;
    // metoda interakcji
    void interact() const override;
    // metoda wypisu zlozonosci
    void printComplexity() const override;
    // metoda zwracajaca wartosc zlozonosci 
    int complexity() const override {return _cmplx;}

private:
    std::string _complexity = "LOW";
    int _cmplx = LOWEST;
};

#endif // NPC_H