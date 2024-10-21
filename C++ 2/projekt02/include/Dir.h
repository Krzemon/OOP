#ifndef Dir_h
#define Dir_h

#include "FS.h"

// klasa reprezentujaca folder
class Dir final : public FS, public FSElement
{
public:
    // konstruktor, wywoluje FSElement(name)
    Dir(const std::string &name);

    // nadpisanie metody do wypisywania
    void print(size_t spaces = 0, std::ostream &os = std::cout) const override;

    Dir *findDir(const std::string &name);

    // wypisywanie folderow do danej glebokosci
    void listDirs(int depth, std::ostream &os = std::cout);

private:
};

#endif