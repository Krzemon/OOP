#ifndef DIR_H
#define DIR_H

#include "FSElement.h"
#include <vector>

class Dir : public FSElement {
public:
    Dir(const std::string& name) : FSElement(name) {}
    ~Dir();

    void add(FSElement* elem);
    Dir* findDir(const std::string& name);
    std::vector<FSElement*> getDirs() const;
    std::vector<FSElement*> getFSElements(Type type, int depth) override;
    void listDirs(int depth) const;
    void print(std::ostream& os, int depth) const override;

    Dir& operator+=(FSElement* elem) {
        add(elem);
        return *this;
    }

private:
    std::vector<FSElement*> elements;
    void listDirsRecursive(const Dir* dir, int depth, int currentDepth) const;
};

#endif // DIR_H
