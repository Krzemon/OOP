#include "Whales.h"

Whales::Whales(const std::string& name){
    setName(name);
    std::cout << "Whales constructor: " << this->name() << std::endl;
}

Whales::~Whales()  {
    std::cout<<"Whales destructor: "<< this->name() <<std::endl;
}

bool Whales::isMammal() const  {
    return true;
}

std::string const Whales::me() const  {
    return "Whales";
}