#include "Link.h"
#include <iostream>

Link::Link(const std::string& name, FileSystemElement* target): File(name), target(target) {}

void Link::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "[LINK]: " << getName();
    if (target)
        os << " -> " << target->getName();
    else
        os << " -> (null)";
    os << "\n";
}

const std::string& Link::getName() const { return File::getName(); }