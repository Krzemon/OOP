#ifndef GameObject_H
#define GameObject_H

#include <cstring>
#include <iostream>

class GameObject{
public:
    // wirtualna metoda interakcji
    virtual void interact() const = 0;
    // wirtualna metoda wypisu zlozonosci
    virtual void printComplexity() const = 0;
    // wirtualna metoda zwracajaca wartosc zlozonosci 
    virtual int complexity() const = 0;
    // enumeracja zlozonosci
    enum Cplx {LOWEST, MID, HIGHEST};
};

class CompareCplx{
public:
    // przeciazany operator nawiasowy
    bool operator()(const GameObject* GameObject_1,const GameObject* GameObject_2) const {
        bool yup = false;
        if(GameObject_1->complexity() > GameObject_2->complexity()){
            yup = true;
        }
        return yup;
    }
};

#endif // GameObject_H