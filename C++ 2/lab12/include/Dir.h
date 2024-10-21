#ifndef DIR_H
#define DIR_H

#include "FSElement.h"

class Dir : public FSElement {
public:
    // konstruktor
    Dir(const std::string& name) : FSElement(name) {}
    // destruktor
    ~Dir();

    // metoda dodajaca element do katalogu
    void add(FSElement* elem);
    // metoda znajdujaca katalog
    Dir* findDir(const std::string& name);
    // metoda zwracajaca katalogi
    std::vector<FSElement*> getDirs() const;
    // metoda zwracajaca elementy wektora przechowujacego elementy klasy bazowej
    std::vector<FSElement*> getFSElements(Type type, int depth) override;
    // metoda listujca katalogi
    void listDirs(int depth) const;
    // metoda wypisujaca nazwe elementu
    void print(std::ostream& os, int depth) const override;
    // metoda zwracajaca wzgledna sciezke
    std::string getRelativePath() const override;
    
    Dir& operator+=(FSElement* elem) {
        add(elem);
        return *this;
    }

private:
    std::vector<FSElement*> elements;
    // prywatna funkcja wypisu rekurencyjna
    void listDirsRecursive(const Dir* dir, int depth, int currentDepth) const;
};

#endif // DIR_H
