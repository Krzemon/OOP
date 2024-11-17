#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
private:
    std::string my_name;
public:
    Animal(){std::cout << "Animal constructor" << this->name() << std::endl;}
    virtual ~Animal(){std::cout<<"Animal destructor"<<std::endl;}
    /**
     * czy jest ssakiem?
     */
    virtual bool isMammal() const = 0;
    /**
     * zwraca wartosc pola name
     */
    std::string name() const {return my_name;}
    /**
     * ustawia wartosc pola name
     */
    void setName(const std::string& name){ this->my_name = name;}
    /**
     * nazwa klasy
     */
    virtual const std::string me() const = 0;
};


#endif // ANIMAL_H