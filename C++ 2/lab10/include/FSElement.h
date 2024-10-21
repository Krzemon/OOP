#ifndef FSELEMENT_H
#define FSELEMENT_H

#include <iostream>
#include <string>
#include <vector>

enum class Type { Dir, File };

class FSElement {
public:
    FSElement(const std::string& name) : name(name) {}
    virtual ~FSElement() {}

    const std::string& getName() const { return name; }

    virtual std::vector<FSElement*> getFSElements(Type type, int depth) = 0;
    virtual void print(std::ostream& os, int depth) const = 0;

protected:
    std::string name;
};

inline std::ostream& operator<<(std::ostream& os, const FSElement& elem) {
    elem.print(os, 0);
    return os;
}

#endif // FSELEMENT_H
