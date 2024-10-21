#ifndef File_h
#define File_h

#include "FSElement.h"

#include <string>


//klasa reprezentujaca plik
class File: public FSElement{
public:
    //konstruktor, wywoluje FSElement(name)
    File(const std::string& name);

    //nadpisanie metody do wypisywania
    void print(size_t spaces=0, std::ostream& os=std::cout) const override;
private:
};

#endif