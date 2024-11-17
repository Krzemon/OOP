#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include "Birds.h"
#include "Whales.h"

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdint>

class Zoo{
private:
    std::vector<Animal*> *animals;
    static int birdCount;
    static int whaleCount;
public:
    Zoo();
    ~Zoo();
    void print() const;
    void addAnimal(Animal* new_animal);

};

#endif // ZOO_H