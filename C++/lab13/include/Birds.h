#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal {
public:
    Birds(const std::string& name = "");
    ~Birds() override;
    bool isMammal() const override;
    std::string const me() const override;
};

#endif // BIRDS_H