#ifndef FSElement_h
#define FSElement_h

#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>

enum class Type
{
    All,
    File,
    Dir
};

// klasa reprezentujaca ogolny obiekt
class FSElement
{
public:
    // kostruktor z nazwa
    FSElement(const std::string &name);

    // destruktor
    virtual ~FSElement() = default;

    // czysto wirtualna metoda do wypisywania
    virtual void print(size_t spaces = 0, std::ostream &os = std::cout) const = 0;

    // getter nazwy
    std::string getName() const;
protected:

    // nazwa
    std::string _name;
};

// operator<< do wypisywanie, wywoluje print()
std::ostream &operator<<(std::ostream &os, const FSElement &elem);

#endif