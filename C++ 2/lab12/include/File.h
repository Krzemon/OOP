#ifndef FILE_H
#define FILE_H

#include "FSElement.h"

class File : public FSElement {
public:
    // konstruktor 
    File(const std::string& name) : FSElement(name) {}
    // metoda zwracajaca elementy wektora przechowujacego elementy klasy bazowej
    std::vector<FSElement*> getFSElements(Type type, int depth) override { return {}; }
    // metoda wypisujaca nazwe i typ danych
    void print(std::ostream& os, int depth) const override { 
        os << std::string(depth, ' ') << name() << " (FILE)" << std::endl; 
    }
    // metoda wypisujaca wzgledna sciezke do katalogu
    std::string getRelativePath() const override {
        if (!_parent) return name();
        return _parent->getRelativePath() + name();
    }
};

#endif // FILE_H
