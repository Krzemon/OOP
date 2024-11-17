#include "Birds.h"

Birds::Birds(const std::string& name){
    setName(name);
    std::cout << "Birds constructor: " << this->name() << std::endl;
}

Birds::~Birds()  {
    std::cout<<"Birds destructor: "<< this->name() <<std::endl;
}

bool Birds::isMammal() const {
    return false;
}

std::string const Birds::me() const {
    return "Birds";
}