#ifndef WHALES_H
#define WHALES_H

#include "Animal.h"

class Whales : public Animal {
public:
    Whales(const std::string& name = "");
    ~Whales() override;
    bool isMammal() const override;
    std::string const me() const override;
};

#endif // WHALES_H