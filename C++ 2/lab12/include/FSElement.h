#ifndef FSELEMENT_H
#define FSELEMENT_H

#include <iostream>
#include <string>
#include <vector>

enum class Type { Dir, File };

class FSElement {
public:
    // wirtualny konstruktor
    FSElement(const std::string& name) : _name(name), _parent(nullptr) {}
    // wirtualny destruktor
    virtual ~FSElement() {}

    // metoda zwracajaca nazwe danych
    const std::string& name() const { return _name; }
    // wirtualna metoda wypisujaca wzgledna sciezke do katalogu
    virtual std::string getRelativePath() const = 0;
    // wirtualna metoda zwracajaca elementy wektora przechowujacego elementy klasy bazowej
    virtual std::vector<FSElement*> getFSElements(Type type, int depth) = 0;
    // wirtualna metoda wypisujaca nazwe i typ danych
    virtual void print(std::ostream& os, int depth) const = 0;

    void setParent(FSElement* parent) { _parent = parent; }
    FSElement* getParent() const { return _parent; }
    
protected:
    std::string _name;
    FSElement* _parent;
};
// przeciazony operator <<
inline std::ostream& operator<<(std::ostream& os, const FSElement& elem) {
    elem.print(os, 0);
    return os;
}

#endif // FSELEMENT_H
