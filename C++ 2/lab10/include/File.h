#ifndef FILE_H
#define FILE_H

#include "FSElement.h"

class File : public FSElement {
public:
    File(const std::string& name) : FSElement(name) {}
    std::vector<FSElement*> getFSElements(Type type, int depth) override { return {}; }
    void print(std::ostream& os, int depth) const override { os << std::string(depth, ' ') << getName() << " (FILE)" << std::endl; }
};

#endif // FILE_H
